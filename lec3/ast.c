#include "ast.h"

Node *top; // 抽象構文木のルートノード保存用

// プリント用
char *node_types[] = {
  "IDENT_AST",
  "IDENTS_AST",
  "NUMBER_AST",
  "STATEMENT_AST",
  "STATEMENTS_AST",
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
  printf("\"%s_%d\": {", node_types[n->type], num++);
  if (n->child != NULL) {
    num = print_tree(n->child, num);
  }
  printf("}");
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

  // printf("[*] AST generation is completed\n");
  print_tree_in_json(top); // ASTの可視化

  return 0;
}