#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;
		ll res = 1 + 2 * n;
		res += (n*(n - 1)) / 2;
		res += n * (n - 1);
		ll sub = (n*(n - 1)*(n - 2)) / 2;
		if (sub > 0)res += sub;
		cout << res << endl;
	}
	return 0;
}