#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		ll a, b;
		cin >> a >> b;
		ll d = a / b;
		ll res = b * (d + 1);
		cout << res << endl;
	}
	return 0;
}