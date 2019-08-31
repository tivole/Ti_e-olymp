// (c) Tivole

// 1243

#include <iostream>

using namespace std;

long gcd(long a, long b)
{
	return b ? gcd(b, a % b) : a;
}

int main() {
	long ans, n, m, tmp; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m >> ans;
		for (int j = 1; j < m; j++) {
			cin >> tmp;
			ans = ans * tmp / gcd(ans, tmp);
		}
		cout << ans << endl;
	}
}