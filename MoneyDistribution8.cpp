#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define M 1000000007
#define pb push_back
#define ms(a,b) (((a%M)+(b%M))%M)
map<int, ll> memo;
vector<ll> dp;
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
	ll res = 1ULL;
	if (k > n - k)
		k = n - k;

	// Calculate value of  
	// [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1] 
	ll numerator = 1, denominator = 1, i = 1;
	auto it = memo.lower_bound(k);
	if (it == end(memo) && memo.size() > 0) {
		--it;
		i = (*it).first+1;
		denominator = (*it).second;
	}
	else if (it != end(memo)) {
		if ((*it).first == k) {
			denominator = (*it).second;
			i = (*it).first + 1;
		}
		else if (it != begin(memo)) {
			--it;
			i = (*it).first + 1;
			denominator = (*it).second;
		}
	}
	for (; i <= k; ++i)
	{
		denominator = mul(denominator, i);
		//res = mul(res, n - i);
		//res = modDivide(res, i + 1);
	}
	memo[k] = denominator;
	for (ll i = n - k + 1; i <= n; ++i) {
		numerator = mul(numerator, i);
	}

	return res = modDivide(numerator, denominator);
}
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n, k;
		sc = scanf("%d %d", &n, &k);
		if (k == n) {
			printf("1\n");
			continue;
		}
		if (k > n) {
			printf("0\n");
			continue;
		}
		ll res = solve(n - 1, k - 1);
		printf("%llu\n", res);
	}
	return 0;
}