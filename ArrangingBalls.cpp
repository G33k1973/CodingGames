#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = unsigned long long int;
int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;
		ll res = 1 + 2 * n;
		ll sub = ((n - 1) & 1) ? ((n / 2)*(n - 1)) : (((n - 1) / 2)*n);
		res += sub;
		cout << res << "\n";
	}
	return 0;
}