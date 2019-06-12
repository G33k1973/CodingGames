#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		ll n, m;
		cin >> n >> m;
		if (m == 1) {
			cout << "1\n";
			continue;
		}
		if (m > n) {
			int d1 = m - n;
			int d2 = n - 1;
			if (d2 < d1)cout << "1\n";
			else cout << m << "\n";
			continue;
		}
		ll res = m;
		ll sub = 1;
		ll diff = std::numeric_limits<ll>::max();
		while (1) {
			ll diff2 = (sub <= n) ? (n - sub) : (sub - n);
			if (diff >= diff2) {
				diff = diff2;
				res = sub;
			}
			if (sub > n)break;
			sub *= m;
		}
		cout << res << "\n";
	}
	return 0;
}