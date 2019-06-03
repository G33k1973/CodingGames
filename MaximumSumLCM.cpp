#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int res = 0;
		for (int i = 1; i*i <= n; ++i) {
			if (n%i == 0) {
				int d1 = i, d2 = n / i;
				if (d1 == d2)res += d1;
				else res += d1 + d2;
			}
		}
		cout << res << endl;
	}
	return 0;
}