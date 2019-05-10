https://practice.geeksforgeeks.org/problems/different-ways-to-spell-a-number/0
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
using ll = unsigned long long int;
#define pb push_back
ll count_(ll c) {
	return (1ULL << (c - 1));
}
int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		string s("");
		cin >> s;
		vector<ll> arr;
		int l = static_cast<int>(s.size());
		int i = 0;
		char p = '@';
		ll c = 0;
		for (i = 0; i < l; ++i) {
			if (p == '@' || (i > 0 && s[i] == p)) {
				++c;
			}
			else {
				arr.pb(count_(c));
				c = 1;
			}
			p = s.operator[](i);
		}
		arr.pb(count_(c));
		ll res = 1;
		for (const auto& x : arr) {
			res *= x;
		}
		cout << res << "\n";
	}
	return 0;
}