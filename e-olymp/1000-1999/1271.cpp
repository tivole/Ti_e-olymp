// (c) Tivole

// 1271

#include <cstdio>
#include <cstring>

using namespace std;
int main(){
	int l, i, k, cs = 1, a[3000];
	char a1[3000];
	while (gets(a1)){
		if (a1[0] == '-') break;
		l = strlen(a1);
		for (i = 0; i < l; i++){
			if (a1[i] == '{') a[i] = 1;
			else if (a1[i] == '}') a[i] = -1;
		}
		int sum = 0; k = 0;
		for (i = 0; i < l; i++){
			sum += a[i];
			if (sum < 0){
				sum = 1;
				k++;
			}
		}
		if (sum > 0) k += sum / 2;
		printf("%d. %d\n", cs++, k);
	}
	return 0;
}