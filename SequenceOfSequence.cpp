#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int dfs(int n, int m, int i, int p) {
	if (i == n)return 1;
	if (p > m)return 0;
	int ans = 0;
	for (int j = p * 2; j <= m; ++j) {
		ans += dfs(n, m, i + 1, j);
	}
	return ans;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int m, n;
		cin >> m >> n;
		int ans = 0;
		for (int i = 1; i <= m; ++i) {
			int sub = dfs(n, m, 1, i);
			if (sub == 0)break;
			ans += sub;
		}
		cout << ans << "\n";
	}
	return 0;
}