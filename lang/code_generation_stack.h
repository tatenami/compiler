#include "ast2.h"

struct SymbolInfo {
  Node  *target_node; // 対象のノード
  char  *var_name;    // 変数名
  int    number;      // 変数番号
  int    mem_size;    // 変数のメモリサイズ
  int    mem_array_row;
  long   mem_offset;  // データセグメントからのメモリオフセット
};

typedef union {
  unsigned char reg;
  Node *node;
} Operand;

struct ThreeAddrCode {
  Ntype op;
  unsigned char result;
  Operand op1;
  Operand op2;
  struct ThreeAddrCode *next;
};

typedef struct {
  int pointer;

} StackExp;

void gen_code_add(char *target, char *op1, char *op2);
void gen_code_sub(char *target, char *op1, char *op2);
void gen_code_mul(char *target, char *op1, char *op2);
void gen_code_div(char *target, char *op1, char *op2);
void gen_code_expression(Node *n, char *reg);
void gen_code_keep_operand(Node *op, char *reg);
void gen_code_unary_op(Node *op, Node *ident);
void gen_code_assignment(Node *n);
void gen_code_while(Node *n);
void gen_code_if(Node *n);
void gen_code_elif(Node *n);
void gen_code_statement(Node *n);
void gen_code_statements(Node *n);