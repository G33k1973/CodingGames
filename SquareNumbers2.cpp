#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
bool isSquareFree(int n)
{
	if (n % 2 == 0)
		n = n / 2;

	// If 2 again divides n, then n is  
	// not a square free number. 
	if (n % 2 == 0)
		return false;

	// n must be odd at this point.  So we can   
	// skip one element (Note i = i +2) 
	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		// Check if i is a prime factor 
		if (n % i == 0)
		{
			n = n / i;

			// If i again divides, then  
			// n is not square free 
			if (n % i == 0)
				return false;
		}
	}

	return true;
}

int solve(int n) {
	int res = n - 1;
	for (int i = 2; i <= n; ++i) {
		if (isSquareFree(i))--res;
	}
	return res;
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
}