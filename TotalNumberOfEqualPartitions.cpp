#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
#define pb push_back
#define mp make_pair
vector<ll> memo;
void init(ll n) {
	memo.assign(n + 1, 1);
	std::iota(begin(memo) + 2, end(memo), 2);
	memo[0] = 1, memo[1] = 1;
	for (ll i = 2; i <= n / 2; ++i) {
		for (ll j = i * 2, k = 2; j <= n; j += i, ++k) {
			memo[j] += k;
		}
	}
	for (ll i = 2; i <= n; ++i) {
		++memo[i];
		memo[i] += memo[i - 1];
	}
}
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	ll nx = 0;
	vector<pair<ll, ll>> a;
	while (q--) {
		ll l, r;
		cin >> l >> r;
		assert(l <= r);
		if (nx < r)nx = r;
		a.pb(mp(l, r));
	}
	init(nx);
	for (const auto& x : a) {
		ll res = memo[x.second] - memo[x.first - 1];
		cout << res << endl;
	}
	return 0;
}