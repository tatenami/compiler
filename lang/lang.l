%{
  #include "lang.tab.h"
%}

%%

"define" {
  return DEFINE;
}

= {
  return ASSIGN;
}

"array" {
  return ARRAY;
}

\[ {
  return L_BRACKET;
}

\] {
  return R_BRACKET;
}

\( {
  return L_PARAN;
}

\) {
  return R_PARAN;
}

\{ {
  return L_BRACE;
}

\} {
  return R_BRACE;
}

; {
  return SEMIC;
}

\+ {
  return ADD;
}

- {
  return SUB;
}

\* {
  return MUL;
}

\/ {
  return DIV;
}

== {
  return EQ;
}

\< {
  return LT;
}

\> {
  return GT;
}

while {
  return WHILE;
}

if {
  return IF;
}

else {
  return ELSE;
}

[a-zA-Z][a-zA-Z0-9]* {
  yylval.var = (char*)malloc(sizeof(char) * yyleng);
  strncpy(yylval.var, yytext, yyleng);
  return IDENT;
}

[0-9]+ {
  yylval.value = atoi(yytext); 
  return NUMBER;
}

[ \t]+
 
\n

%%