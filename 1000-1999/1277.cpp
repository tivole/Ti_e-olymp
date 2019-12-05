// (c) Tivole

// 1277

#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 300;
bool dp[maxn][maxn];
int n, m, casen = 0;

int main(){
	while (scanf("%d%d", &n, &m) != EOF && (m || n)){
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++) dp[i][j] = false;

		for (int i = 0; i <= n; i++) dp[i][i] = true;
		int ans = 0, u, v;
		while (m--){
			scanf("%d%d", &u, &v);
			if (dp[v][u]) ans++;
			else
				if (!dp[u][v])
				{
					dp[u][v] = true;
					for (int i = 1; i <= n; i++)
					{
						if (!dp[i][u]) continue;
						dp[i][v] = true;
						for (int j = 1; j <= n; j++)
						{
							if (!dp[v][j]) continue;
							dp[i][j] = true;
							dp[u][j] = true;
						}
					}
				}
		}
		casen++;
		printf("%d. %d\n", casen, ans);
	}
	return 0;
}