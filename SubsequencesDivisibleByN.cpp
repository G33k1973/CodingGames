#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define pb push_back
#define ms(a,b) (((a%M)+(b%M))%M)
using ll = unsigned long long int;
std::unordered_set<string> memo;
ll countDivisibleSubseq(string str, ll n)
{
	int len = str.length();

	// division by n can leave only n remainder 
	// [0..n-1]. dp[i][j] indicates number of 
	// subsequences in string [0..i] which leaves 
	// remainder j after division by n. 
	ll dp[len][n];
	memset(dp, 0, sizeof(dp));

	// Filling value for first digit in str 
	dp[0][(str[0] - '0') % n]++;

	for (int i = 1; i < len; i++)
	{
		// start a new subsequence with index i 
		dp[i][(str[i] - '0') % n] = ms(dp[i][(str[i] - '0') % n], 1);

		for (int j = 0; j < n; j++)
		{
			// exclude i'th character from all the 
			// current subsequences of string [0...i-1] 
			dp[i][j] = ms(dp[i - 1][j], dp[i][j]);

			// include i'th character in all the current 
			// subsequences of string [0...i-1] 
			dp[i][(j * 10 + (str[i] - '0')) % n] = ms(dp[i - 1][j], dp[i][(j * 10 + (str[i] - '0')) % n]);
		}
	}

	return dp[len - 1][0];
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int l;
		ll num;
		cin >> l >> num;
		string s("");
		cin >> s;
		{
			ll res = countDivisibleSubseq(s, num);
			cout << res << endl;
		}
	}
	return 0;
}