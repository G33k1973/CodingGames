#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n, x;
		cin >> n >> x;
		int d = n / x;
		int rem = n % x;
		if (rem == 0) {
			int res = (d)*x;
			cout << res << endl;
		}
		else {
			int res1 = d * x;
			int res2 = (d + 1)*x;
			if (res1 == 0) {
				cout << res2 << endl;
				continue;
			}
			int diff1 = n - res1, diff2 = res2 - n;
			if (diff1 < diff2)cout << res1 << "\n";
			else cout << res2 << "\n";
		}
	}
	return 0;
}