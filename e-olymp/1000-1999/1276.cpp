// (c) Tivole

// 1276

#include<cstdio>
#include<algorithm>

using namespace std;

const double PI = 3.141;
const double eps = 1e-8;

int sgn(double x) {
	return (x > eps) - (x < -eps);
}

struct Point {
	double x, y;
	bool operator < (const Point _p) const {
		return x < _p.x;
	}
} p[1005], c1, c2;

double T;

int main()
{
	int n, kase = 1;
	while (scanf("%d", &n) == 1) {
		if (n == 0) break;
		scanf("%lf%lf%lf%lf%lf", &c1.x, &c1.y, &c2.x, &c2.y, &T);
		T /= PI;
		double x, y;
		for (int i = 1; i <= n; i++) {
			scanf("%lf%lf", &x, &y);
			p[i].x = (x - c1.x)*(x - c1.x) + (y - c1.y)*(y - c1.y);
			p[i].y = (x - c2.x)*(x - c2.x) + (y - c2.y)*(y - c2.y);
		}
		sort(p + 1, p + n + 1);
		int cur, ans = 0;
		p[0].x = 0;
		for (int i = 0; i <= n; i++) {
			x = p[i].x;
			y = T - x;
			if (sgn(y) < 0) break;
			cur = i;
			for (int j = i + 1; j <= n; j++) if (sgn(y - p[j].y) >= 0) cur++;
			if (cur > ans) ans = cur;
		}
		printf("%d. %d\n", kase++, n - ans);
	}
	return 0;
}