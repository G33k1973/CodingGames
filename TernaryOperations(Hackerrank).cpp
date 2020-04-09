#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb push_back
constexpr ll maxpow3 = 10000000000;
constexpr ll mul = 3LL;
vector<ll> pow3;
void init() {
	ll num = 1LL;
	while (1) {
		if (num > maxpow3)break;
		pow3.pb(num);
		num *= mul;
	}
	return;
}
void solve(ll left) {
	vector<ll> fl, fr;
	if (left > 0) {
		vector<int> indexes;
		vector<int> rem2;
		int l = 0;
		while (left > 0) {
			int rem = left % 3;
			if (rem == 2)rem2.pb(l);
			indexes.pb(rem);
			left /= 3;
			++l;
		}
		if (!rem2.empty()) {
			int i = 0;
			while (i < l) {
				if (indexes[i] == 0) {
					++i;
					continue;
				}
				else if (indexes[i] == 1) {
					++i;
					continue;
				}
				else {
					int j{ i };
					int carry = 0;
					int rem, res;
					while (j < l) {
						if (j == i) {
							res = indexes[j] + 1;
							indexes[j] = res % 3;
							carry = res / 3;
							fl.pb(pow3[j]);
							++j;
						}
						else {
							res = indexes[j] + carry;
							carry = res / 3;
							if (res % 3 == 1) {
								indexes[j] = 1;
								break;
							}
							else if (res % 3 == 2) {
								fl.pb(pow3[j]);
								indexes[j] = 0;
								carry = 1;
							}
							else if (res % 3 == 0) {
								indexes[j] = 0;
							}
							++j;
						}
					}
					//cout<<i<<" "<<j<<endl;
					if (carry) {
						indexes.pb(1);
					}
					i = j;
				}
			}
		}
		l = int(indexes.size());
		for (int i = 0; i < l; ++i) {
			if (indexes[i] == 1)fr.pb(pow3[i]);
		}
	}
	reverse(begin(fl), end(fl));
	reverse(begin(fr), end(fr));
	cout << "left pan: ";
	for (int i = 0; i<int(fl.size()); ++i)cout << fl[i] << " ";
	cout << endl;
	cout << "right pan: ";
	for (int i = 0; i<int(fr.size()); ++i)cout << fr[i] << " ";
	cout << endl;
	cout << endl;
	return;
}
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	std::ios::sync_with_stdio(false);
	init();
	int q;
	cin >> q;
	while (q-- > 0) {
		ll left = 0LL;
		cin >> left;
		solve(left);
	}
	return 0;
}
