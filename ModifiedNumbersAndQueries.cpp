#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
vector<ll> dp;
#define N 1000001
// stores smallest prime factor for every number 
ll spf[N + 1];

// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve()
{
	spf[1] = 1;
	for (ll i = 2; i <= N; i++)

		// marking smallest prime factor for every 
		// number to be itself. 
		spf[i] = i;

	// separately marking spf for every even 
	// number as 2 
	for (ll i = 4; i <= N; i += 2)
		spf[i] = 2;

	for (ll i = 3; i*i <= N; i++)
	{
		// checking if i is prime 
		if (spf[i] == i)
		{
			// marking SPF for all numbers divisible by i 
			for (ll j = i * i; j <= N; j += i) {
				// marking spf[j] if it is not  
				// previously marked 
				if (spf[j] == j)
					spf[j] = i;
			}
		}
	}
}
void init() {
	sieve();
	dp.assign(N + 1, 1);
	dp[0] = 0;
	for (ll i = 2; i <= N; ++i) {
		ll sum = 0, x = i;
		while (x != 1)
		{
			sum += spf[x];
			ll p = x;
			while (x%spf[p] == 0)
				x = x / spf[p];
		}
		dp[i] = sum;
	}
	for (int i = 1; i <= N; ++i)dp[i] += dp[i - 1];
	return;
}

int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	init();
	while (q--) {
		int l, r;
		sc = scanf("%d %d", &l, &r);
		ll res = dp[r] - dp[l - 1];
		printf("%llu\n", res);
	}
	return 0;
}