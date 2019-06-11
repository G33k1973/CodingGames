#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
#define LLMAX std::numeric_limits<ll>::max()
ll GCD(ll a, ll b) {
	if (a == 0)return b;
	return GCD(b%a, a);
}
#define pb push_back
vector<ll> solve(ll x) {
	vector<ll> temp;
	int c = 0;
	while (x % 2 == 0) {
		x /= 2;
		if (c == 0)++c;
	}
	if (c)temp.pb(2);
	for (ll i = 3; i*i <= x; i += 2) {
		c = 0;
		while (x%i == 0) {
			if (!c)c = !c;
			x /= i;
		}
		if (c)temp.pb(i);
	}
	if (x > 1)temp.pb(x);
	return std::move(temp);
}
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n;
		sc = scanf("%d", &n);
		ll p = LLMAX;
		ll res = 1;
		int i = 0;
		while (i < n) {
			ll x;
			sc = scanf("%llu", &x);
			if (p != LLMAX) {
				res = (x*res) / GCD(x, res);
			}
			else res = x;
			p = x;
			++i;
		}
		vector<ll> b = solve(res);
		for (auto& x : b)printf("%llu ", x);
		printf("\n");
	}
	return 0;
}