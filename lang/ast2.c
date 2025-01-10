#include "ast2.h"

#define MAX_VAR_NAME 100
#define MAX_STR_LEN 100

Node *top; // 抽象構文木のルートノード保存用

// プリント用
char *node_types[] = {
  "DEFINE_AST",
  "ARRAY_DEF_AST",
  "ARRAY_INDEX",
  "ASSIGN_AST",
  "IDENT_AST",
  "IDENTS_AST",
  "NUMBER_AST",
  "FLOAT_AST",
  "CHAR_AST",
  "STR_AST",
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
  "OP_ADD",
  "OP_SUB",
  "OP_MUL",
  "OP_DIV",
  "OP_REM",
  "OP_AND",
  "OP_OR",
  "OP_XOR",
  "OP_L_SHIFT",
  "OP_R_SHIFT",
  "OP_EQ",
  "OP_NE", 
  "OP_LT",
  "OP_GT",
  "OP_LTE",
  "OP_GTE",
  "VAR_AST",
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
  "ELSE_STMT_AST",
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

Node* build_num_node(Ntype t, int n){
  Node *p = (Node *)malloc(sizeof(Node));
  if(p == NULL){
    yyerror("out of memory");
  }
  p->type = t;
  p->ival = n;
  p->variable = NULL;
  p->child = NULL;
  p->brother = NULL;
  return p;
}


Node *build_float_node(Ntype t, float n) {
  Node *p;
  p = (Node *)malloc(sizeof(Node));

  if (p == NULL) {
    yyerror("out of memory");
  }

  p->type = t;
  p->fval = n;
  p->child = NULL;
  p->brother = NULL;
  p->variable = NULL;

  return p;
}

Node *build_char_node(Ntype t, char c) {
  Node *p;
  p = (Node *)malloc(sizeof(Node));

  if (p == NULL) {
    yyerror("out of memory");
  }

  p->type = t;
  p->cval = c;
  p->child = NULL;
  p->brother = NULL;
  p->variable = NULL;

  return p;
}

Node *build_str_node(Ntype t, char *s) {
  Node *p;
  p = (Node *)malloc(sizeof(Node));

  if (p == NULL) {
    yyerror("out of memory");
  }

  p->sval = (char *)malloc(MAX_STR_LEN);

  if (p->sval == NULL) {
    yyerror("out of memory");
  }

  p->type = t;
  strncpy(p->sval, s, MAX_STR_LEN);
  p->child = NULL;
  p->brother = NULL;
  p->variable = NULL;

  return p;
}

Node *build_ident_node(Ntype t, char *s) {
  Node *p;
  p = (Node *)malloc(sizeof(Node));

  if (p == NULL) {
    yyerror("out of memory");
  }

  p->variable = (char *)malloc(MAX_VAR_NAME);

  if (p->variable == NULL) {
    yyerror("out of memory");
  }

  p->type = t;
  strncpy(p->variable, s, MAX_VAR_NAME);
  p->child = NULL;
  p->brother = NULL;

  return p;
}


Node *build_node0(Ntype t) {
  Node *p;
  p = (Node *)malloc(sizeof(Node));

  if (p == NULL) {
    yyerror("out of memory");
  }
  p->type = t;
  p->child = NULL;
  p->variable = NULL;
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
  p->variable = NULL;
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
  p->variable = NULL;
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
  p->variable = NULL;
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
  p->variable = NULL;
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
  if (n->type == IDENT_AST) {
    printf("\"%s(%s)_%d\": {\n", node_types[n->type], n->variable, num++);
  }
  else if (n->type == NUMBER_AST) {
    printf("\"%s(%d)_%d\": {\n", node_types[n->type], n->ival, num++);
  }
  else if (n->type == FLOAT_AST) {
    printf("\"%s(%f)_%d\": {\n", node_types[n->type], n->fval, num++);
  }
  else if (n->type == CHAR_AST) {
    printf("\"%s(%c)_%d\": {\n", node_types[n->type], n->cval, num++);
  }
  else if (n->type == STR_AST) {
    printf("\"%s(%s)_%d\": {\n", node_types[n->type], n->sval, num++);
  }
  else {
    printf("\"%s_%d\": {\n", node_types[n->type], num++);
  }

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
