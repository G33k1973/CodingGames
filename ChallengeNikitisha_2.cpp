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
bool IsGreater(const std::deque<int>& a, const std::deque<int>& b, int n) {
	int i = n - 1;
	while (i >= 0) {
		if (a[i] > b[i])return true;
		if (a[i] < b[i])return false;
		--i;
	}
	return false;
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
		int l = (int)s.size();
		for (int i = l - z; i < l; ++i) {
			temp.push_back(s[i]);
		}
		best = temp;
		for (int i = l - 2; i >= (z - 1); --i) {
			temp.pop_back();
			temp.push_front(s[i - z + 1]);
			if (IsGreater(temp, best, z))best = temp;
		}
		ll x = 1;
		ll res = 0;
		for (int i = 0; i < z; ++i) {
			ll sub = mul(best[i], x);
			res = ms(res, sub);
			x = mul(x, k);
		}
		cout << res << "\n";
	}
	return 0;
}