#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define M 1000000007
#define pb push_back
#define ms(a,b) (((a%M)+(b%M))%M)
vector<ll> dp;
vector<pair<int, int>> tests;
ll mul(ll a, ll b) {
	ll res = 0;
	a = (a%M);
	while (b) {
		if (b & 1) {
			res = ms(res, a);
		}
		a = (a << 1) % M;
		b >>= 1;
	}
	return (res%M);
}
// C function for extended Euclidean Algorithm 
ll gcdExtended(ll a, ll b, ll *x, ll *y);

void init(int n) {
	dp.assign(n + 1, 1);
	for (ll i = 2; i <= n; ++i) {
		dp[i] = mul(dp[i - 1], i);
	}
	return;
}

// Function to find modulo inverse of b. It returns 
// -1 when inverse doesn't 
ll modInverse(ll b)
{
	ll x, y; // used in extended GCD algorithm 
	int g = gcdExtended(b, M, &x, &y);

	// m is added to handle negative x 
	return (x%M + M) % M;
}

// Function to compute a/b under modlo m 
ll modDivide(ll a, ll b)
{
	a = a % M;
	ll inv = modInverse(b);
	return mul(inv, a);
}

// C function for extended Euclidean Algorithm (used to 
// find modular inverse. 
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
	// Base Case 
	if (a == 0)
	{
		*x = 0, *y = 1;
		return b;
	}

	ll x1, y1; // To store results of recursive call 
	ll gcd = gcdExtended(b%a, a, &x1, &y1);

	// Update x and y using results of recursive 
	// call 
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

ll solve(int n, int k) {
	ll sub = modDivide(dp[n - 1], dp[n - k]);
	ll res = modDivide(sub, dp[k - 1]);
}
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	int nmax = 0, kmax = 0;
	while (q--) {
		int n, k;
		sc = scanf("%d %d", &n, &k);
		if (nmax < n)nmax = n;
		if (kmax < k)kmax = k;
		tests.push_back({ n,k });
	}
	init(max(nmax, kmax));
	for (const auto& x : tests) {
		int n = x.first, k = x.second;
		if (k == n) {
			printf("1\n");
			continue;
		}
		if (k > n) {
			printf("0\n");
			continue;
		}
		ll res = solve(n, k);
		printf("%llu\n", res);
	}
	return 0;
}