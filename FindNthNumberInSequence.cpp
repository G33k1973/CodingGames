#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		ll x;
		cin >> x;
		double y = 1 + 8 * x;
		double sy = sqrt(y);
		ll val = static_cast<ll>(std::floor((-1 + sy) / 2.));
		ll z = (val*(val + 1)) / 2;
		if (z == x) {
			cout << val << "\n";
			continue;
		}
		val = 0;
		while (z != x) {
			++val, ++z;
		}
		cout << val << endl;
	}
	return 0;
}