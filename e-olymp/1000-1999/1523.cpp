// (c) Tivole

// 1523

#include <iostream>
#include <math.h>

int main(void) {
	double m0, x, a[101][101], s[101];
	int i, j, n;

	while (scanf("%lf %d", &m0, &n) == 2){
		for (i = 0; i < n; i++) scanf("%lf", &s[i]);

		for (i = 0; i <= n; i++) a[n][i] = 0;

		for (i = n - 1; i >= 0; i--) {
			for (j = 0; j <= i; j++){
				x = sqrt((m0 - j) * s[i] / (10 + s[i] / 10 + a[i + 1][j + 1] - a[i + 1][j]));
				if (x > m0 - j) x = m0 - j;
				a[i][j] = x  * (s[i] / (2 * x) + 10 + s[i] / 10 + a[i + 1][j + 1]) / (m0 - j) + (1 - x / (m0 - j)) * (s[i] / x + a[i + 1][j]);
			}
		}

		printf("%.4lf\n", a[0][0]);
	}

	return 0;
}