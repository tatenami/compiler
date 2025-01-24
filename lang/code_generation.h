#include "ast2.h"

int is_operator(Node *n);
int gen_code_add(Node *n, int reg_num);
int gen_code_expression(Node *n, int reg_num);
void gen_code_keep_operand(Node *op, int reg_num);
void gen_code_assignment(Node *n);
void gen_code_while(Node *n);
void gen_code_if(Node *n);
void gen_code_elif(Node *n);
void gen_code_statement(Node *n);
void gen_code_statements(Node *n);
struct ThreeAddrCode *make_exp_3ac(Node *n);
void add_exp_3ac(struct ThreeAddrCode *exp, Node *n);