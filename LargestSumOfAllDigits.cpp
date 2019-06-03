#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void updateRes(const string& s, int& res) {
	int sub = 0;
	for (const auto& x : s)sub += (x - '0');
	res = std::max(res, sub);
	return;
}
std::string GetString(int x) {
	string s("");
	std::stack<char> pile;
	while (x) {
		pile.push((x % 10) + '0');
		x /= 10;
	}
	while (!pile.empty()) {
		s.push_back(pile.top());
		pile.pop();
	}
	return std::move(s);
}
void solve(int& res, int n) {
	for (int i = 1; i*i <= n; ++i) {
		if (n%i == 0) {
			int d1 = i, d2 = n / i;
			if (d1 == d2) {
				updateRes(GetString(d1), res);
			}
			else {
				updateRes(GetString(d1), res);
				updateRes(GetString(d2), res);
			}
		}
	}
	return;
}
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int res = INT_MIN;
		solve(res, n);
		cout << res << "\n";
	}
	return 0;
}