#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n, m, k;
		cin >> n >> m >> k;
		int mx[n][m] = { 0 }, mxror[n][m] = { 0 };
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> mx[i][j];
			}
		}
		k %= m;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int nix = (j - k + m) % m;
				mxror[i][nix] = mx[i][j];
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << mxror[i][j] << " ";
			}
		}
		cout << endl;
	}
	return 0;
}