#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> coins{ 5000,4000,3000,2000,1000 };
#define m 5
#define INF 0x3f3f3f3f
int dfs(int n, int i, int cum) {
	if (n == 0) {
		return cum / 2;
	}
	if (i >= m)return INF;
	int ans = 0;
	int ans1 = 0, ans2 = INF;
	ans1 = cum / 2 + dfs(n, i + 1, 0);
	int cost = coins.at(i);
	int tot = n;
	int c = 0;
	while (tot >= cost) {
		++c;
		tot -= cost;
		ans2 = min(ans2, cum / 2 + c + dfs(tot, i + 1, c));
	}
	return min(ans1, ans2);
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		if (n % 1000 != 0) {
			cout << "No\n";
			continue;
		}
		int res = dfs(n, 0, 0);
		cout << res << endl;
	}
	return 0;
}