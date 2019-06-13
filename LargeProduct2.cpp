#include <iostream>
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		cpp_int prod = 1;
		cpp_int sum = 0;
		for (int i = 0; i < n; ++i) {
			cpp_int x;
			cin >> x;
			prod *= x;
			sum += x;
		}
		sum /= n;
		cpp_int res = sum;
		while (1) {
			cpp_int sub = 1;
			cpp_int mul = sum;
			for (cpp_int i = 1; i <= n; ++i) {
				sub *= sum;
			}
			if (sub > prod) {
				res = sum;
				--sum;
			}
			else if (sub == prod) {
				res = sum;
				break;
			}
			else {
				break;
			}
		}
		cout << res << "\n";
	}
	return 0;
}