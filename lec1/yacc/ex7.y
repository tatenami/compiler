%{
 #include <stdio.h>
 #include "ex7.tab.h"
 extern int yylex();
 extern int yyerror();
%}

%union {
  char* var;
  int   value;
}

%token DEFINE ASSIGN <var>IDENT <value>NUMBER COMMA SEMIC

%%
statement
 : DEFINE idents SEMIC {
    printf("ALL OK!\n");
 }
;

idents
  : IDENT COMMA idents
  | assign COMMA idents 
  | IDENT
  | assign
;

assign
  : IDENT ASSIGN NUMBER {
    printf("OK! ident=%s, num=%d\n", $1, $3);
  }
;

%%

int main(void) {
  if (yyparse()) {
    fprintf(stderr, "Error!\n");
    return 1;
  }
  return 0;
}