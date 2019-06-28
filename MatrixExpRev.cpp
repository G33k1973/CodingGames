#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
using ll = unsigned long long int;
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
// A utility function to multiply two matrices 
// a[][] and b[][].  Multiplication result is 
// stored back in b[][] 
void multiply(ll a[3][3], ll b[3][3])
{
	// Creating an auxiliary matrix to store elements  
	// of the multiplication matrix 
	ll Mul[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Mul[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				ll sub = mul(a[i][k], b[k][j]);
				Mul[i][j] = ms(Mul[i][j], sub);
			}
		}
	}

	// storing the multiplication resul in a[][] 
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			a[i][j] = Mul[i][j];  // Updating our matrix 
}

// Function to compute F raise to power n-2. 
ll power(ll F[3][3], ll n)
{
	ll Mul[3][3] = { {0,1,1}, {1,0,0}, {0,1,0} };

	// Multiply it with initial values i.e with 
	// F(0) = 0, F(1) = 1, F(2) = 1 
	if (n == 1)
		return ms(F[0][0], F[0][2]);

	power(F, n / 2);

	multiply(F, F);

	if (n % 2 != 0)
		multiply(F, Mul);

	// Multiply it with initial values i.e with 
	// F(0) = 0, F(1) = 1, F(2) = 1 
	return ms(F[0][0], F[0][2]);
}

// Return n'th term of a series defined using below 
// recurrence relation. 
// f(n) is defined as 
//    f(n) = f(n-1) + f(n-2) + f(n-3), n>=3 
// Base Cases : 
//    f(0) = 0, f(1) = 1, f(2) = 1 
ll findNthTerm(ll n)
{
	ll F[3][3] = { {0,1,1}, {1,0,0}, {0,1,0} };

	return power(F, n - 2);
}

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		else if (n == 2) {
			cout << 1 << endl;
			continue;

		}
		ll res = findNthTerm(n);
		cout << res << "\n";
	}
}