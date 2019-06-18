#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define pb push_back
#define mp make_pair
typedef unsigned long long int ll;
#define N 1e6
vector<ll> prime;
// This functions finds all primes smaller than 'limit' 
// using simple sieve of eratosthenes. It also stores 
// found primes in vector prime[] 
void simpleSieve(ll limit)
{
	// Create a boolean array "mark[0..n-1]" and initialize 
	// all entries of it as true. A value in mark[p] will 
	// finally be false if 'p' is Not a prime, else true. 
	bool mark[limit + 1];
	memset(mark, true, sizeof(mark));

	for (int p = 2; p*p < limit; p++)
	{
		// If p is not changed, then it is a prime 
		if (mark[p] == true)
		{
			// Update all multiples of p 
			for (int i = p * 2; i < limit; i += p)
				mark[i] = false;
		}
	}

	// Print all prime numbers and store them in prime 
	for (int p = 2; p < limit; p++)
	{
		if (mark[p] == true)
		{
			prime.push_back(p);
		}
	}
}

// Prints all prime numbers smaller than 'n' 
void segmentedSieve(ll n)
{
	{
		simpleSieve(n);
		return;
	}
	// Compute all primes smaller than or equal 
	// to square root of n using simple sieve 
	ll limit = floor(sqrt(n)) + 1;
	simpleSieve(limit);
	// Divide the range [0..n-1] in different segments 
	// We have chosen segment size as sqrt(n). 
	ll low = limit;
	ll high = 2 * limit;

	// While all segments of range [0..n-1] are not processed, 
	// process one segment at a time 
	while (low < n)
	{
		if (high >= n)
			high = n;

		// To mark primes in current range. A value in mark[i] 
		// will finally be false if 'i-low' is Not a prime, 
		// else true. 
		bool mark[limit + 1];
		memset(mark, true, sizeof(mark));

		// Use the found primes by simpleSieve() to find 
		// primes in current range 
		for (int i = 0; i < prime.size(); i++)
		{
			// Find the minimum number in [low..high] that is 
			// a multiple of prime[i] (divisible by prime[i]) 
			// For example, if low is 31 and prime[i] is 3, 
			// we start with 33. 
			ll loLim = floor(low / prime[i]) * prime[i];
			if (loLim < low)
				loLim += prime[i];

			/* Mark multiples of prime[i] in [low..high]:
				We are marking j - low for j, i.e. each number
				in range [low, high] is mapped to [0, high-low]
				so if range is [50, 100] marking 50 corresponds
				to marking 0, marking 51 corresponds to 1 and
				so on. In this way we need to allocate space only
				for range */
			for (int j = loLim; j < high; j += prime[i])
				mark[j - low] = false;
		}

		// Numbers which are not marked as false are prime 
		for (ll i = low; i < high; i++)
			if (mark[i - low] == true)
				prime.pb(i);

		// Update low and high for next segment 
		low = low + limit;
		high = high + limit;
	}
	return;
}

int main(int argc, char ** argv) {
	segmentedSieve(static_cast<ll>(N));
	int q;
	cin >> q;
	while (q--) {
		ll x;
		cin >> x;
		ll res = 1;
		for (const auto& y : prime) {
			ll nxt = res * y;
			if (nxt > x)break;
			res = nxt;
		}
		cout << res << "\n";
	}
	return 0;
}