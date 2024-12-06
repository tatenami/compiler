#include "ast.h"

int main() {
  if (yyparse()) {
    fprintf(stderr, "Error!\n");
    return 1;
  }

  printf("[*] AST generation is completed\n");

  return 0;
}