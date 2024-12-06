%{
  #include <stdio.h>
  #include "lang2.tab.h"
  #include "ast2.h"
  extern int yylex();

  int assign_count = 0, define_count = 0;
  extern Node *top;
%}

%union {
  struct node *np;
  char* var;
  char  chara;
  char* str;
  int   ival;
  float fval;
}

%type <np> program declarations func_define decl_statement decl_part statements statement
           func_var_decl func_arg_part
           break_stmt assignment_stmt assignment loop_stmt cond_stmt func_call expressions expression 
           while_stmt if_stmt elif_stmt for_stmt
           condition array array_index term factor unary_factor unary_op bit_op mul_op div_op rem_op add_op sub_op var idents
           eq_op ne_op lt_op lte_op gt_op gte_op

%token DEFINE ASSIGN ARRAY_DEF 
       L_BRACKET R_BRACKET L_PARAN R_PARAN L_BRACE R_BRACE
       SEMIC COMMA ADD SUB MUL DIV REM INCREM DECREM EQ NE LT GT LTE GTE
       AND OR XOR NOT L_SHIFT R_SHIFT
       FUNCDECL FUNCCALL BREAK
       FOR WHILE IF ELSE <var>IDENT <chara>CHAR <str>STRING <ival>NUMBER <fval>FLOAT

%define parse.error verbose

%%

program
  : declarations statements { top = build_node2(PROGRAM_AST, $1, $2); }
  | func_define             { top = build_node1(PROGRAM_AST, $1); }
;

declarations
  : decl_statement declarations { $$ = build_node2(DECLARATIONS_AST, $1, $2); }
  | decl_statement              { $$ = build_node1(DECLARATIONS_AST, $1); }

// ex2
array_index
  : L_BRACKET expression R_BRACKET {} // ex1
  | L_BRACKET expression R_BRACKET L_BRACKET expression R_BRACKET {} // ex1
;

array
  : IDENT array_index { $$ = build_node2(ARRAY_AST, build_node0(IDENT_AST), $2); }
;

decl_part
  : DEFINE idents {
    $$ = build_node1(DECL_PART_AST, $2);
  }
  | ARRAY_DEF array {
    $$ = build_node1(DECL_PART_AST, $2);
  }
;

func_arg_part
  : DEFINE IDENT {
    $$ = build_node1(FUNC_ARG_PART_AST, build_node0(IDENT_AST));
  }
  | ARRAY_DEF array {
    $$ = build_node1(FUNC_ARG_PART_AST, $2);
  }
;

decl_statement
  : decl_part SEMIC { $$ = build_node1(DECL_STATEMENT_AST, $1); }
  | func_define     { $$ = build_node1(DECL_STATEMENT_AST, $1); }
;

/* ex3 */
func_var_decl
  : func_arg_part                     { $$ = build_node1(FUNC_VAR_DECL_AST, $1); }
  | func_arg_part COMMA func_var_decl { $$ = build_node2(FUNC_VAR_DECL_AST, $1, $3); }
;

func_define
  : FUNCDECL IDENT L_PARAN func_var_decl R_PARAN L_BRACE declarations statements R_BRACE { 
    $$ = build_node4(FUNC_DEFINE_AST, build_node0(IDENT_AST), $4, $7, $8);
  }
  | FUNCDECL IDENT L_PARAN R_PARAN L_BRACE declarations statements R_BRACE { 
    $$ = build_node3(FUNC_DEFINE_AST, build_node0(IDENT_AST), $6, $7);
  }
;

func_call
  : FUNCCALL IDENT L_PARAN expressions R_PARAN SEMIC {
    $$ = build_node2(FUNC_CALL_AST, build_node0(IDENT_AST), $4);
  }
  | FUNCCALL IDENT L_PARAN  R_PARAN SEMIC {
    $$ = build_node1(FUNC_CALL_AST, build_node0(IDENT_AST));
  }
;

/* ex3 */

statements
  : statement statements { $$ = build_node2(STATEMENTS_AST, $1, $2); }
  | statement            { $$ = build_node1(STATEMENTS_AST, $1); }
;

statement
  : assignment_stmt { $$ = build_node1(STATEMENT_AST, $1); }
  | loop_stmt       { $$ = build_node1(STATEMENT_AST, $1); }
  | cond_stmt       { $$ = build_node1(STATEMENT_AST, $1); }
  | func_call       { $$ = build_node1(STATEMENT_AST, $1); }
  | break_stmt      { $$ = build_node1(STATEMENT_AST, $1); }
;

break_stmt
  : BREAK SEMIC { $$ = build_node1(BREAK_STMT_AST, build_node0(BREAK_AST));}
;

assignment
  : IDENT ASSIGN expression {
    $$ = build_node2(ASSIGNMENT_AST, build_node0(IDENT_AST), $3);
  }
  | array ASSIGN expression  {
    $$ = build_node2(ASSIGNMENT_AST, $1, $3);
  }
  | unary_factor { $$ = build_node1(ASSIGNMENT_AST, $1); }// ex4
  | IDENT ASSIGN CHAR {}
  | IDENT ASSIGN STRING {}
