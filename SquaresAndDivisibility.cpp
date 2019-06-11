#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define pb push_back
#define mp make_pair
void solve(int n) {
	vector<pair<int, int>> a;
	int i = 1;
	while (i <= n) {
		int j = i * i - 1;
		a.pb(mp(i, j));
		++i;
	}
	int res = 0;
	int m = static_cast<int>(a.size());
	int j = 0;
	for (i = 0; i < m - 1; ++i) {
		int x = a[i].first;
		int x2m1 = a[i].second;
		for (j = i + 1; j < m; ++j) {
			int y = a[j].first;
			int y2m1 = a[j].second;
			if (x2m1%y == 0 && y2m1%x == 0)++res;
		}
	}
	cout << res << "\n";
}

int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		solve(n);
	}
	return 0;
}