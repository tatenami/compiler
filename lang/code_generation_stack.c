#include "code_generation_stack.h"

/* Global variable */
FILE*  code_fp;
extern Node *top;
struct SymbolInfo *symbols;
int symbol_num = 0;
const unsigned int  var_base_size = 4;
const unsigned long base_address = 0x10004000;


const unsigned int reg_start = 2; // 自由に使えるレジスタの番号の最小値
const unsigned int stack_offset = 4;
char reg_dataseg[] = "$t0";
char reg_comp_result[] = "$t1"; // 比較演算の結果等の格納
char reg_op1[] = "$t2";
char reg_op2[] = "$t3";

/* global vals use generate code */
int num_whiles = 0;
int num_ifs = 0;
StackExp stack;


/* ---------- 記号表関連 ---------- */

long get_offset(char *var_name) {
  
  for (int i = 0; i < symbol_num; i++) {
    if (strcmp(var_name, symbols[i].var_name) == 0) {
      return symbols[i].mem_offset;
    }
  }

  return -1;
}

int get_array_row_size(char *var_name) {
  for (int i = 0; i < symbol_num; i++) {
    if (strcmp(var_name, symbols[i].var_name) == 0) {
      return symbols[i].mem_array_row;
    }
  }

  return -1;
}

// long get_array_offset(char *var_name, int index1, int index2) {
//   int var_offset = get_offset(var_name);
//   int offset = (index1 * var_base_size) + (index2 * get_array_row_size(var_name));
// }

void count_symbol(Node *n) {
  if (n->type == DECL_PART_AST) {
    symbol_num++;
  }

  if (n->child != NULL)  {
    count_symbol(n->child);
  }
  if (n->brother != NULL) {
    count_symbol(n->brother);
  }
}

/**
 * @brief 
 * 
 * @param s 
 * @param n 
 * @return struct SymbolInfo* 
 */
void make_symbol(Node *n, int num) {
  int size;
  int array_row_size = 0;
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
      array_row_size = num1 * var_base_size;
      if (index1->brother != NULL) { // ２次元配列
        int num2 = index1->brother->ival;
        size = (num1 + num2) * var_base_size;
      }
      else { // １次元配列
        size = num1 * var_base_size;
      }
      break; 
    }
  }

  symbols[num].number = num;
  symbols[num].target_node = n;
  symbols[num].mem_size   = size;
  symbols[num].mem_offset = (num == 0) ? 0 : (symbols[num - 1].mem_offset + symbols[num - 1].mem_size);
  symbols[num].mem_array_row = array_row_size;
  symbols[num].var_name   = n->var_name;
}

/**
 * @brief ノードツリーから再帰的に記号リスト情報を追加
 * 
 * @param s 末尾の記号リスト
 * @param n ツリーのノード
 * @return struct SymbolInfo* 
 */
int add_symbol(Node *n) {
  static int num = 0;

  if (n->type == DECL_PART_AST) {
    make_symbol(n->child, num++);
  }

  if (n->child != NULL) {
    add_symbol(n->child);
  }
  if (n->brother != NULL) {
    add_symbol(n->brother);
  }

  return num;
} 

void make_symbol_list(Node *n) {
  add_symbol(n);
}

void print_symbol_list(FILE *fp) {
  fprintf(fp, "# ------ [ Symbols ] ------\n");

  for (int i = 0; i < symbol_num; i++) {
    fprintf(fp, "# \tsymbol_%d \tsize: %d \toffset: %#5x \t[%s]\n", 
          i, symbols[i].mem_size, (int)(symbols[i].mem_offset), symbols[i].var_name);
  }

  fprintf(fp, "# -------------------------\n");
}

/* ---------- コード生成関連 ---------- */

void gen_code_push(const char *reg) {
  fprintf(code_fp, "  sw %s, %d($sp)\n", reg, stack.pointer);
  fprintf(code_fp, "  nop\n");
  stack.pointer += var_base_size;
}

void gen_code_pop(const char *reg) {
  stack.pointer -= var_base_size;
  fprintf(code_fp, "  lw %s, %d($sp)\n", reg, stack.pointer);
  fprintf(code_fp, "  nop\n");
}


void gen_code_keep_operand(Node *op, char *reg) {
  switch (op->type) {
    case NUMBER_AST: {
      fprintf(code_fp, "  # keep imm val (%d) to stack\n", op->ival);
      fprintf(code_fp, "  li %s, %d\n", reg, op->ival);
      break;
    }
    case IDENT_AST: {
      int var_offset = get_offset(op->var_name);
      fprintf(code_fp, "  # keep val (%s) to stack\n", op->var_name);
      fprintf(code_fp, "  lw %s, %d($t0)\n", reg, var_offset);
      fprintf(code_fp, "  nop\n");
      break;
    }
  }

  gen_code_push(reg);
}

