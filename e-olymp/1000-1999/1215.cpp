// (c) Tivole

// 1215

#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, m, ans; cin >> n;
	string str1, str2;
	for (int i = 0; i < n; i++) {
		cin >> m;
		ans = 0;
		for (int j = 0; j < m; j++) {
			cin >> str1 >> str2;
			if (str1 == "P" && str2 == "R") ans++;
			if (str1 == "P" && str2 == "S") ans--;
			if (str1 == "R" && str2 == "P") ans--;
			if (str1 == "R" && str2 == "S") ans++;
			if (str1 == "S" && str2 == "P") ans++;
			if (str1 == "S" && str2 == "R") ans--;
		}
		if (ans == 0) cout << "TIE" << endl;
		else if (ans > 0) cout << "Player 1" << endl;
		else cout << "Player 2" << endl;
	}
}