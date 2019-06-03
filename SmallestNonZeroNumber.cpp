#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
ll suitable_num(ll a[], int n)
{
	ll num = 0;

	// Calculating the suitable number at each step. 
	for (int i = n - 1; i >= 0; i--)
		num = round((a[i] + num) / 2.0);

	return num;
}
int main(int argc, char ** argv) {
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n;
		sc = scanf("%d", &n);
		int mx = INT_MIN;
		vector<ll> a(n);
		for (auto&x : a) {
			sc = scanf("%llu", &x);
		}
		ll res = suitable_num(a.data(), n);
		printf("%llu\n", res);
	}
}