// 
void gen_code_array_offset(Node *n, char *target) { // n -> IDENT_AST
  Node *index = n->brother;

  gen_code_expression(index->child, reg_op1);
  gen_code_pop(reg_op1); // index1 の確保 $t2
  fprintf(code_fp, "  li %s, %d", reg_op2, var_base_size); // 要素１つのサイズを確保 $t3
  gen_code_mul(reg_op1, reg_op1, reg_op2); // offset($t2) = $t2 * $t3
  fprintf(code_fp, "  li %s, %d", reg_op2, (int)get_offset(n->var_name)); // 変数のオフセットを確保 $t3
  gen_code_add(reg_op1, reg_op1, reg_op2);
  
  if (index->child->brother != NULL) { // index2
    gen_code_expression(index->child->brother, reg_op2);
    gen_code_pop(reg_op2);
    fprintf(code_fp, "  li $t4, %d", get_array_row_size(n->var_name)); // 配列１次元分サイズを確保 $t4
    // offset($t2) += (index2 * row_size)
    gen_code_mul(reg_op2, reg_op2, "$t4");
  }

  // base -> $t0, offset -> $t2  addressは$t2に
  gen_code_add(target, "$t0", reg_op1);    
}

void gen_code_comp(Node *n) {
  n = n->child;
  Node *op1 = n->child;
  Node *op2 = op1->brother;

  gen_code_expression(op1, reg_op1);
  gen_code_expression(op2, reg_op2);

  gen_code_pop(reg_op2);
  gen_code_pop(reg_op1);

  switch (n->type) {
    case LT_AST: {
      fprintf(code_fp, "  # comp '<'\n");
      fprintf(code_fp, "  slt %s, %s, %s\n", reg_comp_result, reg_op1, reg_op2);
      break;
    }
    case EQ_AST: {
      fprintf(code_fp, "  # comp '=='\n");
      fprintf(code_fp, "  sub %s, %s, %s\n", reg_comp_result, reg_op1, reg_op2);
      break;
    }
    case LTE_AST: {
      fprintf(code_fp, "  # comp '<='\n");
      fprintf(code_fp, "  sub %s, %s, %s\n", reg_comp_result, reg_op1, reg_op2);
      fprintf(code_fp, "  slti %s, %s, 1\n", reg_comp_result, reg_comp_result);
      break;
    }
  }
}

void gen_code_add(char *target, char *op1, char *op2) {
  fprintf(code_fp, "  # add exp\n");
  fprintf(code_fp, "  add %s, %s, %s\n", target, op1, op2);
}

void gen_code_sub(char *target, char *op1, char *op2) {
  fprintf(code_fp, "  # sub exp\n");
  fprintf(code_fp, "  sub %s, %s, %s\n", target, op1, op2);
}

void gen_code_mul(char *target, char *op1, char *op2) {
  fprintf(code_fp, "  # mul exp\n");
  fprintf(code_fp, "  mult %s, %s\n", op1, op2);
  fprintf(code_fp, "  mflo %s\n", target); // たちまち下位32Bitを計算結果として扱う
}

void gen_code_div(char *target, char *op1, char *op2) {
  fprintf(code_fp, "  # mul exp\n");
  fprintf(code_fp, "  div %s, %s\n", op1, op2);
  fprintf(code_fp, "  mflo %s\n", target); // 商を計算結果のレジスタへ
}

// 算術式生成
void gen_code_expression(Node *n, char *reg) { 
  // struct ThreeAddrCode *exps = (struct ThreeAddrCode *)malloc();

  if (n->type == IDENT_AST || n->type == NUMBER_AST) {
    gen_code_keep_operand(n, reg);
  }
  else {
    Node *op1 = n->child;
    Node *op2 = op1->brother;

    gen_code_expression(op1, reg_op1);
    gen_code_expression(op2, reg_op2);

    // 被演算子をロード
    gen_code_pop(reg_op2);
    gen_code_pop(reg_op1);

    switch (n->type) {
      case ADD_AST: {
        gen_code_add("$v0", reg_op1, reg_op2);
        break;
      }
      case SUB_AST: {
        gen_code_sub("$v0", reg_op1, reg_op2);
        break;  
      }
      case MUL_AST: {
        gen_code_mul("$v0", reg_op1, reg_op2);
        break;
      }
      case DIV_AST: {
        gen_code_div("$v0", reg_op1, reg_op2);
        break;
      }
    }

    gen_code_push("$v0");
  }
}

// 代入文生成

void gen_code_assignment(Node *n) {
  Node *ident = n->child;
  Node *expression = ident->brother;
  int offset;
  char *addr_reg;
  char *var_name;

  if (ident->type == ARRAY_AST) {
    var_name = ident->child->var_name;
  }
  else {
    var_name = ident->var_name;
  }

  if (expression->type == NUMBER_AST) {
    fprintf(code_fp, "  li %s, %d\n", "$v0", expression->ival);
    fprintf(code_fp, "  # assignment [%s] <- imm (%d)\n", var_name, expression->ival);
  }
  else {
    gen_code_expression(expression, "$v0");
    fprintf(code_fp, "  # assignment [%s] <- exp val\n", var_name);
  }

  if (ident->type == IDENT_AST) {
    addr_reg = reg_dataseg;
    offset = get_offset(var_name);
  }
  else { // 配列
    offset = 0;
    addr_reg = reg_op1;
    gen_code_array_offset(ident->child, reg_op1);
  }

  if (expression->type != NUMBER_AST) {
    gen_code_pop("$v0");  // 代入する数値
  }

  fprintf(code_fp, "  sw $v0, %d(%s)\n", offset, addr_reg);
  fprintf(code_fp, "  nop\n");
}

