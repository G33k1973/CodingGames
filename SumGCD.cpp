#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define pb push_back
using ll = unsigned long long int;
#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
ll mul(ll a, ll b) {
	ll res = 0;
	a = (a%M);
	while (b > 0) {
		if (b & 1) {
			res = ms(res, a);
		}
		b >>= 1;
		a = (a << 1) % M;
	}
	return (res%M);
}
ll solve(ll n) {
	ll res = 1 + n;
	vector<bool> vis(n + 1, false);
	vis[1] = vis[n] = true;
	ll av = n - 2;
	vector<int> div1;
	stack<int> div2;
	for (ll i = 2; i*i <= n; ++i) {
		if (n%i == 0) {
			ll d1 = i, d2 = n / i;
			if (d1 == d2) {
				ll j = d1;
				div1.pb(d1);
			}
			else {
				ll mx = max(d1, d2);
				ll mn = min(d1, d2);
				div1.pb(mn);
				div2.push(mx);
			}
		}
	}
	while (!div2.empty()) {
		div1.pb(div2.top());
		div2.pop();
	}
	int m = (int)div1.size();
	int i = m - 1;
	while (i >= 0) {
		ll j = div1[i];
		while (j < n) {
			if (!vis[j]) {
				res = ms(res, div1[i]);
				vis[j] = true;
				--av;
			}
			j += div1[i];
		}
		--i;
	}
	res = ms(res, av);
	return res;
}

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		ll x;
		cin >> x;
		cout << solve(x) << "\n";
	}
}