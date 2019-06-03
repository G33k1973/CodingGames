#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = unsigned long long int;
vector<ll> faithful, p7;
#define pb push_back

void dfs(const std::vector<ll>& a, int n, int i, ll& num) {
	if (i == n) {
		return;
	}
	faithful.pb(num);
	for (int j = i; j < n; ++j) {
		num += a[j];
		dfs(a, n, j + 1, num);
		num -= a[j];
	}
	return;
}

void init() {
	ll mul = 1ULL;
	p7 = vector<ll>{ 1 };
	for (int i = 2; i <= 20; ++i) {
		ll x = mul * 7;
		p7.push_back(x);
		mul = x;
	}
	return;
}

ll solve(int n) {
	std::queue<int> bin;
	while (n > 0) {
		int rem = n % 2;
		bin.push(rem);
		n /= 2;
	}
	int j = 0;
	ll res = 0;
	while (!bin.empty()) {
		int bit = bin.front();
		if (bit == 1)res += p7[j];
		++j;
		bin.pop();
	}
	return res;
}

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	init();
	while (q--) {
		int n;
		cin >> n;
		cout << solve(n) << "\n";
	}
}