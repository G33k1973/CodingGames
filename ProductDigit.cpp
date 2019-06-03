#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << 1 << "\n";
			continue;
		}
		int digit = 9;
		string res("");
		while (n > 1) {
			while (n%digit == 0) {
				n /= digit;
				res.push_back(digit + '0');
			}
			--digit;
			if (digit == 1)break;
		}
		if (n != 1)cout << "-1\n";
		else {
			reverse(begin(res), end(res));
			cout << res << "\n";
		}
	}
}