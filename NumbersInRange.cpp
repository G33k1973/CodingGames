#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef unsigned long long int ll;
vector<ll> memo;
void init(ll n) {
	vector<bool> isprime(n + 1, true);
	ll i, j;
	for (i = 2; i*i <= n; ++i) {
		if (isprime.at(i)) {
			for (j = i * 2; j <= n; j += i) {
				isprime.at(j) = false;
			}
		}
	}
	for (i = 2; i <= n; ++i) {
		if (isprime.at(i))memo.pb(i*i);
	}
	return;
}
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	ll nx = std::numeric_limits<ll>::min();
	vector<pair<ll, ll>> num;
	while (q--) {
		ll x, y;
		sc = scanf("%llu %llu", &x, &y);
		num.pb(mp(x, y));
		if (nx < y)nx = y;
	}
	init(nx);
	for (const auto& x : num) {
		ll l = x.first, r = x.second;
		auto it = std::lower_bound(begin(memo), end(memo), l);
		if (it == end(memo)) {
			cout << 0 << "\n";
			continue;
		}
		int fl = static_cast<int>(it - begin(memo));
		auto it2 = std::lower_bound(begin(memo) + fl, end(memo), r);
		if (it2 == end(memo)) {
			int res = (int)memo.size() - fl;
			cout << res << "\n";
		}
		if (*it2 != r) {
			if (it2 == begin(memo)) {
				cout << "0\n";
				continue;
			}
			--it2;
		}
		int fr = static_cast<int>(it2 - begin(memo));
		int res = fr - fl + 1;
		cout << res << "\n";
	}
	return 0;
}