%{
    #include "define_and_assign_num.tab.h"
%}

%%

define                  {return DEFINE;}
,                       {return COMMA;}
=                       {return ASSIGN;}
;                       {return SEMIC;}
[a-zA-Z][a-zA-Z0-9]*    {
                            yylval.sp = (char*)malloc(sizeof(char) * yyleng);
                            strncpy(yylval.sp, yytext, yyleng);
                            return IDENT;
                        }
[0-9]+                  { yylval.ival = atoi(yytext); return NUMBER; }
[ \t\n]+
.                       {return yytext[0];}
