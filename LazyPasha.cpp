#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n, t;
		cin >> n >> t;
		string s("");
		cin >> s;
		string cur(s);
		int l = static_cast<int>(s.length());
		while (t--) {
			int a, b;
			cin >> a >> b;
			if (a == 1) {
				int k = b;
				k %= l;
				if (k == 0) {
					continue;
				}
				s += s;
				s = s.substr(l - k, l);
			}
			else if (a == 2) {
				cout << s[b] << "\n";
			}
		}
	}
	return 0;
}