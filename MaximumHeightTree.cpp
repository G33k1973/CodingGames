#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		ll x;
		sc = scanf("%lld", &x);
		ll delta = 1 + 8 * x;
		double root = (-1. + sqrt(delta)) / 2.;
		ll res = static_cast<ll>(std::floor(root));
		printf("%lld\n", res);
	}
	return 0;
}