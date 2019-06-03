#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Function to return trailing  
// 0s in factorial of n 
int findTrailingZeros(int n)
{
	// Initialize result 
	int count = 0;

	// Keep dividing n by powers of  
	// 5 and update count 
	for (int i = 5; n / i >= 1; i *= 5)
		count += n / i;

	return count;
}

int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int res = 0;
		int st = 0;
		while (1) {
			int cnt = findTrailingZeros(st);
			if (cnt > n)break;
			if (cnt == n)++res;
			++st;
		}
		cout << res << endl;
	}
}