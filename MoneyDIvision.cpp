#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n;
		sc = scanf("%d", &n);
		vector<ll> a(n, 0);
		ll sum = 0;
		for (auto& x : a) {
			sc = scanf("%lld", &x);
			sum += x;
		}
		int rem = sum % n;
		if (rem != 0) {
			printf("-1\n");
			continue;
		}
		ll delta = sum / n;
		int res = 0;
		bool fail = 0;
		ll incr = 0, decr = 0;
		for (auto& x : a) {
			if (x == delta)continue;
			else if (x < delta) {
				ll gap = delta - x;
				if (gap % 3 != 0) {
					fail = 1;
					break;
				}
				incr += gap;
			}
			else if (x > delta) {
				ll gap = x - delta;
				if (gap % 3 != 0) {
					fail = 1;
					break;
				}
				decr += gap;
			}
		}
		if (decr != incr || ((decr % 3) != 0) || fail) {
			printf("-1\n");
		}
		else {
			res = incr / 3;
			printf("%d\n", res);
		}
	}
	return 0;
}