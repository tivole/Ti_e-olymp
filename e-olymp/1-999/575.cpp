// (c) Tivole

// 575

#include <iostream>

using namespace std;

int main() {
	int n; cin >> n;
	switch (n) {
	case 1: cout << 1 << endl; break;
	case 2: cout << 2 << endl; break;
	default: cout << 3 * (n - 2) << endl; break;
	}
}