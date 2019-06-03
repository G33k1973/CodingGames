#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define pb push_back
int main(int argc, char ** argv) {
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n;
		sc = scanf("%d", &n);
		vector<int> arr(n);
		for (auto& x : arr)sc = scanf("%d", &x);
		int i = 0;
		int c = 0;
		int r = n;
		int j = 0;
		while (r > 0) {
			int mxnodes = 1 << i;
			int tot = std::min(r, mxnodes);
			vector<int> b;
			for (int k = 0; k < tot; ++k) {
				b.pb(arr[j++]);
			}
			sort(begin(b), end(b));
			for (auto& z : b)cout << z << " ";
			cout << "\n";
			r -= tot;
			++i;
		}
	}
	return 0;
}