#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#include <bits/stdc++.h> 
using namespace std;

// function to check if the sum of digits is 
// equal to the summation assumed 
bool check(long long a, long long b)
{
	long long int c = 0;

	// calculate the sum of digit 
	while (a != 0) {
		c = c + a % 10;
		a = a / 10;
	}

	return (c == b);
}

// function to find the largest root possible. 
long long root(long long n)
{
	bool found = 0;
	long long mx = 1e18;

	// iterate for all possible sum of digits. 
	for (long long i = 0; i <= 90; i++) {

		// check if discriminent is a perfect square. 
		long long s = i * i + 4 * n;
		long long sq = sqrt(s);

		// check if discriminent is a perfect square and 
		// if it as perefect root of the equation 
		if (sq * sq == s && check((sq - i) / 2, i)) {
			found = 1;
			mx = min(mx, (sq - i) / 2);
		}
	}

	// function returns answer 
	if (found)
		return mx;
	else
		return -1;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;
		cout << root(n);
		cout << endl;
	}
	return 0;
}