// (c) Tivole

// 1282

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int ans, n, dn[100][330], index[330];
vector <int> simple;

bool fsimple(int x)
{
	if (x < 2) return false;
	if (x < 4) return true;
	if (x % 2 == 0) return false;
	int kok = (int)sqrt(x) + 1;
	for (int i = 3; i < kok; i = i + 2)
	{
		if (x%i == 0) return false;
	}
	return true;
}

int rec(int prev, int Sum)
{
	if (Sum > n) return 0;
	if (Sum == n) return 1;
	if (dn[index[prev]][Sum] != -1) return dn[index[prev]][Sum];
	int tmp = 0;
	for (int i = 0; i < simple.size(); i++)
		if (simple[i] <= prev) tmp += rec(simple[i], Sum + simple[i]);
		else break;
		return dn[index[prev]][Sum] = tmp;
}

int main()
{
	for (int i = 2; i < 330; i++) if (fsimple(i))
	{
		index[i] = simple.size();
		simple.push_back(i);
	}
	while (cin)
	{
		cin >> n;
		if (cin)
		{
			for (int i = 0; i < simple.size(); i++)
				for (int j = 0; j < n; j++) dn[i][j] = -1;

			ans = 0;
			for (int i = 0; i < simple.size(); i++)
				if (simple[i] <= n) ans += rec(simple[i], simple[i]);
				else break;
				cout << ans << endl;
		}
	}
}