;

assignment_stmt
  : assignment SEMIC { $$ = build_node1(ASSIGNMENT_STMT_AST, $1); }
;

expression
  : add_op 
  | sub_op
  | term                   
;

expressions
  : expressions COMMA expression 
  | expression                   
;

term
  : mul_op
  | div_op
  | rem_op
  | term bit_op factor { $$ = build_node3(TERM_AST, $1, $2, $3); }
  | factor             
;

unary_factor
  : IDENT unary_op { $$ = build_node2(UNARY_FACTOR_AST, build_node0(IDENT_AST), $2); } // ex4 
  | unary_op IDENT { $$ = build_node2(UNARY_FACTOR_AST, $1, build_node0(IDENT_AST)); } // ex4 
;

factor
  : var                         
  | unary_factor                { $$ = build_node1(FACTOR_AST, $1); }
  | NOT IDENT                   { $$ = build_node1(FACTOR_AST, build_node0(IDENT_AST)); }
  | L_PARAN expression R_PARAN  
; 


add_op
  : expression ADD term { $$ = build_node2(ADD_AST, $1, $3); }
;

sub_op
  : expression SUB term { $$ = build_node2(SUB_AST, $1, $3); }
;

mul_op
  : term MUL factor { $$ = build_node2(MUL_AST, $1, $3); }
;

div_op
  : term DIV factor { $$ = build_node2(DIV_AST, $1, $3); }
;

rem_op
  : term REM factor { $$ = build_node2(REM_AST, $1, $3); }
;

// ex4
unary_op
  : INCREM { $$ = build_node1(UNARY_OP_AST, build_node0(INCREM_AST));}
  | DECREM { $$ = build_node1(UNARY_OP_AST, build_node0(DECREM_AST));}
;

// ex4 
bit_op
  : AND     { $$ = build_node1(BIT_OP_AST, build_node0(AND_AST));}
  | OR      { $$ = build_node1(BIT_OP_AST, build_node0(OR_AST));}
  | XOR     { $$ = build_node1(BIT_OP_AST, build_node0(XOR_AST));}
  | L_SHIFT { $$ = build_node1(BIT_OP_AST, build_node0(L_SHIFT_AST));}
  | R_SHIFT { $$ = build_node1(BIT_OP_AST, build_node0(R_SHIFT_AST));}
;

var
  : IDENT                       { $$ = build_node0(IDENT_AST);}
  | NUMBER                      { $$ = build_node0(NUMBER_AST); }
  | FLOAT                       { $$ = build_node0(FLOAT_AST); } // ex6
  | IDENT array_index           { $$ = build_node2(ARRAY_AST, build_node0(IDENT_AST), $2); }
;

loop_stmt
  : while_stmt
  | for_stmt
;

while_stmt
  : WHILE L_PARAN condition R_PARAN L_BRACE statements R_BRACE {
    $$ = build_node2(WHILE_STMT_AST, $3, $6);
  }
;

for_stmt
  : FOR L_PARAN assignment SEMIC condition SEMIC assignment R_PARAN L_BRACE statements R_BRACE {
    $$ = build_node4(FOR_STMT_AST, $3, $5, $7, $10);
  } // ex5
  | FOR L_PARAN SEMIC SEMIC R_PARAN L_BRACE statements R_BRACE {
    $$ = build_node1(FOR_STMT_AST, $7);
  } // ex5
;

cond_stmt
  : if_stmt
  | elif_stmt
;

if_stmt
  : IF L_PARAN condition R_PARAN L_BRACE statements R_BRACE { 
    $$ = build_node2(COND_STMT_AST, $3, $6);
  }
;

elif_stmt
  : IF L_PARAN condition R_PARAN L_BRACE statements R_BRACE ELSE L_BRACE statements R_BRACE { 
    $$ = build_node3(COND_STMT_AST, $3, $6, $10);
  }
;

condition
  : eq_op
  | ne_op
  | lt_op
  | gt_op
  | lte_op
  | gte_op
;

eq_op
  : expression EQ expression { $$ = build_node2(EQ_AST, $1, $3); }
;

ne_op
  : expression NE expression { $$ = build_node2(NE_AST, $1, $3); }
;

lt_op
  : expression LT expression { $$ = build_node2(LT_AST, $1, $3); }
;

gt_op
  : expression GT expression { $$ = build_node2(GT_AST, $1, $3); }
;

lte_op
  : expression LTE expression { $$ = build_node2(LTE_AST, $1, $3); }
;

gte_op
  : expression GTE expression { $$ = build_node2(GTE_AST, $1, $3); }
;

idents
  : IDENT COMMA idents { 
    $$ = build_node2(IDENTS_AST, build_node0(IDENT_AST), $3); 
  }
  | IDENT              { $$ = build_node1(IDENTS_AST, build_node0(IDENT_AST)); }
;

%%
