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
       SEMIC COMMA ADD SUB MUL DIV EQ LT GT
       WHILE IF ELSE <var>IDENT <value>NUMBER 

%%

program
  : declarations statements { printf("[PROGRAM]\n"); }
;

declarations
  : decl_statement declarations { printf("[DECLARATIONS]\n"); }
  | decl_statement              
;

array_part
  : L_BRACKET expression R_BRACKET  // ex1
;

decl_statement
  : DEFINE idents SEMIC {
    printf("[DEFINE] \n");
    define_count++;
  }
  | ARRAY IDENT array_part SEMIC {
    printf("[DEFINE] (array1) \n");
    define_count++;
  }
  | ARRAY IDENT array_part array_part SEMIC {
    printf("[DEFINE] (array2)\n");
    define_count++;
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
  | IDENT array_part array_part ASSIGN expression SEMIC {
    printf("[ASSIGN] (array2)\n");
    assign_count++;
  }
;

expression
  : expression add_op term 
  | term                  
;

term
  : term mul_op factor
  | factor
;

factor
  : var 
  | L_PARAN expression R_PARAN
; 

add_op
  : ADD
  | SUB
;

mul_op
  : MUL
  | DIV
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
  | LT
  | GT
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