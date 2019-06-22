#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//#define N 1000005
#define pb push_back
#define mp make_pair
using ll = long long int;
vector<ll> sumprime;
void init(int N) {
	vector<bool> isprime(N + 1, true);
	int i, j;
	for (i = 2; i*i <= N; ++i) {
		if (isprime.at(i)) {
			for (j = i * 2; j <= N; j += i) {
				isprime.at(j) = false;
			}
		}
	}
	sumprime.assign(N + 1, 0);
	for (i = 2; i <= N; ++i) {
		if (isprime.at(i))sumprime[i] = i + sumprime[i - 1];
		else sumprime[i] = sumprime[i - 1];
	}
	return;
}

ll sumOfPrimes(int n)
{
	// Array to store prime numbers 
	bool prime[n + 1];

	// Create a boolean array "prime[0..n]" 
	// and initialize all entries it as true. 
	// A value in prime[i] will finally be 
	// false if i is Not a prime, else true. 
	memset(prime, true, n + 1);

	for (int p = 2; p * p <= n; p++) {

		// If prime[p] is not changed, then 
		// it is a prime 
		if (prime[p] == true) {

			// Update all multiples of p 
			for (int i = p * 2; i <= n; i += p)
				prime[i] = false;
		}
	}

	// Return sum of primes generated through 
	// Sieve. 
	ll sum = 0;
	for (int i = 2; i <= n; i++)
		if (prime[i])
			sum += i;
	return sum;
}

int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	int nx = 0;
	vector<int> arr;
	while (q--) {
		int n;
		sc = scanf("%d", &n);
		printf("%lld\n", sumOfPrimes(n));
		continue;
		arr.pb(n);
		if (nx < n)nx = n;
	}
	{
		return 0;
	}
	init(nx);
	for (const auto& x : arr)printf("%lld\n", sumprime[x]);
	return 0;
}