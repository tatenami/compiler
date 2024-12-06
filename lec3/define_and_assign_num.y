%{
    #include <stdio.h>
    #include "define_and_assign_num.tab.h"
    #include "ast.h"
    extern int yylex();
    extern int yyerror();

    extern Node *top;
%}

%union{
    struct node *np;
    char* sp;
    int ival;
}

// 非終端記号に型を設定 節となる
%type <np> statements statement idents

%token DEFINE COMMA ASSIGN <sp>IDENT <ival>NUMBER SEMIC

%%
// 新たなノードを，左辺のシンボル値にする

statements
    :       statement statements { top = build_node2(STATEMENTS_AST, $1, top); }
    |       statement            { top = build_node1(STATEMENTS_AST, $1); }
;
statement
    :       DEFINE idents SEMIC       { $$ = build_node1(STATEMENT_AST, $2); }
    |       IDENT ASSIGN NUMBER SEMIC { $$ = build_node2(STATEMENT_AST, build_node0(IDENT_AST), build_node0(NUMBER_AST)); }
;
idents
    :       IDENT COMMA idents { $$ = build_node2(IDENTS_AST, build_node0(IDENT_AST), $3); }
    |       IDENT              { $$ = build_node1(IDENTS_AST, build_node0(IDENT_AST)); }
;

%%
