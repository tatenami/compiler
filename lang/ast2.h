#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char* yytext;
extern int yyparse();
extern int yyerror(const char *msg);

// ノードタイプ
typedef enum {
  DEFINE_AST = 0,
  ARRAY_DEF_AST,
  ARRAY_INDEX_AST,
  ASSIGN_AST,
  IDENT_AST,
  IDENTS_AST,
  NUMBER_AST,
  FLOAT_AST,
  CHAR_AST,
  STR_AST,
  FOR_AST,
  WHILR_AST,
  IF_AST,
  ELSE_AST,
  BREAK_AST,
  ADD_AST,
  SUB_AST,
  MUL_AST,
  DIV_AST,
  REM_AST,
  AND_AST,
  OR_AST,
  XOR_AST,
  L_SHIFT_AST,
  R_SHIFT_AST,
  EQ_AST,
  NE_AST, 
  LT_AST,
  GT_AST,
  LTE_AST,
  GTE_AST,
  OP_ADD,
  OP_SUB,
  OP_MUL,
  OP_DIV,
  OP_REM,
  OP_AND,
  OP_OR,
  OP_XOR,
  OP_L_SHIFT,
  OP_R_SHIFT,
  OP_EQ,
  OP_NE, 
  OP_LT,
  OP_GT,
  OP_LTE,
  OP_GTE,
  VAR_AST,
  INCREM_AST,
  DECREM_AST,
  UNARY_OP_AST,
  UNARY_FACTOR_AST,
  FACTOR_AST,
  TERM_AST,
  ARRAY_PART_AST,
  ARRAY_AST,
  EXPRESSION_AST,
  EXPRESSIONS_AST,
  ASSIGNMENT_AST,
  FUNC_ARG_PART_AST,
  FUNC_VAR_DECL_AST,
  FUNC_DECL_AST,
  FUNC_CALL_AST,
  CONDITION_AST,
  COND_STMT_AST,
  IF_STMT_AST,
  ELSE_STMT_AST,
  ELIF_STMT_AST,
  LOOP_STMT_AST,
  WHILE_STMT_AST,
  FOR_STMT_AST,
  BREAK_STMT_AST,
  ASSIGNMENT_STMT_AST,
  STATEMENT_AST,
  STATEMENTS_AST,
  DECL_PART_AST,
  DECL_STATEMENT_AST,
  DECLARATIONS_AST,
  FUNC_DEFINE_AST,
  PROGRAM_AST,
} Ntype;

// 抽象構文木のノードのデータ構造
typedef struct node {
  Ntype  type;
  int    ival;
  float  fval;
  char   cval;
  char*  sval;
  char*  variable;
  struct node *child;
  struct node *brother;  
} Node;

typedef struct symbols {
  int symno;
  char *symbolname;
  struct symbols* next;
} Symbols;

// 抽象構文木のノードの生成
Node *build_num_node(Ntype t, int n);
Node *build_float_node(Ntype t, float n);
Node *build_char_node(Ntype t, char c);
Node *build_str_node(Ntype t, char *s);
Node *build_ident_node(Ntype t, char *s);
Node *build_node0(Ntype t);
Node *build_node1(Ntype t, Node *p1);
Node *build_node2(Ntype t, Node *p1, Node *p2);
Node *build_node3(Ntype t, Node *p1, Node *p2, Node *p3);
Node *build_node4(Ntype t, Node *p1, Node *p2, Node *p3, Node *p4);

/* ASTの可視化 */
void print_tree_in_json(Node *n);
int  print_tree(Node *n, int num);

// プリント用
extern char *node_types[];

// プロトタイプ宣言
void print_node_type(int node_type);
