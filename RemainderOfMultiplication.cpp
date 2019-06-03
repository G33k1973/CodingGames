#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = unsigned long long int;

ll mul(ll a, ll b, ll k) {
	ll res = 0;
	a = (a%k);
	while (b > 0) {
		if (b & 1)res = (res%k + a % k) % k;
		b >>= 1;
		a = (a << 1) % k;
	}
	return (res%k);
}

int main(int argc, char ** argv) {
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n, k;
		sc = scanf("%d", &n);
		ll res = 1;
		int i = 0;
		vector<ll> arr(n, 0);
		while (i < n) {
			ll& x = arr.operator[](i);
			sc = scanf("%llu", &x);
			++i;
		}
		sc = scanf("%d", &k);
		i = 0;
		while (i < n) {
			const ll& x = arr.operator[](i);
			res = mul(res, x, k);
			if (res == 0)break;
			++i;
		}
		printf("%llu\n", res);
	}
}