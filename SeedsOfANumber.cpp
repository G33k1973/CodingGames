#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isGood(int a, int b) {
	int res = a;
	while (a) {
		int rem = a % 10;
		if (rem == 0)return 0;
		res *= rem;
		a /= 10;
	}
	return (res == b);
}
vector<int> Solve(int n) {
	vector<int> temp;
	for (int i = 2; i*i <= n; ++i) {
		if (n%i == 0) {
			int d1 = i, d2 = n / i;
			if (d1 == d2) {
				if (isGood(d1, n))temp.push_back(d1);
			}
			else {
				if (isGood(d1, n))temp.push_back(d1);
				if (isGood(d2, n))temp.push_back(d2);
			}
		}
	}
	return std::move(temp);
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> res = Solve(n);
		if (res.empty())cout << "-1\n";
		else {
			sort(begin(res), end(res));
			for (const auto& x : res) {
				cout << x << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}