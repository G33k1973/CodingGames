//https://practice.geeksforgeeks.org/problems/maximum-occured-integer/0/?track=PC-W2-A&amp;batchId=130
#include <iostream>
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;
using ll = long long int;
#define MAX 100005
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n;
		sc = scanf("%d", &n);
		vector<ll> dp(MAX, 0);
		int ll = INT_MAX;
		int rr = INT_MIN;
		for (int i = 0; i < n; ++i) {
			int l;
			sc = scanf("%d", &l);
			if (l < ll)ll = l;
			++dp[l];
		}
		for (int i = 0; i < n; ++i) {
			int r;
			sc = scanf("%d", &r);
			if (r > rr)rr = r;
			--dp[r + 1];
		}
		int res = dp[ll], ix = ll;
		for (int i = ll + 1; i <= rr; ++i) {
			dp[i] += dp[i - 1];
			if (dp[i] > res) {
				res = dp[i];
				ix = i;
			}
		}
		printf("%d\n", ix);
	}
	return 0;
}