// (c) Tivole

// 1279

#include <math.h>
#include <stdio.h>
#include <string>

const double eps = 1e-8;

using namespace std;

int dcmp(double x)
{
	if (x > eps) return 1;
	if (x < -eps)return -1;
	return 0;
}

int n, w, h, d, num[105];
double gass[105][105], mat[11][11], ans[105];

int Gauss()
{
	int i, j, k, r;
	double tmp;
	for (k = 0; k < n; k++)
	{
		i = k;
		while (i < n && !dcmp(gass[i][k]))i++;
		if (i > k)
			for (r = 0; r <= n; r++) swap(gass[k][r], gass[i][r]);
		for (i = 0; i < n; i++)
			if (i != k && dcmp(gass[i][k]))
			{
				tmp = gass[i][k] / gass[k][k];
				for (j = 0; j <= n; j++) gass[i][j] -= tmp * gass[k][j];
			}
	}
	for (i = 0; i < n; i++)
		if (dcmp(gass[i][n]))
		{
			for (j = 0; j < n && !dcmp(gass[i][j]); j++);
			if (j == n) return 0;
			ans[j] = gass[i][n] = gass[i][n] / gass[i][j];
		}
	return 1;
}

int main()
{
	int i, j, k = 0;
	while (scanf("%d%d%d", &w, &h, &d) && (w || h || d))
	{
		for (i = 0; i < h; i++)
			for (j = 0; j < w; j++) scanf("%lf", &mat[i][j]);

		n = w*h;
		for (i = 0; i < n; i++)
		{
			num[i] = 0;
			for (j = 0; j < n; j++)
			{
				int kx = j / w, mx = j % w;
				int ky = i / w, my = i % w;
				if (abs(ky - kx) + abs(my - mx) <= d)
				{
					gass[i][j] = 1.0;
					num[i]++;
				}
				else gass[i][j] = 0.0;
			}
		}
		for (i = 0; i < n; i++)
		{
			gass[i][n] = mat[i / w][i % w] * num[i] * 1.0;
		};
		Gauss();
		if (k != 0) printf("\n");
		for (i = 0; i < n; i++)
		{
			printf("%8.2lf", ans[i]);
			if ((i + 1) % w == 0) printf("\n");
			else printf("");
		}
		k++;
	}
	return 0;
}