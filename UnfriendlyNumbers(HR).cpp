#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long int;
vector<ll> getdivisors(ll x) {
	vector<ll> temp{ x };
	for (ll i = 2ULL; i*i <= x; ++i) {
		if (x%i == 0) {
			ll d1 = i, d2 = x / i;
			temp.push_back(d1);
			if (d1 != d2)temp.push_back(d2);
		}
	}
	return temp;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	int n;
	ll fr;
	cin >> n >> fr;
	unordered_map<ll, int> dict;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		dict[x]++;
	}
	vector<ll> divisors = getdivisors(fr);//move constructor invoked
	ll count(0ULL);
	for (auto& y : divisors) {
		bool suc = true;
		for (auto& x : dict) {
			if (y > x.first)continue;
			if (x.first%y == 0) {
				suc = false;
				break;
			}
		}
		if (suc ^ 0)++count;
	}
	cout << count;
	return 0;
}

