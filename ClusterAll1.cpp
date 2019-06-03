#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> px, sx;
int tot;
struct Order {
	int I, J, i, j;
	int cluster;
	Order() {
		I = J = i = j = -1;
		cluster = INT_MIN;
	}
};
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		string s("");
		cin >> s;
		int c1 = 0;
		for (auto& x : s) {
			if (x == '1')++c1;
		}
		if (c1 == 1 || c1 == (int)s.size()) {
			cout << "0\n";
			continue;
		}
		int l = static_cast<int>(s.size());
		s += s;
		int res = INT_MAX;
		int i, j;
		bool out = 0;
		for (i = 0; i <= l; ++i) {
			bool st = 0;
			int sub = 0, subc1 = 0;
			for (int j = i; j < i + l; ++j) {
				if (s[j] == '1'&&st == 0) {
					st = 1;
				}
				if (s[j] == '0'&&st == 1)++sub;
				if (s[j] == '1')++subc1;
				if (subc1 == c1)break;
				if (sub > res)break;
			}
			if (sub < res)res = sub;
			if (res == c1)break;
		}
		cout << res << endl;
	}
	return 0;
}