%{
  int num_words = 0, num_chars = 0, num_lines;
%}

%%

[^ \t\n]+ {
  printf("Word: %s\n", yytext);
  num_chars += yyleng;
  num_words++;
}

\n {
  num_lines++;
}

[ \t\n]

%%

int main() {
  yylex();
  printf("#words=%d, #lines=%d, #chars=%d\n", num_words, num_lines, num_chars);
  return 0;
}