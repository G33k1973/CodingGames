#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int l;
		cin >> l;
		string s("");
		cin >> s;
		int res = 0;
		int i, j;
		int f[3] = { 0 };
		for (i = 0; i < l; ++i) {
			int sum = 0;
			bool st = 0;
			for (j = i; j < l; ++j) {
				int d = j - i + 1;
				sum += s[j] - '0';
				bool discard = (sum == 0 || (sum % 3) == 0);
				if (d < 3) {
					int x = (d == 1) ? (s[j] - '0') : ((s[j - 1] - '0') * 10 + (s[j] - '0'));
					if (!discard)if (x > 0 && x % 8 == 0)++res;
				}
				else {
					if (st == 0) {
						f[0] = s[j - 2] - '0', f[1] = s[j - 1] - '0', f[2] = s[j] - '0';
						st = 1;
					}
					else {
						f[0] = f[1];
						f[1] = f[2];
						f[2] = s[j] - '0';
					}
					int x = f[0] * 100 + f[1] * 10 + f[2];
					if (!discard)if (x % 8 == 0)++res;
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}