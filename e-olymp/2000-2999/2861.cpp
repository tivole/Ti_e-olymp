// (c) Tivole

// 2861

#include <iostream>
using namespace std;

int main(){
	long a, b, sum;
	cin >> a >> b;
	if (a % 2 == 0) ++a;
	if (b % 2 == 0) --b;
	if (b < a) sum = 0;
	else sum = (a + b) / 2 * ((b - a) / 2 + 1);
	cout << sum << "\n";
	return 0;
}