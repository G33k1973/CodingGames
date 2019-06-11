#include<bits/stdc++.h>
#include<iostream>
using namespace std;
using ll = unsigned long long int;
vector<bool> memo;
void solve(ll b) {
	memo.assign(b + 1, 0);
	ll sum = 0;
	for (auto i = 1ULL; i <= b; ++i) {
		auto j = i;
		int c = -1;
		while (j) {
			++c;
			if (c == 1) {
				if (j % 2) {
					c = 1;
				}
				else {
					c = 0;
				}
				break;
			}
		}
		if (c == 1)memo.operator[](i) = 1;
	}
	return;
}
#define mp make_pair
#define pb push_back
typedef std::pair<ll, ll> llp;
int main(int argc, char ** argv) {
	int q;
	int sc = scanf("%d", &q);
	vector<llp> temp;
	ll bx = 0;
	while (q--) {
		ll a, b;
		sc = scanf("%d %d", &a, &b);
		temp.pb(mp(a, b));
		if (b > bx)bx = b;
	}
	solve(bx);
	for (const auto& x : temp) {
		ll l = x.first, r = x.second;
		ll res = 0;
		for (ll i = l; i <= r; ++i) {
			if (memo.at(i))++res;
		}
		printf("%llu\n", res);
	}
	return 0;
}