//LONGEST ARITHMETIC PROGRESSION
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF 0x3f3f3f3f
int dfs(const std::vector<int>& a, int n, int i, int p, int AP) {
	//cout<<AP<<endl;
	if (i == n)return 0;
	int ans = 0;
	int ans1 = 0, ans2 = 0;
	for (int j = i; j < n; ++j) {
		if (AP == INF && j != p) {
			ans1 = max(ans1, 2 + dfs(a, n, j + 1, j, a[j] - a[p]));
		}
		else if (j != p && a[j] - a[p] == AP) {
			ans2 = max(1 + dfs(a, n, j + 1, j, AP), ans2);
		}
	}
	return ans = max(ans1, ans2);
}
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int res = 1;
		for (int i = 0; i < n - 1; ++i) {
			res = std::max(res, dfs(a, n, i + 1, i, INF));
		}
		cout << res << endl;
	}
	return 0;
}