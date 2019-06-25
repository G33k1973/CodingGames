#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
using ll = long long int;
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		ll s, x;
		int n;
		sc = scanf("%lld %d %lld", &s, &n, &x);
		std::set<ll> a;
		ll tot = s;
		a.insert(s);
		int i = 0;
		ll y, z;
		bool off = false;
		ll cum = s;
		while (i < n) {
			sc = scanf("%lld", &y);
			z = tot + y;
			if (!off) {
				a.insert(z);
				tot += z;
			}
			if (!off&&z > x)off = !off;
			++i;
		}
		if (tot == x) {
			printf("yes\n");
			continue;
		}
		if (tot < x) {
			printf("no\n");
			continue;
		}
		while (!a.empty()) {
			auto it = a.lower_bound(x);
			if (it == end(a))--it;
			if (*it > x) {
				if (it == begin(a))break;
				--it;
			}
			x = x - *it;
			if (x == 0)break;
			a.erase(it);
		}
		if (x == 0)printf("yes\n");
		else printf("no\n");
	}
	return 0;
}