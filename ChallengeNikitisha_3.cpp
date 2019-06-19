#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
ll mul(ll a, ll b) {
	ll res = 0;
	a = (a%M);
	while (b > 0) {
		if (b & 1)res = ms(res, a);
		b >>= 1;
		a = (a << 1) % M;
	}
	return (res%M);
}
bool IsGreater(const std::deque<int>& a, const ll& res, ll& cum, int n, const std::vector<ll>& pwk_) {
	int i = 0;
	ll x = 1;
	while (i < n) {
		ll sub = mul(pwk_[i], a[i]);
		cum = ms(cum, sub);
		++i;
	}
	return (cum > res);
}
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n, z;
		ll k;
		cin >> n >> z >> k;
		string s("");
		cin >> s;
		std::deque<int> temp, best;
		vector<ll> pwk_(z, 1);
		ll x = 1;
		for (int i = 1; i < z; ++i) {
			ll sub = mul(x, k);
			x = sub;
			pwk_[i] = sub;
		}
		int l = (int)s.size();
		ll res = 0;
		for (int i = l - z; i < l; ++i) {
			temp.push_back(s[i]);
			ll sub = mul(pwk_[z - l + i], s[i]);
			res = ms(res, sub);
		}
		best = temp;
		for (int i = l - 2; i >= (z - 1); --i) {
			temp.pop_back();
			temp.push_front(s[i - z + 1]);
			ll cum = 0;
			if (IsGreater(temp, res, cum, z, pwk_))best = temp, res = cum;
		}
		cout << res << "\n";
	}
	return 0;
}