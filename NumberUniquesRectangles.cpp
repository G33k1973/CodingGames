#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;
		ll res = 0;
		for (ll i = 1; i*i <= n; ++i) {
			for (ll j = i; i*j <= n; ++j) {
				++res;
			}
		}
		cout << res << endl;
	}
	return 0;
}