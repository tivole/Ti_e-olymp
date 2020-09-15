// (c) Tivole

// 1272

#include <iostream>

using namespace std;

long gcd(long a, long b){
	return b > 0 ? gcd(b, a%b) : a;
}

int main(){
	long x, y;
	while (cin >> x >> y && (x || y)){
		long GCD = gcd(x, y);
		cout << x*y / (GCD*GCD) << endl;
	}
	return 0;
}