// (c) Tivole

// 576

#include <iostream>

using namespace std;

int main() {
	int sum = 0, tmp;
	for (int i = 0; i < 31; i++) {
		cin >> tmp;
		sum += tmp;
	}
	cout << sum / 27 << endl;
}