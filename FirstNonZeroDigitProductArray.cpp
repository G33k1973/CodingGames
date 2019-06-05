#include <bits/stdc++.h>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		cpp_int res = 1;
		bool fail = 0;
		for (int i = 0; i < n; ++i) {
			cpp_int y;
			cin >> y;
			if (y == 1 || fail)continue;
			if (y == 0) {
				fail = !fail;
			}
			res *= y;
		}
		if (fail)cout << "-1\n";
		else {
			cpp_int d = -1;
			while (res > 0) {
				cpp_int rem = res % 10;
				if (rem > 0) {
					d = rem;
					break;
				}
				res /= 10;
			}
			cout << d << "\n";
		}
	}
}

