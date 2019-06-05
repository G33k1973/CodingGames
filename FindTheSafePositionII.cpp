#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<bool> vis(n, false);
		int i = 0;
		int j = 0;
		int k = 0;
		int res = 1;
		int m = n;
		while (m > 1) {
			j = (i + 1) % n;
			res = i + 1;
			while (vis[j] == true) {
				j = (j + 1) % n;
			}
			vis[j] = true;
			--m;
			if (m == 1)break;
			i = (j + 1) % n;
			while (vis[i] == true) {
				i = (i + 1) % n;
			}
		}
		cout << res << "\n";
	}
}