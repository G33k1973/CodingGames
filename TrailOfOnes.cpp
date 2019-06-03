#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = ull;
vector<ull> dp;
void init(ull n) {
	dp.assign(n + 1, 0);
	ll x = 0, y = 1;
	for (ull i = 2; i <= n; ++i) {
		if (i == 2)dp[i] = 1;
		else {
			ll z = x + y;
			x = y;
			y = z;
			dp[i] = 2 * dp[i - 1] + z;
		}
	}
}
#define pb push_back
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	ull nx = 0;
	vector<ull> a;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;
		a.pb(n);
		if (nx < n)nx = n;
	}
	init(nx);
	for (auto& x : a) {
		cout << dp[x] << "\n";
	}
	return 0;
}