// if / if-else 生成
void gen_code_if(Node *n) {

  Node *cond  = n->child;
  Node *stmts = cond->brother;
  gen_code_comp(cond); // 条件式生成

  int num_if = num_ifs++;

  fprintf(code_fp, "  bne %s, $zero, $END_IF%d\n", reg_comp_result, num_if);
  fprintf(code_fp, "  nop\n");
  gen_code_statements(stmts);
  fprintf(code_fp, "$END_IF%d:\n", num_if);
}

void gen_code_elif(Node *n) {
  Node *if_stmt   = n->child;
  Node *else_stmt = if_stmt->brother;

  Node *cond  = if_stmt->child;
  Node *stmts = cond->brother;
  gen_code_comp(cond); // 条件式生成

  int num_if = num_ifs++;

  // else
  fprintf(code_fp, "  # else stmt\n");
  fprintf(code_fp, "  beq %s, $zero, $IF%d\n", reg_comp_result, num_if);
  fprintf(code_fp, "  nop\n");
  gen_code_statements(else_stmt->child);
  fprintf(code_fp, "  j $END_IF%d\n", num_if);
  fprintf(code_fp, "  nop\n");

  // if
  fprintf(code_fp, "  # if stmt\n");
  fprintf(code_fp, "$IF%d:\n", num_if);
  gen_code_statements(if_stmt);
  fprintf(code_fp, "$END_IF%d:\n", num_if);
}


// while 生成
void gen_code_while(Node *n) {
  Node *cond = n->child;
  Node *stmts = cond->brother;

  int this_while_num = num_whiles;

  fprintf(code_fp, "$WHILE%d:\n", this_while_num);

  gen_code_comp(cond);   // 継続の比較演算処理を生成
  // 比較結果が0なら終了
  fprintf(code_fp, "  beq %s, $zero, $ENDWHILE%d\n", reg_comp_result, this_while_num);
  fprintf(code_fp, "  nop\n");
  num_whiles++;

  gen_code_statements(stmts); // 内部の処理生成 

  fprintf(code_fp, "  j $WHILE%d\n", this_while_num);
  fprintf(code_fp, "  nop\n");
  fprintf(code_fp, "$ENDWHILE%d:\n", this_while_num);
}

void gen_code_statement(Node *n) {
  n = n->child; 
  switch (n->type) {
    case ASSIGNMENT_AST: {
      gen_code_assignment(n);
      break;
    }
    case WHILE_STMT_AST: {
      gen_code_while(n); // while内の処理が再帰的に生成されないよう return 
      return;
    }
    case IF_STMT_AST: {
      fprintf(code_fp, "  # --- [START] if stmt ---\n");
      gen_code_if(n); //  if内の処理が再帰的に生成されないよう return 
      return;
    }
    case ELIF_STMT_AST: {
      fprintf(code_fp, "  # --- [START] if-else stmt ---\n");
      gen_code_elif(n);
      return;
    }
  }
}

void gen_code_statements(Node *n) {
  Node *stmt = n->child;
  gen_code_statement(stmt);

  if (stmt->brother != NULL) {
    gen_code_statements(stmt->brother);
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
void gen_code(Node *n_top) {
  // printf("\ngen_code -> ");
  // print_node(n, num);

  Node *dec = n_top->child;
  Node *stmts = dec->brother;

  gen_code_statements(stmts);  
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

void gen_data_segment(struct SymbolInfo *s) {
  while (s != NULL) {
      
  }
}

void closing(FILE *fp) {
  fprintf(fp, "\n li $v0, stop_service\n");
  fprintf(fp, " syscall\n");
  fprintf(fp, " nop\n");
  fprintf(fp, " jr $ra\n");
  fprintf(fp, " nop\n");
  fprintf(fp, "\n");
  fprintf(fp, ".data 0x10004000\n");
  fprintf(fp, " RESULT:\n");
}

/* main */

#define JSON 0

int main(int argc, char *argv[]) {
  if (yyparse()) {
    fprintf(stderr, "Error!\n");
    return 1;
  }

  if (argc == 2) {
    code_fp = fopen(argv[1], "w");
    if (code_fp == NULL) {
      fprintf(stderr, "Can't open file");
      return 1;
    }
  }
  else {
    code_fp = stdout;
  }

  #if JSON
   print_tree_in_json(top); // ASTの可視化
  #endif

  // 記号情報リストの生成

  #if !JSON
  count_symbol(top);
  symbols = (struct SymbolInfo *)malloc(sizeof(struct SymbolInfo) * symbol_num);
  make_symbol_list(top);
  print_symbol_list(code_fp);
  print_symbol_list(stdout);

  // コード生成
  initialize(code_fp);
  stack.pointer = stack_offset;
  gen_code(top);
  closing(code_fp);
  #endif

  free_ast_tree(top);
  fclose(code_fp);

  return 0;
}