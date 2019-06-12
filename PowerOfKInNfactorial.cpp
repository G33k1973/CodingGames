#include <bits/stdc++.h>
#include <iostream>
using namespace std;
std::vector<pair<int, int>> a;
#define pb push_back
#define mp make_pair
int solve(int n) {
	int res = INT_MAX;
	for (const auto& x : a) {
		int k = x.first;
		int val = k;
		int exponent = 0;
		while ((n / val) > 0) {
			exponent += n / val;
			val *= k;
		}
		int subres = exponent / x.second;
		res = min(res, subres);
	}
	return res;
}
void generate(int n) {
	int c = 0;
	while (n % 2 == 0) {
		++c;
		n /= 2;
	}
	if (c > 0)a.pb(mp(2, c));
	for (int i = 3; i*i <= n; i += 2) {
		c = 0;
		while (n%i == 0) {
			++c;
			n /= i;
		}
		if (c)a.pb(mp(i, c));
	}
	if (n > 1)a.pb(mp(n, 1));
}
int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		if (!a.empty())a.clear();
		int n, k;
		cin >> n >> k;
		generate(k);
		cout << solve(n) << endl;
	}
	return 0;
}