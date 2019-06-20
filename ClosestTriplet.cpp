#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb push_back
ll solve(vector<ll>& a, int na, vector<ll>& b, int nb, vector<ll>& c, int nc, int i) {
	ll res = std::numeric_limits<ll>::max();
	ll y1, y2, z1, z2;
	for (auto& x : a) {
		ll sub = 0;
		auto it = std::lower_bound(begin(b), end(b), x);
		if (it == end(b)) {
			--it;
			y1 = y2 = *it;
		}
		else if (*it != x) {
			if (it == begin(b))y1 = y2 = *it;
			else {
				ll v1 = *it;
				--it;
				ll v2 = *it;
				y1 = v1, y2 = v2;
			}
		}
		else y1 = y2 = *it;
		auto it2 = std::lower_bound(begin(c), end(c), x);
		if (it2 == end(c)) {
			--it2;
			z1 = z2 = *it2;
		}
		else if (*it2 != x) {
			if (it2 == begin(c))z1 = z2 = *it2;
			else {
				z1 = *it2;
				--it2;
				z2 = *it2;
			}
		}
		else z1 = z2 = *it2;
		sub = max(abs(x - y1), max(abs(x - z1), abs(z1 - y1)));
		res = min(res, sub);
		sub = max(abs(x - y2), max(abs(x - z1), abs(z1 - y2)));
		res = min(res, sub);
		sub = max(abs(x - y2), max(abs(x - z2), abs(z2 - y2)));
		res = min(res, sub);
		sub = max(abs(x - y1), max(abs(x - z2), abs(z2 - y1)));
		res = min(res, sub);
	}
	return res;
}
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n1, n2, n3;
		vector<ll> a, b, c;
		sc = scanf("%d", &n1);
		a.assign(n1, 0);
		for (auto& x : a)sc = scanf("%lld", &x);
		sc = scanf("%d", &n2);
		b.assign(n2, 0);
		for (auto& x : b)sc = scanf("%lld", &x);
		sc = scanf("%d", &n3);
		c.assign(n3, 0);
		for (auto& x : c)sc = scanf("%lld", &x);
		ll res = solve(a, n1, b, n2, c, n3, 0);
		printf("%lld\n", res);
	}
	return 0;
}