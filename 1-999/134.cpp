// (c) Tivole

// 134

#include <iostream>

using namespace std;

int main() {
	int r1, r2, ans = 0;
	pair<int, int> o1, o2;
	o1 = o2 = make_pair(0, 0);
	cin >> o1.first >> o1.second >> r1 >> o2.first >> o2.second >> r2;
	for (int x = -300; x < 300; x = x + 1)
		for (int y = -300; y < 300; y = y + 1)
			if ((o1.first - x)*(o1.first - x) + (o1.second - y)*(o1.second - y) <= r1*r1 || 
				(o2.first - x)*(o2.first - x) + (o2.second - y)*(o2.second - y) <= r2*r2) ans++;

	cout << ans << endl;
}