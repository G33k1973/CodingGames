#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
#define pb push_back
vector<pair<ll, ll>> fact;
#define mp make_pair
void init(ll n) {
	ll res = 1;
	fact.pb(mp(res, 1ULL));
	ll i = 1;
	while (1) {
		++i;
		ll latest = i * res;
		if (latest > n)break;
		fact.pb(mp(latest, i));
		res = latest;
	}
	return;
}
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	ll nx = 0;
	vector<ll> a;
	while (q--) {
		ll n;
		cin >> n;
		a.pb(n);
		if (nx < n)nx = n;
	}
	init(nx);
	for (auto& x : a) {
		ll val = x;
		auto ptr = begin(fact);
		while (ptr != end(fact)) {
			ll factorial = ptr->first;
			if (factorial > val)break;
			cout << ptr->first << " ";
			++ptr;
		}
		cout << endl;
	}
	return 0;
}