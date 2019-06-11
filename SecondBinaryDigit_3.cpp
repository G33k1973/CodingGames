#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = unsigned long long int;

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		ll a;
		ll b;
		cin >> a >> b;
		assert(a <= b);
		if (a == b) {
			if (a > 1) {
				ll rem = (a - 2) % 4;
				if (rem == 0 || rem == 1)cout << "1\n";
			}
			else {
				cout << "0\n";
			}
			continue;
		}
		else if (a + 1 == b) {
			if (a == 1) {
				cout << "1\n";
				continue;
			}
			ll rem = (a - 2) % 4;
			if (rem == 0)cout << "2\n";
			else if (rem == 1)cout << "1\n";
			else cout << "0\n";
			continue;
		}
		else {
			ll r1 = (a == 1) ? (3) : ((a - 2) % 4);
			ll r2 = (b - 2) % 4;
			ll d1 = (a == 1) ? (0) : ((a - 2) / 4);
			ll d2 = (b - 2) / 4;
			ll res = 0;
			if (r1 == 0) {
				res += 2;
				++d1;
			}
			else if (r1 == 1) {
				++res;
				++d1;
			}
			else {
				ll temp = 4ULL * d1;
				//if (temp > 0 && temp < a)
				++d1;
			}
			if (r2 == 0) {
				++res;
				--d2;
			}
			else if (r2 == 1) {
				res += 2;
				--d2;
			}
			else {
				ll temp = 4ULL * d2;
				if (temp > b)--d2;
			}
			//cout<<res<<endl;
			res += (d2 - d1 + 1ULL) * 2ULL;
			if (a == 1)res += 2;
			cout << res << "\n";
		}
	}
}