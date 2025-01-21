%{
  #include <stdio.h>
  #include "lang2.tab.h"
  #include "ast2.h"
  extern int yylex();
  extern char* yytext;

  int assign_count = 0, define_count = 0;
  extern Node *top;
%}

%union {
  struct node *np;
  char* sp;
  char  chara;
  char* str;
  int   ival;
  float fval;
}

%type <np> program declarations func_define decl_statement decl_part statements statement
           func_var_decl func_arg_part
           break_stmt assignment_stmt assignment loop_stmt cond_stmt func_call expressions expression 
           while_stmt if_stmt else_stmt elif_stmt for_stmt
           condition array array_index term factor unary_factor unary_op bit_op var idents
           comp_op str

%type <ival> add_op mul_op

%token DEFINE ASSIGN ARRAY_DEF 
       L_BRACKET R_BRACKET L_PARAN R_PARAN L_BRACE R_BRACE
       SEMIC COMMA ADD SUB MUL DIV REM INCREM DECREM EQ NE LT GT LTE GTE
       AND OR XOR NOT L_SHIFT R_SHIFT
       FUNCDECL FUNCCALL BREAK
       FOR WHILE IF ELSE <chara>CHAR <str>STRING <fval>FLOAT

%token <sp> IDENT
%token <ival> NUMBER

%define parse.error verbose

%%

program
  : declarations statements { top = build_node2(PROGRAM_AST, $1, $2); }
  | declarations            { top = build_node1(PROGRAM_AST, $1); }
;

declarations
  : decl_statement declarations { $$ = build_node2(DECLARATIONS_AST, $1, $2); }
  | decl_statement              { $$ = build_node1(DECLARATIONS_AST, $1); }

// ex2
array_index
  : L_BRACKET expression R_BRACKET { $$ = build_node1(ARRAY_INDEX_AST, $2); } // ex1
  | L_BRACKET expression R_BRACKET L_BRACKET expression R_BRACKET { $$ = build_node2(ARRAY_INDEX_AST, $2, $5); } // ex1
;

array
  : IDENT array_index { $$ = build_node2(ARRAY_AST, build_ident_node(IDENT_AST, $1), $2); }
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
    $$ = build_node1(FUNC_ARG_PART_AST, build_ident_node(IDENT_AST, $2));
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
  : func_arg_part                     { 
    $$ = build_node1(FUNC_VAR_DECL_AST, $1); 
  }
  | func_arg_part COMMA func_var_decl { 
    $$ = build_node2(FUNC_VAR_DECL_AST, $1, $3); 
  }
;



func_define
  : FUNCDECL IDENT L_PARAN func_var_decl R_PARAN L_BRACE declarations statements R_BRACE { 
    $$ = build_node4(FUNC_DEFINE_AST, build_ident_node(IDENT_AST, $2), $4, $7, $8);
  }
  | FUNCDECL IDENT L_PARAN R_PARAN L_BRACE declarations statements R_BRACE { 
    $$ = build_node3(FUNC_DEFINE_AST, build_ident_node(IDENT_AST, $2), $6, $7);
  }
;

func_call
  : FUNCCALL IDENT L_PARAN expressions R_PARAN SEMIC {
    $$ = build_node2(FUNC_CALL_AST, build_ident_node(IDENT_AST, $2), $4);
  }
  | FUNCCALL IDENT L_PARAN  R_PARAN SEMIC {
    $$ = build_node1(FUNC_CALL_AST, build_ident_node(IDENT_AST, $2));
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
    $$ = build_node2(ASSIGNMENT_AST, build_ident_node(IDENT_AST, $1), $3);
  }
  | array ASSIGN expression  {
    $$ = build_node2(ASSIGNMENT_AST, $1, $3);
  }
  | unary_factor { $$ = build_node1(ASSIGNMENT_AST, $1); }// ex4
  | IDENT ASSIGN str {
    $$ = build_node2(ASSIGNMENT_AST, build_ident_node(IDENT_AST, $1), $3);
  }
;

assignment_stmt
  : assignment SEMIC { $$ = $1; }
;

expressions
  : expression COMMA expressions { $$ = build_node2(EXPRESSIONS_AST, $1, $3); }
  | expression                   
;

expression
  : expression add_op term {
    if ($2 == OP_ADD) {
      $$ = build_node2(ADD_AST, $1, $3);
    }
    else if ($2 == OP_SUB) {
      $$ = build_node2(SUB_AST, $1, $3);
    }
  }
  | term                   
;

