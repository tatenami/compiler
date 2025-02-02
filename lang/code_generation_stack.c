#include "code_generation_stack.h"
#define OPT1 1
#define OPT2 1
#define OPT3 1

/* Global variable */
FILE*  code_fp;
extern Node *top;
struct SymbolInfo *symbols;
int symbol_num = 0;
const unsigned int  var_base_size = 4;
const unsigned long base_address = 0x10004000;


const unsigned int reg_start = 2; // 自由に使えるレジスタの番号の最小値
const unsigned int stack_offset = 0;
char reg_dataseg[] = "$t0";
char reg_comp_result[] = "$t1"; // 比較演算の結果等の格納
char reg_op1[] = "$t2";
char reg_op2[] = "$t3";
const int no_nop = 0;
const int nop = 1;

/* global vals use generate code */
int num_whiles = 0;
int num_fors = 0;
int num_ifs = 0;
int sp;

/* ---------- 記号表関連 ---------- */
int is_var_node(Node *n) {
  if (n->type == NUMBER_AST) {
    return 1;
  }
  if (n->type == IDENT_AST) {
    return 1;
  }
  if (n->type == ARRAY_AST) {
    return 1;
  }
  return 0;
}

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

void count_symbol(Node *n) {
  if (n->type == FUNC_DEFINE_AST) {
    if (strcmp(n->child->var_name, "main") != 0) {
      return;
    }
  }
  
  if (n->type == STATEMENTS_AST) {
    return;
  }

  if (n->type == ARRAY_AST || n->type == IDENTS_AST) {
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
int make_symbol(Node *n, int num) {
  int size;
  int next_num = num;
  int array_row_size = 0;
  switch (n->type) {
    case IDENTS_AST: {
      Node *indet = n->child; 
      n = n->child; // IDENT
      size = var_base_size;
      symbols[num].number = num;
      symbols[num].target_node = n;
      symbols[num].mem_size   = size;
      symbols[num].mem_offset = (num == 0) ? 0 : (symbols[num - 1].mem_offset + symbols[num - 1].mem_size);
      symbols[num].mem_array_row = array_row_size;
      symbols[num].var_name   = n->var_name;
      if (indet->brother != NULL) {
        next_num = make_symbol(indet->brother, num + 1);
      }
      else {
        next_num++;
      }
      return next_num;
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

      symbols[num].number = num;
      symbols[num].target_node = n;
      symbols[num].mem_size   = size;
      symbols[num].mem_offset = (num == 0) ? 0 : (symbols[num - 1].mem_offset + symbols[num - 1].mem_size);
      symbols[num].mem_array_row = array_row_size;
      symbols[num].var_name   = n->var_name;

      next_num++;
      return next_num;
    }
  }

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

  if (n->type == FUNC_DEFINE_AST) {
    if (strcmp(n->child->var_name, "main") != 0) {
      return 0;
    }
  }

  if (n->type == DECL_PART_AST) {
    num = make_symbol(n->child, num);
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
    fprintf(fp, "# \tsymbol_%d \tsize: %d \toffset: %#5x(%d) \t[%s]\n", 
          i, symbols[i].mem_size, (int)(symbols[i].mem_offset), (int)(symbols[i].mem_offset), symbols[i].var_name);
  }

  fprintf(fp, "# -------------------------\n");
}

/* ---------- コード生成関連 ---------- */

void gen_code_push(const char *reg) {
  fprintf(code_fp, "  sw %s, %d($sp)\n", reg, sp);
  fprintf(code_fp, "  nop\n");
  sp -= var_base_size;
}

void gen_code_pop(const char *reg) {
  fprintf(code_fp, "  # pop stack\n");
  sp += var_base_size;
  fprintf(code_fp, "  lw %s, %d($sp)\n", reg, sp);
  #if OPT2
  if (strcmp(reg, reg_op2) != 0) {
    fprintf(code_fp, "  nop\n");
  }
  #endif
  #if !OPT2
  fprintf(code_fp, "  nop\n");
  #endif
}

// 
void gen_code_array_offset(Node *n, char *target) { // n -> IDENT_AST
  Node *index = n->brother;

  fprintf(code_fp, "  # clac array offset of [%s]\n", n->var_name);
  
  if (index->child->brother != NULL) { // index2
    // printf("index2\n");
    Node *index1 = index->child;
    Node *index2 = index1->brother; 
    #if OPT3
    if (!is_var_node(index2)) {
      gen_code_expression(index2, reg_op1);
      gen_code_pop(reg_op1);
    }
    else {
      gen_code_keep_operand(index2, reg_op1, no_nop);
    }

    fprintf(code_fp, "  li %s, %d", "$t4", var_base_size); // 要素１つのサイズを確保 $t4
    gen_code_mul(reg_op1, reg_op1, "$t4"); // offset($t2) = $t2 * $t4

    // printf("index1\n");
    if (!is_var_node(index1)) {
      gen_code_expression(index1, reg_op2); // $t3
      gen_code_pop(reg_op2);
    }
    else {
      gen_code_keep_operand(index2, reg_op2, nop);
    }

    fprintf(code_fp, "  li $t4, %d", get_array_row_size(n->var_name)); // 配列１次元分サイズを確保 $t4
    gen_code_mul(reg_op2, reg_op2, "$t4"); // $t3 = (row(index) * row_size)
    gen_code_add(reg_op1, reg_op1, reg_op2); // offset($t2) += row_offset
    fprintf(code_fp, "  li %s, %d", reg_op2, (int)get_offset(n->var_name)); // 変数のオフセットを確保 $t3
    gen_code_add(reg_op1, reg_op1, reg_op2); // offset($t2) += var_offset
    #endif

    #if !OPT3
    gen_code_expression(index2, reg_op1); // $t2
    #if OPT1
    if (index2->type != NUMBER_AST) {
      gen_code_pop(reg_op1);
    }
    #endif
    #endif
    #if !OPT1
    gen_code_pop(reg_op1); // index2 の確保 $t2
    fprintf(code_fp, "  li %s, %d", reg_op2, var_base_size); // 要素１つのサイズを確保 $t3
    gen_code_mul(reg_op1, reg_op1, reg_op2); // offset($t2) = $t2 * $t3
    gen_code_expression(index1, reg_op2); // $t3
    #if OPT1
    if (index1->type != NUMBER_AST) {
      gen_code_pop(reg_op2);
    }
    #endif
    #if !OPT1
    gen_code_pop(reg_op2); // index1 の確保 $t3
    #endif
    fprintf(code_fp, "  li $t4, %d", get_array_row_size(n->var_name)); // 配列１次元分サイズを確保 $t4
    gen_code_mul(reg_op2, reg_op2, "$t4"); // $t3 = (row(index) * row_size)
    gen_code_add(reg_op1, reg_op1, reg_op2); // offset($t2) += row_offset
    fprintf(code_fp, "  li %s, %d", reg_op2, (int)get_offset(n->var_name)); // 変数のオフセットを確保 $t3
    gen_code_add(reg_op1, reg_op1, reg_op2); // offset($t2) += var_offset
    #endif
  }
  
  else { // index1
    #if OPT3
    // printf("index\n");
    index = index->child;
    #if OPT1
    if (!is_var_node(index)) {
      gen_code_expression(index, reg_op1);
      gen_code_pop(reg_op1);
    }
    else {
      gen_code_keep_operand(index, reg_op1, nop);
    }
    #endif
    #if !OPT1
    gen_code_pop(reg_op1); // index1 の確保 $t2
    #endif
    fprintf(code_fp, "  li %s, %d", reg_op2, var_base_size); // 要素１つのサイズを確保 $t3
    gen_code_mul(reg_op1, reg_op1, reg_op2); // offset($t2) = $t2 * $t3
    fprintf(code_fp, "  li %s, %d", reg_op2, (int)get_offset(n->var_name)); // 変数のオフセットを確保 $t3
    gen_code_add(reg_op1, reg_op1, reg_op2); // offset($t2) += var_offset
    #endif
    #if !OPT3
    // printf("index\n");
    index = index->child;
    gen_code_expression(index, reg_op1);
    #if OPT1
    if (index->type != NUMBER_AST) {
      gen_code_pop(reg_op1); // index1 の確保 $t2
    }
    #endif
    #if !OPT1
    gen_code_pop(reg_op1); // index1 の確保 $t2
    #endif
    fprintf(code_fp, "  li %s, %d", reg_op2, var_base_size); // 要素１つのサイズを確保 $t3
    gen_code_mul(reg_op1, reg_op1, reg_op2); // offset($t2) = $t2 * $t3
    fprintf(code_fp, "  li %s, %d", reg_op2, (int)get_offset(n->var_name)); // 変数のオフセットを確保 $t3
    gen_code_add(reg_op1, reg_op1, reg_op2); // offset($t2) += var_offset
    #endif
  }

  // base -> $t0, offset -> $t2  addressは$t2に
  gen_code_add(target, "$t0", reg_op1);    
  fprintf(code_fp, "  # array offset -> [%s]\n", target);
}


void gen_code_keep_operand(Node *op, char *reg, int nop_flag) {
  switch (op->type) {
    case NUMBER_AST: {
      fprintf(code_fp, "  # keep imm val (%d) to reg(%s)\n", op->ival, reg);
      fprintf(code_fp, "  li %s, %d\n", reg, op->ival);
      break;
    }
    case IDENT_AST: {
      int var_offset = get_offset(op->var_name);
      fprintf(code_fp, "  # keep val (%s) to reg(%s)\n", op->var_name, reg);
      fprintf(code_fp, "  lw %s, %d($t0)\n", reg, var_offset);
      #if OPT3
      if (nop_flag == nop) {
        fprintf(code_fp, "  nop\n");
      }
      #endif
      #if !OPT3
      fprintf(code_fp, "  nop\n");
      #endif
      break;
    }
    case ARRAY_AST: {
      gen_code_array_offset(op->child, reg);
      fprintf(code_fp, "  # keep element of array(%s) to reg(%s)\n", op->child->var_name, reg);
      fprintf(code_fp, "  lw %s, 0(%s)\n", reg, reg);
      #if OPT3
      if (nop_flag == nop) {
        fprintf(code_fp, "  nop\n");
      }
      #endif
      #if !OPT3
      fprintf(code_fp, "  nop\n");
      #endif
      break;
    }
  }
}


void gen_code_eq(char *target, char *op1, char *op2) {
  fprintf(code_fp, "  # comp '=='\n");
  fprintf(code_fp, "  sub %s, %s, %s\n", target, reg_op1, reg_op2);
  fprintf(code_fp, "  sltiu %s, %s, 1\n", target, target);
}

void gen_code_ne(char *target, char *op1, char *op2) {
  fprintf(code_fp, "  # comp '!='\n");
  fprintf(code_fp, "  sub %s, %s, %s\n", target, reg_op1, reg_op2);
  fprintf(code_fp, "  sltu %s, $zero, %s\n", target, target);
}

void gen_code_lt(char *target, char *op1, char *op2) {
  fprintf(code_fp, "  # comp '<'\n");
  fprintf(code_fp, "  slt %s, %s, %s\n", target, reg_op1, reg_op2);
}

void gen_code_gt(char *target, char *op1, char *op2) {
  fprintf(code_fp, "  # comp '>'\n");
  fprintf(code_fp, "  slt %s, %s, %s\n", target, reg_op2, reg_op1);
}

void gen_code_lte(char *target, char *op1, char *op2) {
    fprintf(code_fp, "  # comp '<='\n");
    fprintf(code_fp, "  sub %s, %s, %s\n", target, reg_op1, reg_op2);
    fprintf(code_fp, "  slti %s, %s, 1\n", target, target);
}

void gen_code_gte(char *target, char *op1, char *op2) {
  fprintf(code_fp, "  # comp '>='\n");
  fprintf(code_fp, "  sub %s, %s, %s\n", target, reg_op2, reg_op1);
  fprintf(code_fp, "  slti %s, %s, 1\n", target, target);
}


void gen_code_comp(Node *n) {
  n = n->child;
  Node *op1 = n->child;
  Node *op2 = op1->brother;

  #if OPT3
  if (!is_var_node(op1)) {
    gen_code_expression(op1, reg_op1);
  }
  if (!is_var_node(op2)) {
    gen_code_expression(op2, reg_op2);
  }

  if (!is_var_node(op2)) {
    gen_code_pop(reg_op2);
  }
  else {
    gen_code_keep_operand(op2, reg_op2, no_nop);
  }

  if (!is_var_node(op1)) {
    gen_code_pop(reg_op1);
  }
  else {
    gen_code_keep_operand(op1, reg_op1, nop);
  }
  #endif

  #if !OPT3
  gen_code_expression(op1, reg_op1);
  gen_code_expression(op2, reg_op2);

  #if OPT1
  if (op2->type != NUMBER_AST) {
    gen_code_pop(reg_op2);
  }
  
  if (op1->type != NUMBER_AST) {
    gen_code_pop(reg_op1);
  }
  #endif

  #if !OPT1
  gen_code_pop(reg_op2);
  gen_code_pop(reg_op1);
  #endif
  #endif

  switch (n->type) {
    case EQ_AST: {
      gen_code_eq(reg_comp_result, reg_op1, reg_op2);
      break;
    }
    case NE_AST: {
      gen_code_ne(reg_comp_result, reg_op1, reg_op2);
      break;
    }
    case LT_AST: {
      gen_code_lt(reg_comp_result, reg_op1, reg_op2);
      break;
    }
    case GT_AST: {
      gen_code_gt(reg_comp_result, reg_op1, reg_op2);
      break;
    }
    case LTE_AST: {
      gen_code_lte(reg_comp_result, reg_op1, reg_op2);
      break;
    }
    case GTE_AST: {
      gen_code_gte(reg_comp_result, reg_op1, reg_op2);
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
  fprintf(code_fp, "  # div exp\n");
  fprintf(code_fp, "  div %s, %s\n", op1, op2);
  fprintf(code_fp, "  mflo %s\n", target); // 商を計算結果のレジスタへ
}

void gen_code_rem(char *target, char *op1, char *op2) {
  fprintf(code_fp, "  # div exp\n");
  fprintf(code_fp, "  div %s, %s\n", op1, op2);
  fprintf(code_fp, "  mfhi %s\n", target); // 剰余を計算結果のレジスタへ
}

void gen_code_and(char *target, char *op1, char *op2) {
  fprintf(code_fp, "  # and exp\n");
  fprintf(code_fp, "  and %s, %s, %s\n", target, op1, op2);
}

void gen_code_or(char *target, char *op1, char *op2) {
  fprintf(code_fp, "  # or exp\n");
  fprintf(code_fp, "  or %s, %s, %s\n", target, op1, op2);
}
void gen_code_xor(char *target, char *op1, char *op2) {
  fprintf(code_fp, "  # xor exp\n");
  fprintf(code_fp, "  xor %s, %s, %s\n", target, op1, op2);
}

void gen_code_lshift(char *target, char *op1, char *op2) {
  fprintf(code_fp, "  # L-shift exp\n");
  fprintf(code_fp, "  sllv %s, %s, %s\n", target, op1, op2);
}

void gen_code_rshift(char *target, char *op1, char *op2) {
  fprintf(code_fp, "  # R-shift exp\n");
  fprintf(code_fp, "  srav %s, %s, %s\n", target, op1, op2);
}

void gen_code_not(char *target, char *op1, char *op2) {
  fprintf(code_fp, "  # not exp\n");
  fprintf(code_fp, "  srav %s, %s, %s\n", target, op1, op2);
}


// 算術式生成
void gen_code_expression(Node *n, char *reg) { 
  // struct ThreeAddrCode *exps = (struct ThreeAddrCode *)malloc();
  int b_unary_flag = 0;

  #if OPT2
  int val_nop = nop;
  if (strcmp(reg, reg_op2) == 0) {
    val_nop = no_nop;
  }
  #endif

  #if !OPT3
  if (n->type == IDENT_AST) {
    gen_code_keep_operand(n, reg, val_nop);
    gen_code_push(reg);
  }
  else if (n->type == NUMBER_AST) {
    gen_code_keep_operand(n, reg, val_nop);
    #if !OPT1
    gen_code_push(reg);
    #endif
  }
  else if (n->type == ARRAY_AST) {
    gen_code_keep_operand(n, reg, val_nop);
    gen_code_push(reg);
  }
  #endif
  #if OPT3
  if (n->type == UNARY_OP_AST) {
    Node *op = n->child;
    Node *ident = op->brother;

    if (op->type == B_INCREM_AST || op->type == B_DECREM_AST) {
      gen_code_keep_operand(ident, reg, nop);
      gen_code_push(reg);
      gen_code_unary_op(op, ident);
    }
    else {
      gen_code_unary_op(op, ident);
      gen_code_keep_operand(ident, reg, nop);
      gen_code_push(reg);
    }
  }
  #endif
  #if !OPT3
  else if (n->type == UNARY_OP_AST) {
    Node *op = n->child;
    Node *ident = op->brother;

    if (op->type == B_INCREM_AST || op->type == B_DECREM_AST) {
      gen_code_keep_operand(ident, reg, val_nop);
      gen_code_push(reg);
      gen_code_unary_op(op, ident);
    }
    else {
      gen_code_unary_op(op, ident);
      gen_code_keep_operand(ident, reg, val_nop);
      gen_code_push(reg);
    }
  }
  #endif
  else if (n->type == NOT_AST) {
    Node *ident = n->child;
    gen_code_keep_operand(ident, reg, nop);
    fprintf(code_fp, "  sub %s, $zero, %s\n", reg, reg);
    fprintf(code_fp, "  addi %s, %s, -1\n", reg, reg);                                                                                                                                                                                                                                                                                                                             
    gen_code_push(reg);
  }
  else {
    Node *op1 = n->child;
    Node *op2 = op1->brother;

    #if OPT3
    if (!is_var_node(op1)) {
      gen_code_expression(op1, reg_op1);
    }
    if (!is_var_node(op2)) {
      gen_code_expression(op2, reg_op2);
    }
    #endif 

    #if !OPT3
    gen_code_expression(op1, reg_op1);
    gen_code_expression(op2, reg_op2);
    #endif
    // 被演算子をロード
    #if !OPT3
    #if OPT1
    if (op2->type != NUMBER_AST) {
      gen_code_pop(reg_op2);
    }
    if (op1->type != NUMBER_AST) {
      gen_code_pop(reg_op1);
    }
    #endif 
    #endif

    #if OPT3
    if (!is_var_node(op2)) {
      gen_code_pop(reg_op2);
    }
    else {
      gen_code_keep_operand(op2, reg_op2, no_nop);
    }

    if (!is_var_node(op1)) {
      gen_code_pop(reg_op1);
    }
    else {
      gen_code_keep_operand(op1, reg_op1, nop);
    }
    #endif

    #if !OPT1
    gen_code_pop(reg_op2);
    gen_code_pop(reg_op1);
    #endif

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
      case REM_AST: {
        gen_code_rem("$v0", reg_op1, reg_op2);
        break;
      }
      case AND_AST: {
        gen_code_and("$v0", reg_op1, reg_op2);
        break;
      }
      case OR_AST: {
        gen_code_or("$v0", reg_op1, reg_op2);
        break;
      }
      case XOR_AST: {
        gen_code_xor("$v0", reg_op1, reg_op2);
        break;  
      }
      case L_SHIFT_AST: {
        gen_code_lshift("$v0", reg_op1, reg_op2);
        break;
      }
      case R_SHIFT_AST: {
        gen_code_rshift("$v0", reg_op1, reg_op2);
        break;
      }
    }

    gen_code_push("$v0");
  }
}

// 代入文生成
void gen_code_unary_op(Node *op, Node *ident) {
  int offset;
  char *addr_reg;

  gen_code_keep_operand(ident, "$v0", nop);

  fprintf(code_fp, "  # unary operation\n");
  if (op->type == F_INCREM_AST || op->type == B_INCREM_AST) {
    fprintf(code_fp, "  addi $v0, $v0, 1\n");
  }
  else {
    fprintf(code_fp, "  addi $v0, $v0, -1\n");
  }

  if (ident->type == IDENT_AST) {
    addr_reg = reg_dataseg;
    offset = get_offset(ident->var_name);
  }
  else { // 配列
    offset = 0;
    addr_reg = reg_op1;
    gen_code_array_offset(ident->child, reg_op1);
  }

  fprintf(code_fp, "  sw $v0, %d(%s)\n", offset, addr_reg);
  fprintf(code_fp, "  nop\n");
}

void gen_code_assignment(Node *n) {
  if (n->child->type == UNARY_OP_AST) {
    Node *op = n->child->child;
    Node *ident = op->brother;
    gen_code_unary_op(op, ident);
  }
  else {
    Node *ident = n->child;
    Node *expression = ident->brother;
    int offset;
    char *addr_reg;
    char *var_name;

    // 変数名の設定
    if (ident->type == ARRAY_AST) {
      var_name = ident->child->var_name;
    }
    else {
      var_name = ident->var_name;
    }

    #if OPT3
    fprintf(code_fp, "  # assignment [%s] <- val\n", var_name);
    if (is_var_node(expression)) {
      gen_code_keep_operand(expression, "$v0", nop);
    }
    else {
      gen_code_expression(expression, "$v0");
      gen_code_pop("$v0");
    }
    #endif

    #if !OPT3
    // 右辺を計算 -> $v0へ
    if (expression->type == NUMBER_AST) { // 右辺が数値
      fprintf(code_fp, "  li %s, %d\n", "$v0", expression->ival);
      fprintf(code_fp, "  # assignment [%s] <- imm (%d)\n", var_name, expression->ival);
    }
    else { // 右辺が変数または式
      gen_code_expression(expression, "$v0");
      fprintf(code_fp, "  # assignment [%s] <- exp val\n", var_name);
    }
    #endif

    if (ident->type == IDENT_AST) {
      addr_reg = reg_dataseg;
      offset = get_offset(var_name);
    }
    else { // 配列
      offset = 0;
      addr_reg = reg_op1;
      gen_code_array_offset(ident->child, reg_op1);
    }

    #if !OPT3
    if (expression->type != NUMBER_AST) {
      gen_code_pop("$v0");  // 代入する数値
    }
    #endif

    fprintf(code_fp, "  sw $v0, %d(%s)\n", offset, addr_reg);
    fprintf(code_fp, "  nop\n");
  }
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
  fprintf(code_fp, "  bne %s, $zero, $IF%d\n", reg_comp_result, num_if);
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

void gen_code_for(Node *n) {
  Node *assign_init = n->child;
  Node *condition   = assign_init->brother;
  Node *assign_last = condition->brother;
  Node *stmts = assign_last->brother;

  int this_for_num = num_fors;

  gen_code_assignment(assign_init); // 初期化部分の生成
  fprintf(code_fp, "$FOR%d:\n", this_for_num);

  gen_code_comp(condition);

  fprintf(code_fp, "  beq %s, $zero, $ENDFOR%d\n", reg_comp_result, this_for_num);
  fprintf(code_fp, "  nop\n");
  num_fors++;

  gen_code_statements(stmts);

  gen_code_assignment(assign_last);

  fprintf(code_fp, "  j $FOR%d\n", this_for_num);
  fprintf(code_fp, "  nop\n");
  fprintf(code_fp, "$ENDFOR%d:\n", this_for_num);
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
    case FOR_STMT_AST: {
      gen_code_for(n);
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

void gen_code_func(Node *n) {

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
  switch (n->type) {
    case STATEMENTS_AST: {
      gen_code_statements(n);
      return;
    }
    case FUNC_DEFINE_AST: {
      gen_code_func(n);
      return;
    }
  }

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

void gen_data_segment(struct SymbolInfo *s) {
  while (s != NULL) {
      
  }
}

void closing(FILE *fp) {
  fprintf(fp, " li $v0, stop_service\n");
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
  sp = stack_offset;
  gen_code(top);
  closing(code_fp);
  #endif

  free_ast_tree(top);
  fclose(code_fp);

  return 0;
}