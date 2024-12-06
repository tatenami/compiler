%{
  #include "lang2.tab.h"
%}

%%

  /* DEFINE */
"define" { return DEFINE; }

  /* ASSIGN */
"=" { return ASSIGN; }
  /* ARRAY */
"array" { return ARRAY_DEF; }

  /* L_BRACKET */
"[" { return L_BRACKET; }

  /* R_BRACKET */
"]" { return R_BRACKET; }

  /* L_PARAN */
"(" { return L_PARAN; }

  /* R_PARAN */
")" { return R_PARAN; }

  /* L_BRACE */
"{" { return L_BRACE; }

  /* R_BRACE */
"}" { return R_BRACE; }

  /* SEMIC */
";" { return SEMIC; }

  /* COMMA */
"," { return COMMA; }

  /* ADD */
"+" { return ADD; }

  /* SUB */
"-" { return SUB; }

  /* MUL */
"*" { return MUL; }

  /* DIV */
"/" { return DIV; }

  /* REM */
"%" { return REM; }

  /* INCREM */
"++" { return INCREM; }

  /* DECREM */
"--" { return DECREM; }

  /* EQ */
"==" { return EQ; }

  /* NE */
"!=" { return NE; }

  /* LT */
"<" { return LT; }

  /* GT */
">" { return GT; }

  /* LET */
"<=" { return LTE; }

  /* GET */
">=" { return GTE; }

  /* AND */
"&" { return AND; }

  /* OR */
"|" { return OR; }

  /* XOR */
"^" { return XOR; }

  /* NOT */
"~" { return NOT; }

  /* L_SHIFT */
"<<" { return L_SHIFT; }

  /* R_SHIFT */
">>" { return R_SHIFT; }

  /* FOR */
"for" { return FOR; }

  /* WHILE */
"while" { return WHILE; }

  /* IF */
"if" { return IF; }

  /* ELSE */
"else" { return ELSE; }

  /* FUNC */
"func" { return FUNCDECL; }

  /* FUNCCALL */
"funccall" { return FUNCCALL; }

  /* BREAK */
"break" { return BREAK; }

  /* IDENT */
[a-zA-Z][a-zA-Z0-9]* {
  yylval.var = (char*)malloc(sizeof(char) * yyleng);
  strncpy(yylval.var, yytext, yyleng);
  return IDENT;
}

  /* NUMBER */
[0-9]+ {
  yylval.ival = atoi(yytext); 
  return NUMBER;
}

  /* char */
\'[0-9a-zA-Z !"#$%&'()\*\+\-\.,\/:;<=>?@\[\\\]^_`{|}~]\' {
  yylval.chara = yytext[0];
  return CHAR;
}

  /* str */
\"[0-9a-zA-Z !"#$%&'()\*\+\-\.,\/:;<=>?@\[\\\]^_`{|}~]+\" {
  yylval.var = (char*)malloc(sizeof(char) * yyleng);
  strncpy(yylval.var, yytext, yyleng);
  return STRING;
}

[0-9]+[.][0-9]+ {
  yylval.fval = atof(yytext); 
  return FLOAT;
}

[ \t]+
 
\n

%%