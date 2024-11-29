
%%

[^ \t\n]+ {printf("Word: %s\n", yytext);}
[ \t\n]

%%

int main() {
  yylex();
  return 0;
}
