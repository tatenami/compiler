%{
  #include "lang.tab.h"
%}

%%

  /* DEFINE */
"define" {
  return DEFINE;
}

  /* ASSIGN */
"=" {
  return ASSIGN;
}
  /* ARRAY */
"array" {
  return ARRAY;
}

  /* L_BRACKET */
"[" {
  return L_BRACKET;
}

  /* R_BRACKET */
"]" {
  return R_BRACKET;
}

  /* L_PARAN */
"(" {
  return L_PARAN;
}

  /* R_PARAN */
")" {
  return R_PARAN;
}


  /* L_BRACE */
"{" {
  return L_BRACE;
}

  /* R_BRACE */
"}" {
  return R_BRACE;
}

  /* SEMIC */
";" {
  return SEMIC;
}

  /* COMMA */
"," {
  return COMMA;
}

  /* ADD */
"+" {
  return ADD;
}


  /* SUB */
"-" {
  return SUB;
}

  /* MUL */
"*" {
  return MUL;
}

  /* DIV */
"/" {
  return DIV;
}

  /*  */

  /* EQ */
"==" {
  return EQ;
}

  /* LT */
"<" {
  return LT;
}

  /* GT */
">" {
  return GT;
}

  /* WHILE */
"while" {
  return WHILE;
}

  /* IF */
"if" {
  return IF;
}

  /* ELSE */
"else" {
  return ELSE;
}

  /* IDENT */
[a-zA-Z][a-zA-Z0-9]* {
  yylval.var = (char*)malloc(sizeof(char) * yyleng);
  strncpy(yylval.var, yytext, yyleng);
  return IDENT;
}

  /* NUMBER */
[0-9]+ {
  yylval.value = atoi(yytext); 
  return NUMBER;
}

[ \t]+
 
\n

%%