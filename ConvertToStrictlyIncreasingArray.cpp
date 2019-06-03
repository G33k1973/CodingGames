#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n;
		sc = scanf("%d", &n);
		vector<int> a(n, 0);
		for (auto& x : a)sc = scanf("%d", &x);
		vector<int> dp(n, 1);
		int res = 1;
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (a[i] > a[j] && dp[i] < 1 + dp[j]) {
					dp[i] = 1 + dp[j];
				}
			}
			res = max(dp[i], res);
		}
		res = n - res;
		printf("%d\n", res);
	}
	return 0;
}