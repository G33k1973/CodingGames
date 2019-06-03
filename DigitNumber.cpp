#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		ll l, r;
		int k;
		cin >> l >> r >> k;
		ll low = l;
		while (1) {
			int ld = low % 10;
			if (ld == k)break;
			++low;
		}
		if (low > r) {
			cout << 0 << endl;
			continue;
		}
		ll res = (r - low) / 10;
		cout << ++res << "\n";
	}
	return 0;
}