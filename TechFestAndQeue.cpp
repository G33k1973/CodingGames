#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
/*
vector<long long> factorization;
	for (int d : {2, 3, 5}) {
		while (n % d == 0) {
			factorization.push_back(d);
			n /= d;
		}
	}
	static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
	int i = 0;
	for (long long d = 7; d * d <= n; d += increments[i++]) {
		while (n % d == 0) {
			factorization.push_back(d);
			n /= d;
		}
		if (i == 8)
			i = 0;
	}
	if (n > 1)
		factorization.push_back(n);
		*/
ll solve(ll a, ll b) {
	static array<int, 8> increments = { 4, 2, 4, 2, 4, 6, 2, 6 };
	ll i = a;
	ll sum = 0;
	while (i <= b) {
		ll j = i;
		int c = 0;
		for (int d : {2, 3, 5}) {
			if (c)c = 0;
			while (j % d == 0) {
				j /= d;
				++c;
			}
			if (c)sum += c;
		}
		int k = 0;
		for (ll d = 7; d * d <= j; d += increments[k++]) {
			if (c)c = 0;
			while (j % d == 0) {
				++c;
				j /= d;
			}
			if (c)sum += c;
			if (k == 8)
				k = 0;
		}
		if (j > 1)++sum;
		++i;
	}
	return sum;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		ll n, a, b;
		cin >> n >> a >> b;
		ll res = solve(a, b);
		cout << res << "\n";
	}
	return 0;
}