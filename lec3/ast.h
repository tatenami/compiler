#include <stdio.h>
#include <stdlib.h>

extern int yyparse();
extern int yyerror(const char *msg);

// ノードタイプ
typedef enum {
  IDENT_AST = 0,
  IDENTS_AST,
  NUMBER_AST,
  STATEMENT_AST,
  STATEMENTS_AST
} Ntype;

// 抽象構文木のノードのデータ構造
typedef struct node {
  Ntype type;
  struct node *child;
  struct node *brother;  
} Node;

// 抽象構文木のノードの生成
Node *build_node0(Ntype t);
Node *build_node1(Ntype t, Node *p1);
Node *build_node2(Ntype t, Node *p1, Node *p2);

/* ASTの可視化 */
void print_tree_in_json(Node *n);
int  print_tree(Node *n, int num);

// プリント用
extern char *node_types[];

// プロトタイプ宣言
void print_node_type(int node_type);
