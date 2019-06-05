#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long int;

ll Totient(ll n) {
	double phi = n;
	int c = 0;
	while (n % 2 == 0) {
		n /= 2;
		if (c == 0)c = !c;
	}
	if (c == 1)phi *= (1. - 1. / 2.);
	for (int i = 3; i*i <= n; i += 2) {
		c = 0;
		while (n%i == 0) {
			n /= i;
			if (!c)c = !c;
		}
		if (c)phi *= (1. - 1. / (1.*i));
	}
	if (n > 1)phi *= (1. - 1. / (1.*n));
	return static_cast<ll>(phi);
}

ll SumGCD(ll n) {
	ll res = n;
	double sum = 0.0;
	for (ll i = 1; i*i <= n; ++i) {
		if (n%i == 0) {
			ll d1 = i, d2 = n / i;
			if (d1 == d2) {
				sum += Totient(d1) / (static_cast<double>(d1));
			}
			else {
				sum += Totient(d1) / (static_cast<double>(d1));
				sum += Totient(d2) / (static_cast<double>(d2));
			}
		}
	}
	sum *= n;
	res = static_cast<ll>((sum));
	return res;
}

int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;
		ll res = SumGCD(n);
		cout << res << endl;
	}
}