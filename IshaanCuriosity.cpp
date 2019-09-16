#include<bits/stdc++.h>
#include<iostream>
using namespace std;
using ll = unsigned long long int;
#define N 64
int c;
int MSBPosition(ll x) {
	int msbp = -1;
	while (x) {
		x >>= 1;
		++msbp;
	}
	return msbp;
}
ll solve(ll L, ll R) {
	ll res = 0;
	// Find the MSB position in L 
	int msb_p1 = MSBPosition(L);

	// Find the MSB position in R 
	int msb_p2 = MSBPosition(R);

	while (msb_p1 == msb_p2) {
		long long int res_val = (1 << msb_p1);

		// Add this value until msb_p1 and 
		// msb_p2 are same; 
		res += res_val;

		L -= res_val;
		R -= res_val;

		// Calculate msb_p1 and msb_p2 
		msb_p1 = MSBPosition(L);
		msb_p2 = MSBPosition(R);
	}
	// Find the max of msb_p1 and msb_p2 
	msb_p1 = max(msb_p1, msb_p2);

	// Set all the bits from msb_p1 upto 
	// 0th bit in the result 
	for (int i = msb_p1; i >= 0; i--) {
		long long int res_val = (1 << i);
		res += res_val;
	}
	return res;
}

int main(int argc, char ** argv) {
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		ll l, r;
		sc = scanf("%llu %llu", &l, &r);
		ll result = solve(l, r);
		printf("%llu\n", result);
	}
}
