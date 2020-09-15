// (c) Tivole

// 1218

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<sstream>

#define max(a,b) a > b ? a : b

using namespace std;
int n, f[20], dp[16][1666], X[1666], Y[1666], num[1666], len, a[20];

void DFS(int k, int t, int c){
	if (c == t) {
		int u = 0, v = 0;
		for (int i = 1; i <= t; ++i)
			if (a[i]){
				v |= 1 << (i - 1);
				u |= 1 << (i - 1);
				u |= 1 << i;
				if (i > 1) u |= 1 << (i - 2);
			}
		X[len] = u, Y[len] = v; ++len;
		return;
	}
	for (int i = 0; i < 2; ++i){
		if (i &&a [k - 1]) continue;
		a[k] = i;
		DFS(k + 1, t, c + 1);
	}
}

int work(int x){
	int ret = 0, i = 1;
	while (x){
		if (x & 1) ret += f[i];
		x >>= 1; ++i;
	}
	return ret;
}

void Init(char* ch){
	char x[10];
	stringstream in(ch);
	n = len = 0;
	while (in >> x) f[++n] = atoi(x);
	DFS(1, n, 0);
	memset(dp, 0, sizeof(dp));
	for (int j = 0; j < len; ++j) dp[1][j] = work(Y[j]);
}

int main(){
	char ch[150];
	while (gets(ch) != NULL){
		Init(ch);
		int ans = 0;
		for (int i = 2; i <= n; ++i){
			for (int j = 1; j <= n; ++j) scanf("%d", f + j);
			for (int j = 0; j < len; ++j) num[j] = work(Y[j]);
			for (int j = 0; j < len; ++j)
				for (int k = 0; k < len; ++k)
					if (!(Y[j] & X[k])) {
						dp[i][j] = max(dp[i][j], dp[i - 1][k] + num[j]);
						ans = max(dp[i][j], ans);
					}
		}
		printf("%d\n", ans);
		getchar();
		getchar();
	}
}