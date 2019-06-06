#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
using ll = unsigned long long int;
ll mul(ll a, ll b) {
	ll res = 0;
	a = (a%M);
	while (b > 0) {
		if (b & 1)
			res = (res%M + a % M) % M;
		b >>= 1;
		a = (a << 1) % M;
	}
	return (res%M);
}
ll fex(ll b, ll n) {
	ll res = 1;
	b = (b%M);
	while (n) {
		if (n & 1) {
			res = mul(res, b);
		}
		n >>= 1;
		b = mul(b, b);
	}
	return res;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		ll h, m;
		cin >> m >> h;
		ll res = fex(m, h);
		cout << res << endl;
	}
	return 0;
}