#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = unsigned long long int;
int solve(ll n) {
	int res = 0;
	while (n >= 1) {
		if (n == 1) {
			++res;
			break;
		}
		if (!(n & 1ULL)) {
			n >>= 1;
			++res;
		}
		else {
			bool suc = static_cast<bool>(0);
			for (ll j = 2; j <= sqrt(n); ++j) {
				if (n%j == 0) {
					ll d = n / j;
					n -= d;
					++res;
					suc = true;
					break;
				}
			}
			if ((suc ^ 1)) {
				--n, ++res;
			}
		}
	}
	return res;
}

int main(int argc, char ** argv) {
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		ll n;
		sc = scanf("%llu", &n);
		ll res = solve(n);
		printf("%llu\n", res);
	}
}