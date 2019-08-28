#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ip = std::pair<ll, ll>;
#define pb push_back
#define mp make_pair
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n;
		sc = scanf("%d", &n);
		vector<ip> a;
		for (int i = 0; i < n; ++i) {
			ll x, y;
			sc = scanf("%lld %lld", &x, &y);
			a.pb(mp(x, y));
		}
		ll res = 0;
		ip src{ a.front().first,a.front().second };
		for (int i = 1; i < n; ++i) {
			ll x = a[i].first, y = a[i].second;
			if (x == src.first || y == src.second)res += abs(x - src.first) + abs(y - src.second);
			else {
				ll sub = abs(x - src.first) + abs(y - src.second);
				ll sub2 = 0, sub3 = 0;
				if (y > src.second) {
					ll delta = y - src.second;
					if (x > src.first) {
						sub2 = delta + abs(src.first + delta - x);
					}
					else if (x < src.first) {
						sub2 = delta + abs(src.first - delta - x);
					}
				}
				else if (y < src.second) {
					ll delta = -y + src.second;
					if (x > src.first) {
						sub2 = delta + abs(src.first + delta - x);
					}
					else if (x < src.first) {
						sub2 = delta + abs(src.first - delta - x);
					}
				}
				if (x > src.first) {
					ll delta = x - src.first;
					if (y > src.second) {
						sub3 = delta + abs(src.second + delta - y);
					}
					else if (y < src.second) {
						sub3 = delta + abs(src.second - delta - y);
					}
				}
				else if (x < src.first) {
					ll delta = -x + src.first;
					if (y > src.second) {
						sub3 = delta + abs(src.second + delta - y);
					}
					else if (x < src.first) {
						sub3 = delta + abs(src.second - delta - y);
					}
				}
				res += std::min(min(sub2, sub3), sub);
			}
			src = mp(x, y);
		}
		printf("%lld\n", res);
	}
	return 0;
}