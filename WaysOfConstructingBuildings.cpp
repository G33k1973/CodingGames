#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
#define pb push_back
vector<ll> dp;
#define M 1000000007
void init(int n) {
	dp.assign(n + 2, 0);
	dp[0] = 1, dp[1] = 1;
	for (int i = 2; i <= n + 1; ++i) {
		dp[i] = (dp[i - 2] % M + dp[i - 1] % M) % M;
	}
	return;
}
ll mul(ll a, ll b) {
	ll res = 0;
	a = (a%M);
	while (b > 0) {
		if (b & 1) {
			res = (res%M + a % M) % M;
		}
		b >>= 1;
		a = (a << 1) % M;
	}
	return (res%M);
}
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	ll nx = 0;
	vector<ll> a;
	while (q--) {
		ll x;
		sc = scanf("%llu", &x);
		a.pb(x);
		if (x > nx)nx = x;
	}
	init(nx);
	for (const auto& x : a) {
		ll res = mul(dp[x + 1], dp[x + 1]);
		printf("%llu\n", res);
	}
	return 0;
}