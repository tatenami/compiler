%{
  #include "ex7.tab.h"
%}

%%

define {
  return DEFINE;
}

= {
  return ASSIGN;
}

[a-zA-Z][a-zA-Z0-9]* {
  yylval.var = (char*)malloc(sizeof(char) * yyleng);
  strncpy(yylval.var, yytext, yyleng);
  return IDENT;
}

, {
  return COMMA;
}

; {
  return SEMIC;
}

[0-9]+ {
  yylval.value = atoi(yytext); 
  return NUMBER;
}

[ \t]+

\n {
  return 0;
}

. {
  return yytext[0];
}

%%