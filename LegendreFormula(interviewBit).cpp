using ll = unsigned long long int;
#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
ll mul(ll a, ll b) {
	ll res = 0;
	a %= M;
	while (b > 0) {
		if (b & 1)res = ms(res, a);
		b >>= 1;
		a = (a * 2) % M;
	}
	return (res%M);
}
ll fex(ll a, ll b) {
	ll res = 1LL;
	a %= M;
	while (b > 0) {
		if (b & 1)res = mul(res, a);
		b >>= 1;
		a = mul(a, a);
	}
	return res;
}
// allPrimes[] stores all prime numbers less 
// than or equal to n. 
vector<ll> allPrimes;

// Fills above vector allPrimes[] for a given n 
void sieve(ll n)
{
	// Create a boolean array "prime[0..n]" and 
	// initialize all entries it as true. A value 
	// in prime[i] will finally be false if i is 
	// not a prime, else true. 
	vector<bool> prime(n + 1, true);

	// Loop to update prime[] 
	for (ll p = 2; p <= n; p++)
	{
		// If prime[p] is not changed, then it 
		// is a prime 
		if (prime[p] == true)
		{
			// Update all multiples of p 
			for (int i = p * 2; i <= n; i += p)
				prime[i] = false;
		}
	}

	// Store primes in the vector allPrimes 
	for (int p = 2; p <= n; p++)
		if (prime[p])
			allPrimes.push_back(p);
}

// Function to find all result of factorial number 
int Solution::solve(int A)
{
	if (A == 1)return 1;
	if (allPrimes.size() > 0)allPrimes.clear();
	ll n = static_cast<ll>(A);
	sieve(n);  // create sieve 

	// Initialize result 
	ll result = 1LL;

	// find exponents of all primes which divides n 
	// and less than n 
	for (int i = 0; i < allPrimes.size(); i++)
	{
		// Current divisor 
		ll p = allPrimes[i];

		// Find the highest power (stored in exp)' 
		// of allPrimes[i] that divides n using 
		// Legendre's formula. 
		ll exp = 0;
		while (p <= n)
		{
			exp = exp + (n / p);
			p = p * allPrimes[i];
		}

		// Using the divisor function to calculate 
		// the sum 
		ll pw1 = fex(allPrimes[i], exp + 1LL);
		pw1 = (pw1 + M - 1LL) % M;
		ll den = allPrimes[i] - 1LL;
		ll pw2 = fex(den, M - 2);
		result = mul(result, pw1);
		result = mul(result, pw2);
		/*
		result = result * (pow(allPrimes[i], exp + 1) - 1) /
			(allPrimes[i] - 1);
		*/
	}
	// return total divisors 
	return int(result);
}