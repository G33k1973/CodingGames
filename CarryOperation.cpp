#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(string x, string y, int &ans) {
	int n = static_cast<int>(x.size());
	int m = static_cast<int>(y.size());
	reverse(begin(x), end(x));
	reverse(begin(y), end(y));
	int i = 0, j = 0, c = 0;
	while (i < n&&j < m) {
		int fx = x[i] - '0';
		int fy = y[j] - '0';
		int res = fx + fy + c;
		c = res / 10;
		if (c > 0)++ans;
		++i, ++j;
	}
	while (j < m) {
		int fy = y[j] - '0';
		int res = fy + c;
		c = res / 10;
		if (c > 0)++ans;
		++j;
	}
	while (i < n) {
		int fx = x[i] - '0';
		int res = fx + c;
		c = res / 10;
		if (c > 0)++ans;
		++i;
	}
	while (c > 0) {
		c /= 10;
		if (c > 0)++ans;
	}
	return;
}
using ll = unsigned long long int;
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		ll X, Y;
		cin >> X >> Y;
		string x = to_string(X);
		string y = to_string(Y);
		int res = 0;
		solve(x, y, res);
		cout << res << "\n";
	}
	return 0;
}