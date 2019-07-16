#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define pb push_back
using ll = unsigned long long int;
#define M 1000000007
#define N 2
#define ms(a,b) (((a%M)+(b%M))%M)
#define mod(a) (a%M)
ll mul(ll a, ll b) {
	ll res = 0;
	a = mod(a);
	while (b > 0) {
		if (b & 1)res = ms(res, a);
		b >>= 1;
		a = (a << 1) % M;
	}
	res = mod(res);
	return (res);
}
ll fex(ll b, ll n) {
	ll res = 1ULL;
	b = mod(b);
	while (n > 0) {
		if (n & 1) {
			res = mul(res, b);
		}
		n >>= 1;
		b = mul(b, b);
	}
	return (res);
}
// A utility function to multiply two matrices 
// a[][] and b[][].  Multiplication result is 
// stored back in b[][] 
void multiply(ll a[N][N], ll b[N][N])
{
	// Creating an auxiliary matrix to store elements  
	// of the multiplication matrix 
	ll cur[N][N] = { 0 };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cur[i][j] = 0;
			for (int k = 0; k < N; k++) {
				ll sub = mul(a[i][k], b[k][j]);
				cur[i][j] = ms(cur[i][j], sub);
			}
		}
	}

	// storing the multiplication resul in a[][] 
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			a[i][j] = cur[i][j];  // Updating our matrix 

	return;
}

// Function to compute F raise to power n-2. 
ll power(ll F[N][N], ll n)
{
	ll Mx[N][N] = { {1ULL,1ULL}, {1ULL,0} };

	if (n == 1) {
		return F[1][0];
	}

	power(F, n / 2);

	multiply(F, F);

	if (n % 2 != 0)
		multiply(F, Mx);


	return F[1][0];
}

ll findNthTerm(ll n)
{
	ll F[N][N] = { {1ULL,1ULL}, {1ULL,0ULL} };

	return power(F, n);
}

int main(int argc, char ** argv) {
	int	q;
	int sc = scanf("%d", &q);
	while (q--) {
		ll n;
		sc = scanf("%llu", &n);
		if (n == 0) {
			printf("1\n");
			continue;
		}
		ll res = findNthTerm(n + 1);
		printf("%llu\n", res);
	}
	return 0;
}