%{
 #include <stdio.h>
 #include "assign_num.tab.h"
 extern int yylex();
 extern int yyerror();
%}

%union {
  char* var;
  int   value;
}

%token ASSIGN <var>IDENT <value>NUMBER SEMIC

%%
statement
 : IDENT ASSIGN NUMBER SEMIC {
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