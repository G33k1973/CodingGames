#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto& x : a)cin >> x;
		int dp[n][n] = { 0 };
		int i, j, gap;
		for (gap = 0; gap < n; ++gap) {
			for (i = 0, j = gap; j < n; ++i, ++j) {
				int x = (i + 1 <= (j - 1)) ? dp[i + 1][j - 1] : 0;
				int y = (i + 2 <= j) ? dp[i + 2][j] : 0;
				int z = (i <= (j - 2)) ? dp[i][j - 2] : 0;
				dp[i][j] = max(a[i] + min(y, x), a[j] + min(z, x));
			}
		}
		cout << dp[0][n - 1] << endl;
	}
	return 0;
}