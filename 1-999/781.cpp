// (c) Tivole

// 781

#include <cstdio>

int main(void){
	
	int n, x;
	while(scanf("%d%d", &n, &x) && n){
		int num[101];
		
		bool dp[10001] = { true };
		for(int i=1; i<=n; i++){
			int n1, n2;
			scanf("%d.%d", &n1, &n2);
			num[i]=n1*100+n2;
			if(i==x) continue;
			for(int w=10000; w>=num[i]; w--){
				dp[w] |= dp[w-num[i]];
			}
		}
		
		int sum=0;
			for(int w=10000; w>=num[x]&&w>5000; w--){
				if(dp[w-num[x]]) sum=w;
			}
		
		printf("%.2lf\n", num[x]/(double)sum*100.0);
	}
	
	return 0;
}