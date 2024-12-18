%{
  #include <stdio.h>
  #include "lang.tab.h"
  #include "ast.h"
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
           condition array array_part term factor unary_factor cond_op unary_op bit_op mul_op add_op var idents

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
array_part
  : L_BRACKET expression R_BRACKET { $$ = build_node1(ARRAY_PART_AST, $2); } // ex1
;

array
  : IDENT array_part            { $$ = build_node2(ARRAY_AST, build_node0(IDENT_AST), $2); }
  | IDENT array_part array_part { $$ = build_node3(ARRAY_AST, build_node0(IDENT_AST), $2, $3); }
;

decl_part
  : DEFINE idents {
    // define_count++;
    // printf("[DEFINE]<%d> \n", define_count);
    // $$ = build_node2(DECL_PART_AST, build_node0(DEFINE_AST), $2);
    $$ = build_node1(DECL_PART_AST, $2);
  }
  | ARRAY_DEF array {
    // define_count++;
    // printf("[DEFINE]<%d> (array) \n", define_count);
    // $$ = build_node2(DECL_PART_AST, build_node0(ARRAY_AST), $2);
    $$ = build_node1(DECL_PART_AST, $2);
  }
;

func_arg_part
  : DEFINE IDENT {
    // define_count++;
    // printf("[DEFINE]<%d> \n", define_count);
    // $$ = build_node2(FUNC_ARG_PART_AST, build_node0(DEFINE_AST), build_node0(IDENT_AST));
    $$ = build_node1(FUNC_ARG_PART_AST, build_node0(IDENT_AST));
  }
  | ARRAY_DEF array {
    // define_count++;
    // printf("[DEFINE]<%d> (array) \n", define_count);
    // $$ = build_node2(FUNC_ARG_PART_AST, build_node0(ARRAY_DEF_AST), $2);
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
    // printf("[FUNC DECLARATION]\n"); 
    $$ = build_node4(FUNC_DEFINE_AST, build_node0(IDENT_AST), $4, $7, $8);
  }
  | FUNCDECL IDENT L_PARAN R_PARAN L_BRACE declarations statements R_BRACE { 
    // printf("[FUNC DECLARATION]\n"); 
    $$ = build_node3(FUNC_DEFINE_AST, build_node0(IDENT_AST), $6, $7);
  }
;

func_call
  : FUNCCALL IDENT L_PARAN expressions R_PARAN SEMIC {
    // printf("[FUNC CALL]\n");
    $$ = build_node2(FUNC_CALL_AST, build_node0(IDENT_AST), $4);
  }
  | FUNCCALL IDENT L_PARAN  R_PARAN SEMIC {
    // printf("[FUNC CALL]\n");
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
    // assign_count++;
    // printf("[ASSIGN]<%d>\n", assign_count);
    $$ = build_node2(ASSIGNMENT_AST, build_node0(IDENT_AST), $3);
    // $$ = build_node3(ASSIGNMENT_AST, build_node0(IDENT_AST), build_node0(ASSIGN_AST), $3);
  }
  | array ASSIGN expression  {
    // assign_count++;
    // printf("[ASSIGN]<%d> (array)\n", assign_count);
    $$ = build_node2(ASSIGNMENT_AST, $1, $3);
    // $$ = build_node3(ASSIGNMENT_AST, $1, build_node0(ASSIGN_AST), $3);
  }
  | unary_factor { $$ = build_node1(ASSIGNMENT_AST, $1); }// ex4
  | IDENT ASSIGN CHAR {
    // assign_count++;
    // printf("[ASSIGN]<%d> (char)\n", assign_count);
  }
  | IDENT ASSIGN STRING {
    // assign_count++;
    // printf("[ASSIGN]<%d> (str)\n", assign_count);
  }
;

assignment_stmt
  : assignment SEMIC { $$ = build_node1(ASSIGNMENT_STMT_AST, $1); }
;

expression
  : expression add_op term { $$ = build_node3(EXPRESSION_AST, $1, $2, $3); }
  | term                   { $$ = build_node1(EXPRESSION_AST, $1); }
;

expressions
  : expressions COMMA expression { $$ = build_node2(EXPRESSIONS_AST, $1, $3); }
  | expression                   { $$ = build_node1(EXPRESSIONS_AST, $1); }
;

term
  : term mul_op factor { $$ = build_node3(TERM_AST, $1, $2 ,$3); }
  | term bit_op factor { $$ = build_node3(TERM_AST, $1, $2, $3); }
  | factor             { $$ = build_node1(TERM_AST, $1); }
;

unary_factor
  : IDENT unary_op { $$ = build_node2(UNARY_FACTOR_AST, build_node0(IDENT_AST), $2); } // ex4 
  | unary_op IDENT { $$ = build_node2(UNARY_FACTOR_AST, $1, build_node0(IDENT_AST)); } // ex4 
;

factor
  : var                         { $$ = build_node1(FACTOR_AST, $1); }
  | unary_factor                { $$ = build_node1(FACTOR_AST, $1); }
  | NOT IDENT                   { $$ = build_node1(FACTOR_AST, build_node0(IDENT_AST)); }
  | L_PARAN expression R_PARAN  { $$ = build_node1(FACTOR_AST, $2); }
; 

add_op
  : ADD { $$ = build_node1(ADD_OP_AST, build_node0(ADD_AST)); }
  | SUB { $$ = build_node1(ADD_OP_AST, build_node0(SUB_AST)); }
;

mul_op
  : MUL { $$ = build_node1(MUL_OP_AST, build_node0(MUL_AST));}
  | DIV { $$ = build_node1(MUL_OP_AST, build_node0(DIV_AST));}
  | REM { $$ = build_node1(MUL_OP_AST, build_node0(REM_AST));}// ex4
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
  : IDENT                       { $$ = build_node1(VAR_AST, build_node0(IDENT_AST));}
  | NUMBER                      { $$ = build_node1(VAR_AST, build_node0(NUMBER_AST)); }
  | FLOAT                       { $$ = build_node1(VAR_AST, build_node0(FLOAT_AST)); } // ex6
  | IDENT array_part            { $$ = build_node2(VAR_AST, build_node0(IDENT_AST), $2); }
  | IDENT array_part array_part { $$ = build_node3(VAR_AST, build_node0(IDENT_AST), $2, $3); }
;

loop_stmt
  : WHILE L_PARAN condition R_PARAN L_BRACE statements R_BRACE {
    // printf("> [LOOP]\n");
    $$ = build_node2(LOOP_STMT_AST, $3, $6);
  }
  | FOR L_PARAN assignment SEMIC condition SEMIC assignment R_PARAN L_BRACE statements R_BRACE {
    // printf("> [LOOP]\n");
    $$ = build_node4(LOOP_STMT_AST, $3, $5, $7, $10);
  } // ex5
  | FOR L_PARAN SEMIC SEMIC R_PARAN L_BRACE statements R_BRACE {
    // printf("> [LOOP]\n");
    $$ = build_node1(LOOP_STMT_AST, $7);
  } // ex5
;

cond_stmt
  : IF L_PARAN condition R_PARAN L_BRACE statements R_BRACE { 
    // printf("> [IF]\n"); 
    $$ = build_node2(COND_STMT_AST, $3, $6);
  }
  | IF L_PARAN condition R_PARAN L_BRACE statements R_BRACE ELSE L_BRACE statements R_BRACE { 
    // printf("> [IF ELSE]\n"); 
    $$ = build_node3(COND_STMT_AST, $3, $6, $10);
  }
;

condition
  : expression cond_op expression { $$ = build_node3(CONDITION_AST, $1, $2, $3); }
;

cond_op
  : EQ  { $$ = build_node1(COND_OP_AST, build_node0(EQ_AST));}
  | NE  { $$ = build_node1(COND_OP_AST, build_node0(NE_AST));}
  | LT  { $$ = build_node1(COND_OP_AST, build_node0(LT_AST));}
  | GT  { $$ = build_node1(COND_OP_AST, build_node0(GT_AST));}
  | LTE { $$ = build_node1(COND_OP_AST, build_node0(LTE_AST));}
  | GTE { $$ = build_node1(COND_OP_AST, build_node0(GTE_AST));}
;

idents
  : IDENT COMMA idents { $$ = build_node2(IDENTS_AST, build_node0(IDENT_AST), $3); }
  | IDENT              { $$ = build_node1(IDENTS_AST, build_node0(IDENT_AST)); }
;

%%
