// Program to find factorial that N belongs to 
#include <bits/stdc++.h> 
using namespace std;
#define ull unsigned long long 

// Calculate prime factors for a given number 
map<ull, int> primeFactors(ull num)
{
	// Container for prime factors 
	map<ull, int> ans;

	// Iterate from 2 to i^2 finding all factors 
	for (ull i = 2; i * i <= num; i++)
	{
		while (num % i == 0)
		{
			num /= i;
			ans[i]++;
		}
	}

	// If we still have a remainder 
	// it is also a prime factor 
	if (num > 1)
		ans[num]++;
	return ans;
}

// Calculate occurence of an element 
// in factorial of a number 
ull legendre(ull factor, ull num)
{
	ull count = 0, fac2 = factor;
	while (num >= factor)
	{
		count += num / factor;
		factor *= fac2;
	}
	return count;
}

bool possible(map<ull, int> &factors, ull num)
{
	// Iterate through prime factors 
	for (map<ull, int>::iterator it = factors.begin();
		it != factors.end(); ++it)
	{
		// Check if factorial contains less 
		// occurences of prime factor 
		if (legendre(it->first, num) < it->second)
			return false;
	}
	return true;
}

// Function to binary search 1 to N 
ull search(ull start, ull end, map<ull, int> &factors)
{
	ull mid = (start + end) / 2;

	// Prime factors are not in the factorial 
	// Increase the lowerbound 
	if (!possible(factors, mid))
		return search(mid + 1, end, factors);

	// We have reached smallest occurrence 
	if (start == mid)
		return mid;

	// Smaller factorial satisfying 
	// requirements may exist, decrease upperbound 
	return search(start, mid, factors);
}

// Calculate prime factors and search 
ull findFact(ull num)
{
	map<ull, int> factors = primeFactors(num);
	return search(1, num, factors);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		ull n;
		cin >> n;
		cout << findFact(n) << "\n";
	}
	return 0;
}