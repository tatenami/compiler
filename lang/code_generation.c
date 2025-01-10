#include "ast2.h"

struct SymbolInfo {
  Node  *target_node; // 対象のノード
  char  *var_name;    // 変数名
  int    number;      // 変数番号
  int    mem_size;    // 変数のメモリサイズ
  long   mem_offset;  // データセグメントからのメモリオフセット
  struct SymbolInfo *next; // リストの次の記号情報へのポインタ
};

/* Global variable */
FILE*  code_fp;
extern Node *top;
struct SymbolInfo *symbol_head;
const unsigned int  var_base_size = 4;
const unsigned long base_address = 0x10004000;

/* ---------- 記号表関連 ---------- */

long get_offset(char *var_name) {
  struct SymbolInfo *symbol = symbol_head->next;

  while (symbol != NULL) {
    if (strcmp(var_name, symbol->var_name) == 0) {
      return symbol->mem_offset;
    }
    symbol = symbol->next;
  }

  return -1;
}

/**
 * @brief 
 * 
 * @param s 
 * @param n 
 * @return struct SymbolInfo* 
 */
struct SymbolInfo *make_symbol(struct SymbolInfo *s, Node *n) {
  int size;
  switch (n->type) {
    case IDENTS_AST: {
      n = n->child; // IDENT
      size = var_base_size;
      break;
    }
    case ARRAY_AST: {
      n = n->child; // IDENT
      Node *index1 = n->brother->child; // index1
      int num1 = index1->ival;
      // ２次元配列時
      if (index1->brother != NULL) {
        int num2 = index1->brother->ival;
        size = (num1 + num2) * var_base_size;
      }
      else {
        size = num1 * var_base_size;
      }
      break; 
    }
  }

  struct SymbolInfo *ns = (struct SymbolInfo *)malloc(sizeof(struct SymbolInfo));

  ns->number = s->number + 1;
  ns->target_node = n;
  ns->mem_size   = size;
  ns->mem_offset = (ns->number == 0) ? 0 : (s->mem_offset + size);
  ns->var_name   = n->variable;
  ns->next = NULL;
  s->next = ns; // 生成したシンボルを末尾に追加

  return ns;
}

/**
 * @brief ノードツリーから再帰的に記号リスト情報を追加
 * 
 * @param s 末尾の記号リスト
 * @param n ツリーのノード
 * @return struct SymbolInfo* 
 */
struct SymbolInfo *add_symbol(struct SymbolInfo *s, Node *n) {
  if (n->type == DECL_PART_AST) {
    s = make_symbol(s, n->child);
  }

  if (n->child != NULL) {
    s = add_symbol(s, n->child);
  }
  if (n->brother != NULL) {
    s = add_symbol(s, n->brother);
  }

  return s;
} 

void make_symbol_list(struct SymbolInfo *s, Node *n) {
  add_symbol(s, n);
}

struct SymbolInfo *init_sysbol_list() {
  struct SymbolInfo *s_top = (struct SymbolInfo *)malloc(sizeof(struct SymbolInfo));
  s_top->number = -1;
  s_top->next = NULL;
  s_top->mem_offset = 0;

  return s_top;
}

void print_symbol(struct SymbolInfo *s, int num) {
  if (s->number >= 0) 
    printf("symbol_%d [%s] \tsize: %d offset: %#x\n", 
           s->number, s->var_name, s->mem_size, (int)s->mem_offset);

  if (s->next == NULL) return;
  print_symbol(s->next, num);
}

void print_symbol_list() {
  printf("---[ Symbols ]---\n");
  print_symbol(symbol_head->next, 0);
  printf("-----------------\n");
}

/* ---------- コード生成関連 ---------- */

void gen_code_assignment(Node *n) {
  Node *ident = n->child;
  Node *expression = ident->brother;
  int offset = get_offset(ident->variable);

  fprintf(code_fp, "# assignment %s\n", ident->variable);

  switch (expression->type) {
    case NUMBER_AST: {
      int num = expression->ival;
      fprintf(code_fp, "  li $v0, %d\n", num);
      fprintf(code_fp, "  addi $t6, $t0, %d\n", offset);
      break;
    }
    case ADD_AST: {

      break;
    }
  }

  fprintf(code_fp, "  sw $v0, 0($t6)\n");
  fprintf(code_fp, "  nop\n");
}

void gen_code_sentence(Node *n) {
  switch (n->type) {
    case ASSIGNMENT_AST: {
      gen_code_assignment(n);
      break;
    }
  }
}

/**
 * @brief ASTノードに対応したコードを記述する
 * 
 * @param n   ノードのポインタ
 * @param num ノード番号
 * @param fp  コードを記述するファイルのポインタ
 * @return int 
 */
void gen_code(Node *n) {
  // printf("\ngen_code -> ");
  // print_node(n, num);
  gen_code_sentence(n);

  if (n->child != NULL) {
    gen_code(n->child);
  }
  if (n->brother != NULL) {
    gen_code(n->brother);
  }
}

/**
 * @brief 動的に確保したノード変数の開放
 * 
 * @param n ノードのポインタ 
 */
void free_ast_tree(Node *n) {
  if (n->child != NULL) {
    free_ast_tree(n->child);
  }
  if (n->brother != NULL) {
    free_ast_tree(n->brother);
  }

  free(n);
}

void initialize(FILE *fp) {
  fprintf(fp, " INITIAL_GP = 0x10008000 # initial value of global pointer\n");
  fprintf(fp, " INITIAL_SP = 0x7ffffffc # initial value of stack pointer\n");
  fprintf(fp, "# system call service number\n");
  fprintf(fp, " stop_service = 99\n");
  fprintf(fp, "\n");
  fprintf(fp, " .text # テキストセグメントの開始\n"); 
  fprintf(fp, "init:\n");
  fprintf(fp, " # initialize $gp (global pointer) and $sp (stack pointer)\n");
  fprintf(fp, " la $gp, INITIAL_GP # $gp ←0x10008000 (INITIAL_GP)\n");
  fprintf(fp, " la $sp, INITIAL_SP # $sp ←0x7ffffffc (INITIAL_SP)\n");
  fprintf(fp, " jal main # jump to 'main'\n");
  fprintf(fp, " nop # (delay slot)\n");
  fprintf(fp, " li $v0, stop_service # $v0 <-99 (stop_service)\n");
  fprintf(fp, " syscall # stop\n");
  fprintf(fp, " nop\n");
  fprintf(fp, " # not reach here\n");
  fprintf(fp, "stop: # if syscall return\n");
  fprintf(fp, " j stop # infinite loop...\n");
  fprintf(fp, " nop # (delay slot)\n");
  fprintf(fp, "\n");
  fprintf(fp, " .text 0x00001000 # 以降のコードを 0から配置 x00001000\n");
  fprintf(fp, "main:\n");
  fprintf(fp, " la $t0, RESULT # $t0 <-0x10004000\n");
}

/* main */

int main(int argc, char *argv[]) {
  if (yyparse()) {
    fprintf(stderr, "Error!\n");
    return 1;
  }

  if (argc == 2) {
    code_fp = fopen(strcat(argv[1], ".s"), "w");
    if (code_fp == NULL) {
      fprintf(stderr, "Can't open file");
      return 1;
    }
  }
  else {
    code_fp = stdout;
  }


  // print_tree_in_json(top); // ASTの可視化

  // 記号情報リストの生成
  symbol_head =  init_sysbol_list();
  make_symbol_list(symbol_head, top);
  print_symbol_list();

  // コード生成
  initialize(code_fp);
  gen_code(top);
  free_ast_tree(top);

  fclose(code_fp);

  return 0;
}