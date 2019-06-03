#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, string> h{
	{1,"one"},{2,"two"},{3,"three"},{4,"four"},{5,"five"},{6,"six"},{7,"seven"},{8,"eight"},{9,"nine"},{10,"ten"},
	{11,"eleven"},{12,"twelve"},{13,"thirteen"},{14,"fourteen"},{15,"fifteen"},{16,"sixteen"},{17,"seventeen"},
	{18,"eighteen"},{19,"nineteen"},{20,"twenty"},{30,"thirty"},{40,"forty"},{50,"fifty"},{60,"sixty"},{70,"seventy"},
	{80,"eighty"},{90,"ninety"}
};
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> dig;
		int m = n;
		stack<int> s;
		while (m) {
			s.push(m % 10);
			m /= 10;
		}
		m = (int)s.size();
		dig.assign(m, 0);
		int i = 0;
		while (!s.empty()) {
			dig.at(i++) = s.top();
			s.pop();
		}
		if (m == 1) {
			cout << h[dig[0]] << "\n";
			continue;
		}
		if (m == 2) {
			int num = 10 * dig[0] + dig[1];
			if (num <= 20) {
				cout << h[num] << "\n";
				continue;
			}
			cout << h[dig[0] * 10] << " " << h[dig[1]] << endl;
			continue;
		}
		if (m == 3) {
			cout << h[dig[0]];
			int num = 10 * dig[1] + dig[2];
			if (num == 0) {
				cout << " hundred\n";
				continue;
			}
			if (dig[0] == 1)cout << " hundred and ";
			else cout << " hundred and ";
			if (num <= 20) {
				cout << h[num] << "\n";
				continue;
			}
			cout << h[dig[1] * 10] << " " << h[dig[2]] << endl;
			continue;
		}
		if (m == 4) {
			cout << h[dig[0]];
			if (dig[0] == 1)cout << " thousand";
			else cout << " thousand";
			if (dig[1] == 0 && dig[2] == 0 && dig[3] == 0) {
				cout << endl;
				continue;
			}
			cout << " ";
			if (dig[1] > 0) {
				cout << h[dig[1]];
				if (dig[1] == 1)cout << " hundred";
				else cout << " hundred";
			}
			int num = 10 * dig[2] + dig[3];
			if (num == 0) {
				cout << "\n";
				continue;
			}
			cout << " and ";
			if (num <= 20) {
				cout << h[num] << "\n";
				continue;
			}
			cout << h[dig[2] * 10] << " " << h[dig[3]] << endl;
			continue;
		}
	}
	return 0;
}