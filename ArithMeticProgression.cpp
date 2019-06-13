#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define pb push_back
using ll = long long int;
void solve(int n, int n1, int n2) {
	cout << "1 ";
	ll p = 1;
	vector<ll> a{ p };
	for (int i = 2; i <= n; ++i) {
		ll x = p + 1;
		while (1) {
			bool suc = static_cast<bool>(1);
			for (int j = 0; j < i - 1; ++j) {
				for (int k = j; k < i - 1; ++k) {
					ll y = n1 * a[j] - n2 * a[k];
					if (y == x) {
						suc = 0;
						break;
					}
					y = n1 * a[k] - n2 * a[j];
					if (y == x) {
						suc = 0;
						break;
					}
				}
				if (suc == 0)break;
			}
			if (suc ^ 0)break;
			++x;
		}
		cout << x;
		if (i != n)cout << ' ';
		a.pb(x);
		p = a.back();
	}
	cout << '\n';
	return;
}

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n;
		ll n1, n2;
		cin >> n1 >> n2 >> n;
		solve(n, n1, n2);
	}
}