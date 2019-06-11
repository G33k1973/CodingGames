#include<bits/stdc++.h>
#include<iostream>
using namespace std;
using ll = unsigned long long int;
int solve(ll n) {
	if (n == 1)return 0;
	int c = 0;
	int res = 0;
	while (n % 2 == 0) {
		if (!c)c = !c;
		n /= 2;
	}
	if (c > 0)++res;
	for (ll i = 3; i*i <= n; i += 2) {
		c = 0;
		while (n%i == 0) {
			if (!c)++c;
			n /= i;
		}
		if (c)++res;
	}
	if (n > 1)++res;
	return res;
}

int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;
		cout << solve(n) << "\n";
	}
	return 0;
}