// (c) Tivole

// 606

#include <iostream>

using namespace std;

int main() {
	int n, ans = 0, x, y; cin >> n;
	for (int i = n; i < 9999; i++) {
		x = i, y = i + 1;
		while (x) {
			if (x % 10 != y % 10) ans++;
			x /= 10, y /= 10;
		}
	}
	cout << ans << endl;
}