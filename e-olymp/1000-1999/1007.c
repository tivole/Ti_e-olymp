// (c) Tivole

// 1007

#include <stdio.h>

int n, m;

void func(int a1, int b1, int a2, int b2){
	if (n < b1 + b2) return;
	if (m == a1 + a2 && n == b1 + b2) return;
	if (m * (b1 + b2) < n * (a1 + a2)) printf("L"), func(a1, b1, a1 + a2, b1 + b2);
	else printf("R"), func(a1 + a2, b1 + b2, a2, b2);
}

int main(void) {
	while (scanf("%d %d", &m, &n), !(m == 1 && n == 1)){
		func(0, 1, 1, 0);
		printf("\n");
	}

	return 0;
}