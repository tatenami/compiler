#include "ast2.h"

void gen_code_add();
int gen_code_expression(Node *n, int reg_num, int offset);
int gen_code_keep_operand(Node *op, int reg_num, int offset);
void gen_code_assignment(Node *n);
void gen_code_while(Node *n);
void gen_code_if(Node *n);
void gen_code_elif(Node *n);
void gen_code_statement(Node *n);
void gen_code_statements(Node *n);