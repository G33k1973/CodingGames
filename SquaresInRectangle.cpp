#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
#define M 1000000007
ll solve(ll a, ll b) {
	if (a == b)return 1;
	if (a > b)std::swap(a, b);
	ll res = 0;
	while (1) {
		ll sub = b / a;
		res = (res%M + sub % M) % M;
		ll rem = b % a;
		if (rem == 0)break;
		b = rem;
		if (a > b)std::swap(a, b);
	}
	return res;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		ll a, b;
		cin >> a >> b;
		cout << solve(a, b) << endl;
	}
	return 0;
}