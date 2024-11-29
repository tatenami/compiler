%{
 #include <stdio.h>
 #include "lang.tab.h"
 extern int yylex();
 extern int yyerror();
%}

%union {
  char* var;
  int   value;
}

%token DEFINE ASSIGN ARRAY 
       L_BRACKET R_BRACKET L_PARAN R_PARAN L_BRACE R_BRACE
       SEMIC ADD SUB MUL DIV EQ LT GT
       WHILE IF ELSE <var>IDENT <value>NUMBER

%%

program
  : declarations statements { printf("[PROGRAM]\n"); }
;

declarations
  : decl_statement declarations { printf("[DECLARATIONS]\n"); }
  | decl_statement              
;

decl_statement
  : DEFINE IDENT SEMIC {
    printf("[DEFINE] ident = %s\n", $2);
  }
  | ARRAY IDENT L_BRACKET NUMBER R_BRACKET SEMIC {
    printf("[ARRAY] ident = %s, elem = %d\n", $2, $4);
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
  }
  | IDENT L_BRACKET NUMBER R_BRACKET ASSIGN expression SEMIC {
    printf("[ASSIGN] \n");
  }
;

expression
  : expression add_op term { printf("[EXPRESSION] \n"); }
  | term                   { printf("[EXPRESSION] \n"); } 
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
  | IDENT L_BRACKET NUMBER R_BRACKET
  | IDENT L_BRACKET var R_BRACKET // ex1
;

loop_stmt
  : WHILE L_PARAN condition R_PARAN L_BRACE statements R_BRACE {
    printf("[LOOP] \n");
  }
;

cond_stmt
  : IF L_PARAN condition R_PARAN L_BRACE statements R_BRACE { 
    printf("[IF] \n"); 
  }
  | IF L_PARAN condition R_PARAN L_BRACE statements R_BRACE ELSE L_BRACE statements R_BRACE { 
    printf("[IF ELSE] \n"); 
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

%%

int main(void) {
  if (yyparse()) {
    fprintf(stderr, "Error!\n");
    return 1;
  }
  return 0;
}