term
  : term mul_op factor {
    if ($2 == OP_MUL) {
      $$ = build_node2(MUL_AST, $1, $3);
    }
    else if ($2 == OP_DIV) {
      $$ = build_node2(DIV_AST, $1, $3);
    }
    else if ($2 == OP_REM) {
      $$ = build_node2(REM_AST, $1, $3);
    }
  }
  | term bit_op factor { 
    if ($2 == OP_AND) {
      $$ = build_node2(AND_AST, $1, $3);
    }
    else if ($2 == OP_OR) {
      $$ = build_node2(OR_AST, $1, $3);
    }
    else if ($2 == OP_XOR) {
      $$ = build_node2(XOR_AST, $1, $3);
    }
    else if ($2 == OP_L_SHIFT) {
      $$ = build_node2(L_SHIFT_AST, $1, $3);
    }
    else if ($2 == OP_R_SHIFT) {
      $$ = build_node2(R_SHIFT_AST, $1, $3);
    }
  }
  | factor             
;

unary_factor
  : IDENT unary_op { $$ = build_node2(UNARY_FACTOR_AST, build_ident_node(IDENT_AST, $1), $2); } // ex4 
  | unary_op IDENT { $$ = build_node2(UNARY_FACTOR_AST, $1, build_ident_node(IDENT_AST, $2)); } // ex4 
;

factor
  : var                         
  | L_PARAN expression R_PARAN  { $$ = $2; }                   
  | unary_factor                
  | NOT IDENT                   { $$ = build_node1(FACTOR_AST, build_ident_node(IDENT_AST, $2)); } 
; 


add_op
  : ADD { $$ = OP_ADD; }
  | SUB { $$ = OP_SUB; }
;

mul_op
  : MUL { $$ = OP_MUL; }
  | DIV { $$ = OP_DIV; }
  | REM { $$ = OP_REM; }

// ex4
unary_op
  : INCREM { $$ = build_node1(UNARY_OP_AST, build_node0(INCREM_AST));}
  | DECREM { $$ = build_node1(UNARY_OP_AST, build_node0(DECREM_AST));}
;

// ex4 
bit_op
  : AND     { $$ = OP_AND; }
  | OR      { $$ = OP_OR; }
  | XOR     { $$ = OP_XOR; }
  | L_SHIFT { $$ = OP_L_SHIFT; }
  | R_SHIFT { $$ = OP_R_SHIFT; }
;

var
  : IDENT                       { $$ = build_ident_node(IDENT_AST, $1);}
  | NUMBER                      { $$ = build_num_node(NUMBER_AST, $1); }
  | FLOAT                       { $$ = build_float_node(FLOAT_AST, $1); } // ex6
  | IDENT array_index           { $$ = build_node2(ARRAY_AST, build_node0(IDENT_AST), $2); }
;

str
  : STRING { $$ = build_str_node(STR_AST, $1); }
  | CHAR   { $$ = build_char_node(CHAR_AST, $1); }
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
  : if_stmt   // { $$ = build_node1(IF_AST, $1); }
  | elif_stmt // { $$ = build_node1(IF_AST, $1); }
;

if_stmt
  : IF L_PARAN condition R_PARAN L_BRACE statements R_BRACE { 
    $$ = build_node2(IF_STMT_AST, $3, $6);
  }
;

else_stmt
  : ELSE L_BRACE statements R_BRACE {
    $$ = build_node1(ELSE_STMT_AST, $3);
  }
;

elif_stmt
  : if_stmt else_stmt { 
    $$ = build_node2(ELIF_STMT_AST, $1, $2);
  }
;

condition
  : expression comp_op expression {
    if ($2 == OP_EQ) {
      $$ = build_node1(CONDITION_AST, build_node2(EQ_AST, $1, $3));
    }
    else if ($2 == OP_NE) {
      $$ = build_node1(CONDITION_AST, build_node2(NE_AST, $1, $3));
    }
    else if ($2 == OP_LT) {
      $$ = build_node1(CONDITION_AST, build_node2(LT_AST, $1, $3));
    }
    else if ($2 == OP_GT) {
      $$ = build_node1(CONDITION_AST, build_node2(LTE_AST, $1, $3));
    }
    else if ($2 == OP_LTE) {
      $$ = build_node1(CONDITION_AST, build_node2(LTE_AST, $1, $3));
    }
    else if ($2 == OP_GTE) {
      $$ = build_node1(CONDITION_AST, build_node2(GTE_AST, $1, $3));
    }
  }
;

comp_op
  : EQ  { $$ = OP_EQ; }
  | NE  { $$ = OP_NE; }
  | LT  { $$ = OP_LT; }
  | GT  { $$ = OP_GT; }
  | LTE { $$ = OP_LTE; }
  | GTE { $$ = OP_GTE; }
;

idents
  : IDENT COMMA idents { 
    $$ = build_node2(IDENTS_AST, build_ident_node(IDENT_AST, $1), $3); 
  }
  | IDENT              { $$ = build_node1(IDENTS_AST, build_ident_node(IDENT_AST, $1)); }
;

%%
