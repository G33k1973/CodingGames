#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = unsigned long long int;
vector<bool> dp;
std::unordered_map<ll, ll> table;
void init(ll n, vector<ll>& arr) {
	dp.assign(n + 1, 0);
	ll x = 2;
	while (1) {
		ll x2 = x * x;
		if (x2 > n)break;
		ll y = x2;
		while (y <= n) {
			if (dp[y] == 0) {
				dp[y] = 1;
				for (auto& x : arr) {
					if (x >= y)++table[x];
				}
			}
			y += x2;
		}
		++x;
	}
}
int main(int argc, char ** argv) {
	int q;
	int sc = scanf("%d", &q);
	ll nx = 0;
	vector<ll> a;
	while (q--) {
		ll n;
		sc = scanf("%llu", &n);
		a.push_back(n);
		table[n] = 0;
		if (nx < n)nx = n;
	}
	init(nx, a);
	for (auto& x : a) {
		printf("%lld\n", table[x]);
	}
	return 0;
}