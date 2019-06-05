#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 100
using ll = unsigned long long int;
vector<bool> ip;
void init() {
	ip.assign(N + 1, true);
	for (int i = 2; i*i <= N; ++i) {
		if (ip[i]) {
			for (int j = i * 2; j <= N; j += i) {
				ip.operator[](j) = false;
			}
		}
	}
	return;
}

// Returns the highest exponent of p in n! 
ll expFactor(ll n, ll p)
{
	ll x = static_cast<ll>(p);
	ll exponent = 0;
	while ((n / x) > 0)
	{
		exponent += n / x;
		x *= p;
	}
	return exponent;
}

int main() {
	//code
	init();
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		assert(N <= 100);
		ll ans = 1;
		for (int i = 2; i <= n; ++i) {
			if (ip[i]) {
				ans *= (expFactor(n, i) + 1);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}