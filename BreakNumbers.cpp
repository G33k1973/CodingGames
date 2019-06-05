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
		{
			ll res = (n & 1) ? (((n + 1) / 2)*(n + 2)) : (((n + 2) / 2)*(n + 1));
			cout << res;
			cout << endl;
			continue;
		}
		ll res = 0;
		if (n % 3 == 0)++res;
		res += ((n) / 2) * 3;
		ll i, j;
		ll sub = 0;
		for (i = 0; i <= n / 3; ++i) {
			ll diff = n - i;
			sub += (diff - 1) / 2;
		}
		//cout<<sub<<endl;
		ll prod = sub * 6;
		res += prod;
		cout << res << endl;
	}
	return 0;
}