// (c) Tivole

// 588

#include <stdio.h>
#include <math.h>

int main() {
	int a[3], i, n, p = 0, d = 0, t;
	scanf("%d", &n);
	if (n > 1) {
		scanf("%d%d", &a[0], &a[1]);
		d = fabs(a[1] - a[0]);
		for (i = 2; i < n; i++) {
			scanf("%d", &a[2]);
			if (fabs(a[1] - a[2]) + d < 3 * fabs(a[0] - a[2]) + p) {
				p = d;
				d += fabs(a[1] - a[2]);
			}
			else {
				t = d;
				d = 3 * fabs(a[0] - a[2]) + p;
				p = t;
			}
			a[0] = a[1];
			a[1] = a[2];
		}
	}
	printf("%d", d);
	return 0;
}