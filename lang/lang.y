%{
 #include <stdio.h>
 #include "lang.tab.h"
 extern int yylex();
 extern int yyerror();

  int assign_count = 0, define_count = 0;
%}

%union {
  char* var;
  int   value;
}

%token DEFINE ASSIGN ARRAY 
       L_BRACKET R_BRACKET L_PARAN R_PARAN L_BRACE R_BRACE
       SEMIC COMMA ADD SUB MUL DIV REM INCREM DECREM EQ NE LT GT LTE GTE
       AND OR XOR NOT L_SHIFT R_SHIFT
       FUNCDECL FUNCCALL
       WHILE IF ELSE <var>IDENT <value>NUMBER 

%define parse.error verbose

%%

program
  : declarations statements { printf("[PROGRAM]\n"); }
;

declarations
  : decl_statement declarations 
  | decl_statement                           

// ex2
array_part
  : L_BRACKET expression R_BRACKET  // ex1
;

decl_part
  : DEFINE idents {
    printf("[DEFINE] \n");
    define_count++;
  }
  | ARRAY IDENT array_part {
    printf("[DEFINE] (array1) \n");
    define_count++;
  }
  | ARRAY IDENT array_part array_part { //ex2
    printf("[DEFINE] (array2)\n");
    define_count++;
  }
;

fun_arg_part
  : DEFINE IDENT {
    printf("[DEFINE] \n");
    define_count++;
  }
  | ARRAY IDENT array_part {
    printf("[DEFINE] (array1) \n");
    define_count++;
  }
  | ARRAY IDENT array_part array_part { //ex2
    printf("[DEFINE] (array2)\n");
    define_count++;
  }
;

decl_statement
  : decl_part SEMIC
  | func_define
;

func_var_decl
  : decl_part
  | decl_part COMMA func_var_decl
;

func_define
  : FUNCDECL IDENT L_PARAN func_var_decl R_PARAN L_BRACE declarations statements R_BRACE { 
    printf("[FUNC DECLARATION]\n"); 
  }
  | FUNCDECL IDENT L_PARAN R_PARAN L_BRACE declarations statements R_BRACE { 
    printf("[FUNC DECLARATION]\n"); 
  }
;

statements
  : statement statements
  | statement
;

statement
  : assignment_stmt
  | loop_stmt       
  | cond_stmt       
;

assignment_stmt
  : IDENT ASSIGN expression SEMIC {
    printf("[ASSIGN] \n");
    assign_count++;
  }
  | IDENT array_part ASSIGN expression SEMIC {
    printf("[ASSIGN] (array1)\n");
    assign_count++;
  }
  | IDENT array_part array_part ASSIGN expression SEMIC { //ex2
    printf("[ASSIGN] (array2)\n");
    assign_count++;
  }
  | unary_factor SEMIC // ex4
;

expression
  : expression add_op term 
  | term                  
;

term
  : term mul_op factor
  | term bit_op factor
  | factor
;

unary_factor
  : IDENT unary_op // ex4 
  | unary_op IDENT // ex4 
;

factor
  : var 
  | unary_factor
  | NOT IDENT
  | L_PARAN expression R_PARAN
; 

add_op
  : ADD
  | SUB
;

mul_op
  : MUL
  | DIV
  | REM // ex4
;

// ex4
unary_op
  : INCREM
  | DECREM
;

// ex4 
bit_op
  : AND
  | OR
  | XOR
  | L_SHIFT
  | R_SHIFT
;

var
  : IDENT
  | NUMBER
  | IDENT array_part
  | IDENT array_part array_part
;

loop_stmt
  : WHILE L_PARAN condition R_PARAN L_BRACE statements R_BRACE {
    printf("> [LOOP]\n");
  }
;

cond_stmt
  : IF L_PARAN condition R_PARAN L_BRACE statements R_BRACE { 
    printf("> [IF]\n"); 
  }
  | IF L_PARAN condition R_PARAN L_BRACE statements R_BRACE ELSE L_BRACE statements R_BRACE { 
    printf("> [IF ELSE]\n"); 
  }
;

condition
  : expression cond_op expression
;

cond_op
  : EQ
  | NE
  | LT
  | GT
  | LTE
  | GTE
;

idents
  : IDENT COMMA idents
  | IDENT
;

%%

int main(void) {
  if (yyparse()) {
    fprintf(stderr, "Error!\n");
    return 1;
  }
  printf("assign: %d, define: %d\n", assign_count, define_count);
  return 0;
}