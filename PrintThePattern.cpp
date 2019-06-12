#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int l, h;
		for (int i = 1; i <= n; ++i) {
			int tot = (n - i + 1) * 2;
			if (i == 1) {
				int j = n * n;
				int k = 1;
				int c = 0;
				while (c < tot) {
					if (k == (n + 1)) {
						l = k;
						k = j + 1;
						h = k - 1;
					}
					cout << k;
					if (c != (tot - 1))cout << '*';
					++c, ++k;
				}
				cout << '\n';
			}
			else {
				for (int j = 0; j < 2 * (i - 1); ++j)cout << '-';
				int k = l;
				int j = k + tot / 2;
				while (k < j) {
					cout << k << '*';
					++k;
				}
				l = k;
				k = h - tot / 2 + 1;
				while (k <= h) {
					cout << k;
					if (k != h)cout << '*';
					++k;
				}
				h = k - 1 - tot / 2;
				cout << "\n";
			}
		}
	}
	return 0;
}