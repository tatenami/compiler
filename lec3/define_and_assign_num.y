%{
    #include <stdio.h>
    #include "define_and_assign_num.tab.h"
    extern int yylex();
    extern int yyerror();
%}

%union{
    char* sp;
    int ival;
}

%token DEFINE COMMA ASSIGN <sp>IDENT <ival>NUMBER SEMIC

%%

statements
    :       statement statements
    |       statement
;
statement
    :       DEFINE idents SEMIC {printf("Define OK!\n");}
    |       IDENT ASSIGN NUMBER SEMIC {printf("OK! ident=%s, num=%d\n", $1, $3);}
;
idents
    :       IDENT COMMA idents {printf("OK! new ident=%s\n", $1);}
    |       IDENT              {printf("OK! new ident=%s\n", $1);}
;

%%

int main(void) {
    if (yyparse()) {
        fprintf(stderr, "Error!\n");
        return 1;
    }
    return 0;
}