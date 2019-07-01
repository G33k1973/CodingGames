#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long int ll;
ll solve(ll n) {
	ll st_ = n;
	ll res = 1;
	int c = 0;
	while (n % 2 == 0) {
		n /= 2;
		++c;
		if (c == 1)res *= 1;
		else res *= 2;
	}
	for (ll i = 3; i*i <= n; i += 2) {
		c = 0;
		while (n%i == 0) {
			n /= i;
			++c;
			if (c == 1)res *= i - 1;
			else res *= i;
		}
	}
	if (n > 1)res *= (n - 1);
	return res;
}

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		ll x;
		cin >> x;
		ll sub = solve(x);
		if (!(sub & 1))cout << "YES " << sub << "\n";
		else cout << "NO\n";
	}
}