#include <iostream>
#include <stdexcept>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		int res = INT_MIN;
		int fail = 0;
		try {
			int c = 0, d = 0;
			while (c < 4) {
				if (c == 0) {
					d = a + b;
				}
				else if (c == 1) {
					d = a - b;
				}
				else if (c == 2) {
					d = a * b;
				}
				else if (c == 3) {
					if (b == 0)throw runtime_error("error");
					d = a / b;
				}
				res = max(res, d);
				++c;
			}
		}
		catch (std::runtime_error& e) {
			cout << "inf\n";
			continue;
		}
		cout << res << "\n";
	}
	return 0;
}