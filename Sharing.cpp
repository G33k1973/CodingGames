#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		if (n < k)cout << n;
		else {
			int res = 0;
			for (int i = 2; i <= k; ++i) {
				if (n%i == 0)continue;
				res = max(res, n - (n / i)*i);
			}
			cout << res;
		}
		cout << endl;
	}
	return 0;
}