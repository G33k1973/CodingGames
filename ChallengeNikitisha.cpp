#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define M 1000000007
using ll = unsigned long long int;
#define pb push_back
#define mp make_pair
#define ms(a,b) (((a%M)+(b%M))%M)
ll mul(ll a, ll b) {
	ll res = 0;
	a = (a%M);
	while (b > 0) {
		if (b & 1) {
			res = ms(res, a);
		}
		a = (a << 1) % M;
		b >>= 1;
	}
	return (res%M);
}
ll fex(ll b, ll n) {
	ll res = 1;
	b = (b%M);
	while (n > 0) {
		if (n & 1)
			res = mul(res, b);
		n >>= 1;
		b = mul(b, b);
	}
	return res;
}
ll solve(string& x, int l, int z, ll k) {
	reverse(begin(x), end(x));
	string cur = x.substr(0, z);
	string best = cur;
	for (int i = 1; i <= (l - z); ++i) {
		cur.erase(0, 1);
		cur.pb(x[i + z]);
		if (cur > best)best = cur;
	}
	ll pwk = 1;
	ll res = 0;
	for (int i = z - 1; i >= 0; --i) {
		ll val = static_cast<ll>(best[i] - 'a');
		ll sub = mul(pwk, val);
		res = ms(res, sub);
		pwk = mul(pwk, k);
	}
	return res;
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		string s("");
		int z, l;
		ll k;
		cin >> l >> z >> k >> s;
		cout << solve(s, l, z, k) << endl;
	}
}