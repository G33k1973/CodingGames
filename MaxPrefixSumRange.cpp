//https://practice.geeksforgeeks.org/problems/maximum-prefix-sum-for-a-given-range/0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n, t;
		sc = scanf("%d %d", &n, &t);
		std::vector<ll> px(n, 0), sx(n, 0), a(n, 0);
		ll sum = 0;
		for (int i = 0; i < n; ++i) {
			ll x;
			sc = scanf("%lld", &x);
			px.at(i) = sum;
			sum += x;
			a.operator[](i) = x;
		}
		for (int i = n - 2; i >= 0; --i) {
			sx[i] = sx[i + 1] + a[i + 1];
		}
		for (int i = 0; i < t; ++i) {
			int l, r;
			sc = scanf("%d %d", &l, &r);
			ll res = std::numeric_limits<ll>::min();
			for (int i = l; i <= r; ++i) {
				ll sub = sum - px[l] - sx[i];
				res = max(res, sub);
			}
			printf("%lld ", res);
		}
		printf("\n");
	}
	return 0;
}