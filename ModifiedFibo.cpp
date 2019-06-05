#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define M 1000000007
ll solve(ll a, ll b, ll c, ll n) {
	vector<ll> arr{ (a%M + M - c % M) % M,(a%M + b % M) % M,(b%M + c % M) % M,(c%M + M - a % M) % M,(M - a % M - b % M) % M,(M - b % M - c % M) % M };
	n %= 6;
	return arr.at(n);
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		ll a, b, c, n;
		cin >> n >> a >> b >> c;
		ll res = solve(a, b, c, n);
		cout << res << endl;
	}
	return 0;
}