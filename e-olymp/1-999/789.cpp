// (c) Tivole

// 789

#include<cstdio>

using namespace std;

int main() {
	int n, m, num;
	while (scanf("%d", &n) == 1) {
		while (n--) {
			scanf("%d", &m);
			int t = 0, flag = 0;
			while (m--) {
				scanf("%d", &num);
				if (num > 1) flag = 1;
				t ^= num;
			}
			if (flag) {
				if (t) printf("John\n");
				else puts("Brother");
			}
			else {
				if (t == 1) printf("Brother\n");
				else printf("John\n");
			}
		}
	}
	return 0;
}