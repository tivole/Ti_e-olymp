// (c) Tivole

// 8600

#include <stdio.h>

int main(void) {

  int n;
  scanf("%d", &n);

  printf("%d %d\n", (n/10 + n%10), ((n/10)*(n%10)));

  return 0;
}