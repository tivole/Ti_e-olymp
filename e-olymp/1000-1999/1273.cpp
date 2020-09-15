// (c) Tivole

// 1273

#include <iostream>
#include <set>

using namespace std;

set<int>sum;

void get(int x)
{
	for (int i = 2; i*i <= x; i++)
	{
		while (x%i == 0)
		{
			sum.insert(i);
			x /= i;
		}
	}
	if (x > 1) sum.insert(x);
}

int main()
{
	int n, m, kase = 1;
	while (cin >> n >> m && n && m)
	{
		sum.clear();
		get(n); get(m);
		int ans = 0;
		set<int>::iterator it = sum.begin();
		for (; it != sum.end(); it++)
		{
			int a = 0, b = 0, temp = *it;
			while (n%temp == 0) a++, n /= temp;
			while (m%temp == 0) b++, m /= temp;
			ans += a > b ? a - b : b - a;
		}
		cout << kase++ << ". " << sum.size() << ":" << ans << endl;
	}
}