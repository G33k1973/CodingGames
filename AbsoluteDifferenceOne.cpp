#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
char space = ' ';
typedef unsigned long long int ll;
void solve(ll n) {
	if (n < 10) {
		cout << "-1\n";
		return;
	}
	string s = to_string(n);
	std::size_t mm = s.size();
	std::queue<std::string> pile;
	for (int i = 1; i <= 9; ++i) {
		pile.push(string(1, '0' + i));
	}
	bool alarm = 0;
	while (!pile.empty()) {
		int m = static_cast<int>(pile.size());
		for (int i = 0; i < m; ++i) {
			string temp = pile.front();
			pile.pop();
			if (temp.size() == mm) {
				if (!alarm)alarm = !alarm;
				if (temp <= s)cout << temp << space;
				continue;
			}
			if (temp.size() > 1)cout << temp << space;
			char x = temp.back();
			if (x > '0') {
				temp.pb(x - 1);
				pile.push(temp);
				temp.pop_back();
			}
			if (x >= '0'&&x < '9') {
				temp.pb(x + 1);
				pile.push(temp);
				temp.pop_back();
			}

		}
		if (alarm ^ 0)break;
	}
	cout << '\n';
	return;
}
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;
		solve(n);
	}
	return 0;
}