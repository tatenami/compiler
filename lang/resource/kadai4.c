#include <stdio.h>

int main() {
int N, i, j, k;
int a[1001];
N = 1000;
i = 1;

while (i <= N) {
 a[i] = 1;
 i = i + 1;
}

i = 2;
while(i <= N/2) {
 j = 2;
 while(j <= N/i){
  k = i * j;
  a[k] = 0;
  j = j + 1;
 }
  i = i + 1;
}

a[0] = 0;
for (int i = 0; i < 100; i++) {
  if (i % 4 == 0) {
    printf("\n");
  }
  printf("%d ", a[i]);
}

return 0;
}
