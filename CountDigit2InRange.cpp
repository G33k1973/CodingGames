{
// C++ program to count 2s from 0 to n
#include <bits/stdc++.h>
using namespace std;
/* Counts the number of 2s in a number at d-th
   digit */
long long int count2sinRangeAtDigit(long long int number, long long int d);
/* Counts the number of '2' digits between 0 and n */
long long int numberOf2sinRange(long long int number);
// Driver Coden
int main()
{
	long long int n;
	long long int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << numberOf2sinRange(n) << endl;
	}
	return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/* Counts the number of 2s in a number at d-th
   digit */
typedef long long int ll;
long long int count2sinRangeAtDigit(long long int number, long long int d)
{
	// Your code goes here
	ll sub = 0;
	while (number) {
		int rem = number % 10;
		if (rem == d)++sub;
		number /= 10;
	}
	return sub;
}
/* Counts the number of '2' digits between 0 and n */
long long int numberOf2sinRange(long long int number)
{
	// Your code goes here
	ll res = 0;
	for (ll i = 0; i <= number; ++i) {
		res += count2sinRangeAtDigit(i, static_cast<ll>(2));
	}
	return res;
}