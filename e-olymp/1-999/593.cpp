// (c) Tivole

// 593

#include <iostream>

using namespace std;

int main() {
	int n, m, i, j; cin >> n >> m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			if ((i + j) % 2 == n % 2) cout << 'X';
			else cout << '.';
			cout << endl;
	}
}