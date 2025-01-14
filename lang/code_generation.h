#include "ast2.h"

int gen_code_add(Node *n, int reg_num);
void gen_code_expression(Node *n, int reg_num);
void gen_code_keep_operand(Node *op, int reg_num);
void gen_code_assignment(Node *n);
void gen_code_while(Node *n);
void gen_code_statement(Node *n);
void gen_code_statements(Node *n);