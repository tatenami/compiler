#include <stdio.h>

int main() {
  int i = 0;
  int * p = &i;
  printf("value: %d\n", * p);
  printf("pointer: %p\n", & i);
  return 0;
}