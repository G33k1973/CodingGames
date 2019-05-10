//https://practice.geeksforgeeks.org/problems/maximum-value/0

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto& x : a)cin >> x;
		if (n < 4) {
			cout << "-1\n";
			continue;
		}
		int ai = a[0], aj = a[1];
		int best = aj - ai;
		int mn = a[0];
		vector<int> FromLeft(n, 0);
		for (int i = 1; i < n - 2; ++i) {
			if (i == 1) {
				FromLeft[i] = aj - ai;
			}
			else {
				FromLeft[i] = std::max(best, a[i] - mn);
			}
			best = std::max(best, FromLeft[i]);
			mn = std::min(mn, a[i]);
		}
		reverse(begin(a), end(a));
		ai = a[0], aj = a[1];
		int mx = a[0];
		best = INT_MIN;
		vector<int> FromRight(n, 0);
		for (int i = 1; i < n - 2; ++i) {
			int j = n - i - 1;
			if (i == 1) {
				FromRight[j] = ai - aj;
			}
			else {
				FromRight[j] = std::max(best, mx - a[i]);
			}
			best = std::max(best, FromRight[j]);
			mx = std::max(mx, a[i]);
			//cout<<mx<<" "<<best<<endl;
		}
		int res = INT_MIN;
		for (int i = 1; i < n - 2; ++i) {
			//cout<<FromLeft[i]<<" "<<FromRight[i+1]<<"\n";
			res = std::max(res, FromLeft[i] + FromRight[i + 1]);
		}
		cout << res << endl;
	}
	return 0;
}