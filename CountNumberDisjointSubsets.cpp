#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
using ll = long long int;

ll gcdExtended(ll a, ll b, ll *x, ll *y) {
	if (a == 0) {
		*x = 0, *y = 1;
		return b;
	}
	ll x1, y1;
	ll gcd = gcdExtended(b%a, a, &x1, &y1);
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

ll modInverse(ll b, ll m)
{
	ll x, y; // used in extended GCD algorithm 
	ll g = gcdExtended(b, m, &x, &y);

	// m is added to handle negative x 
	return (x%M + M) % M;
}
ll mul(ll a, ll b);
// Function to compute a/b under modlo m 
ll modDivide(int a, int b)
{
	a = a % M;
	ll inv = modInverse(b, M);
	return mul(inv, a);
}

ll mul(ll a, ll b) {
	ll res = 0;
	a = (a%M);
	while (b > 0) {
		if (b & 1) {
			res = ms(res, a);
		}
		b >>= 1;
		a = (a << 1) % M;
	}
	return (res%M);
}

ll fex(ll b, ll n) {
	ll res = 1;
	b = (b%M);
	while (n > 0) {
		if (n & 1) {
			res = mul(res, b);
		}
		n >>= 1;
		b = mul(b, b);
	}
	return res;
}

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	ll num1 = 3LL;
	ll num2 = 2LL;
	while (q--) {
		ll n;
		cin >> n;
		ll sub1 = fex(num1, n);
		sub1 = ms(sub1, 1ULL);
		sub1 = modDivide(sub1, 2LL);
		ll sub2 = fex(num2, n);
		ll res = (sub1%M - sub2 % M + M) % M;
		cout << res << endl;
	}
}