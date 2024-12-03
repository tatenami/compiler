%{
 #include <stdio.h>
 #include "lang.tab.h"
 extern int yylex();
 extern int yyerror();

  int assign_count = 0, define_count = 0;
%}

%union {
  char* var;
  char  chara;
  char* str;
  int   ival;
  float fval;
}

%token DEFINE ASSIGN ARRAY 
       L_BRACKET R_BRACKET L_PARAN R_PARAN L_BRACE R_BRACE
       SEMIC COMMA ADD SUB MUL DIV REM INCREM DECREM EQ NE LT GT LTE GTE
       AND OR XOR NOT L_SHIFT R_SHIFT
       FUNCDECL FUNCCALL BREAK
       FOR WHILE IF ELSE <var>IDENT <chara>CHAR <str>STRING <ival>NUMBER <fval>FLOAT

%define parse.error verbose

%%

program
  : declarations statements { printf("[PROGRAM]\n"); }
  | func_define             { printf("[PROGRAM]\n"); }
;

declarations
  : decl_statement declarations 
  | decl_statement                           

// ex2
array_part
  : L_BRACKET expression R_BRACKET  // ex1
;

array
  : IDENT array_part
  | IDENT array_part array_part
;

decl_part
  : DEFINE idents {
    define_count++;
    printf("[DEFINE]<%d> \n", define_count);
  }
  | ARRAY array {
    define_count++;
    printf("[DEFINE]<%d> (array) \n", define_count);
  }
;

func_arg_part
  : DEFINE IDENT {
    define_count++;
    printf("[DEFINE]<%d> \n", define_count);
  }
  | ARRAY array {
    define_count++;
    printf("[DEFINE]<%d> (array) \n", define_count);
  }
;

decl_statement
  : decl_part SEMIC
  | func_define
;

/* ex3 */
func_var_decl
  : func_arg_part
  | func_arg_part COMMA func_var_decl
;

func_define
  : FUNCDECL IDENT L_PARAN func_var_decl R_PARAN L_BRACE declarations statements R_BRACE { 
    printf("[FUNC DECLARATION]\n"); 
  }
  | FUNCDECL IDENT L_PARAN R_PARAN L_BRACE declarations statements R_BRACE { 
    printf("[FUNC DECLARATION]\n"); 
  }
;

func_call
  : FUNCCALL IDENT L_PARAN expressions R_PARAN SEMIC {
    printf("[FUNC CALL]\n");
  }
  | FUNCCALL IDENT L_PARAN  R_PARAN SEMIC {
    printf("[FUNC CALL]\n");
  }
;

/* ex3 */

statements
  : statement statements
  | statement
;

statement
  : assignment_stmt
  | loop_stmt       
  | cond_stmt      
  | func_call 
  | BREAK SEMIC
;

assignment
  : IDENT ASSIGN expression {
    assign_count++;
    printf("[ASSIGN]<%d>\n", assign_count);
  }
  | array ASSIGN expression  {
    assign_count++;
    printf("[ASSIGN]<%d> (array)\n", assign_count);
  }
  | unary_factor // ex4
  | IDENT ASSIGN CHAR {
    assign_count++;
    printf("[ASSIGN]<%d> (char)\n", assign_count);
  }
  | IDENT ASSIGN STRING {
    assign_count++;
    printf("[ASSIGN]<%d> (str)\n", assign_count);
  }
;

assignment_stmt
  : assignment SEMIC
;

expression
  : expression add_op term 
  | term                  
;

expressions
  : expressions COMMA expression
  | expression
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
  | FLOAT // ex6
  | IDENT array_part
  | IDENT array_part array_part
;

loop_stmt
  : WHILE L_PARAN condition R_PARAN L_BRACE statements R_BRACE {
    printf("> [LOOP]\n");
  }
  | FOR L_PARAN assignment SEMIC condition SEMIC assignment R_PARAN L_BRACE statements R_BRACE {
    printf("> [LOOP]\n");
  } // ex5
  | FOR L_PARAN SEMIC SEMIC R_PARAN L_BRACE statements R_BRACE {
    printf("> [LOOP]\n");
  } // ex5
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
  printf("OK!\n");
  return 0;
}