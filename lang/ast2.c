#include "ast2.h"

Node *top; // 抽象構文木のルートノード保存用

// プリント用
char *node_types[] = {
  "DEFINE_AST",
  "ARRAY_DEF_AST",
  "ARRAY_INDEX"
  "ASSIGN_AST",
  "IDENT_AST",
  "IDENTS_AST",
  "NUMBER_AST",
  "FLOAT_AST",
  "FOR_AST",
  "WHILR_AST",
  "IF_AST",
  "ELSE_AST",

  "BREAK_AST",
  "ADD_AST",
  "SUB_AST",
  "MUL_AST",
  "DIV_AST",
  "REM_AST",
  "AND_AST",
  "OR_AST",
  "XOR_AST",
  "L_SHIFT_AST",
  "R_SHIFT_AST",
  "EQ_AST",
  "NE_AST", 
  "LT_AST",
  "GT_AST",
  "LTE_AST",
  "GTE_AST",

  "VAR_AST",
  "ADD_OP_AST",
  "MUL_OP_AST",
  "BIT_OP_AST",
  "COND_OP_AST",
  "INCREM_AST",
  "DECREM_AST",
  "UNARY_OP_AST",
  "UNARY_FACTOR_AST",
  "FACTOR_AST",
  "TERM_AST",
  "ARRAY_PART_AST",
  "ARRAY_AST",
  "EXPRESSION_AST",
  "EXPRESSIONS_AST",
  "ASSIGNMENT_AST",
  "FUNC_ARG_PART_AST",
  "FUNC_VAR_DECL_AST",
  "FUNC_DECL_AST",
  "FUNC_CALL_AST",
  "CONDITION_AST",
  "COND_STMT_AST",
  "IF_STMT_AST",
  "ELIF_STMT_AST",
  "LOOP_STMT_AST",
  "WHILE_STMT_AST",
  "FOR_STMT_AST",
  "BREAK_STMT_AST",
  "ASSIGNMENT_STMT_AST",
  "STATEMENT_AST",
  "STATEMENTS_AST",
  "DECL_PART_AST",
  "DECL_STATEMENT_AST",
  "DECLARATIONS_AST",
  "FUNC_DEFINE_AST",
  "PROGRAM_AST",
};

void print_node_type(int node_type) {
  printf("Node type: %s\n", node_types[node_type]);
}

/* ノードの生成 */
Node *build_node0(Ntype t) {
  Node *p;
  p = (Node *)malloc(sizeof(Node));

  if (p == NULL) {
    yyerror("out of memory");
  }
  p->type = t;
  p->child = NULL;
  return p;
}

Node *build_node1(Ntype t, Node *p1) {
  Node *p;
  p = (Node *)malloc(sizeof(Node));

  if (p == NULL) {
    yyerror("out of memory");
  }
  p->type = t;
  p->child = p1;
  return p;
}

Node *build_node2(Ntype t, Node *p1, Node *p2) {
  Node *p;
  p = (Node *)malloc(sizeof(Node));

  if (p == NULL) {
    yyerror("out of memory");
  }
  p->type = t;
  p->child = p1;
  p->child->brother = p2;
  return p;
}

Node *build_node3(Ntype t, Node *p1, Node *p2, Node *p3) {
  Node *p;
  p = (Node *)malloc(sizeof(Node));

  if (p == NULL) {
    yyerror("out of memory");
  }
  p->type = t;
  p->child = p1;
  p->child->brother = p2;
  p->child->brother->brother = p3;
  return p;
}

Node *build_node4(Ntype t, Node *p1, Node *p2, Node *p3, Node *p4) {
  Node *p;
  p = (Node *)malloc(sizeof(Node));

  if (p == NULL) {
    yyerror("out of memory");
  }
  p->type = t;
  p->child = p1;
  p->child->brother = p2;
  p->child->brother->brother = p3;
  p->child->brother->brother->brother = p4;
  return p;
}

/* ASTの可視化 */
void print_tree_in_json(Node *n) {
  if (n != NULL) {
    int num = 0;
    printf("{");
    print_tree(n, num);
    printf("}");
  }
}

int print_tree(Node *n, int num) {
  printf("\"%s_%d\": {\n", node_types[n->type], num++);
  if (n->child != NULL) {
    num = print_tree(n->child, num);
  }
  printf("}\n");
  if (n->brother != NULL) {
    printf(", ");
    num = print_tree(n->brother, num);
  }
  return num;
}

int main() {
  if (yyparse()) {
    fprintf(stderr, "Error!\n");
    return 1;
  }
  // printf("OK!\n");
  // printf("[*] AST generation is completed\n");
  print_tree_in_json(top); // ASTの可視化

  return 0;
}