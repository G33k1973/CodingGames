#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		string fa = to_string(a);
		string fb = to_string(b);
		if (fa.size() < fb.size())cout << fb << endl;
		else if (fa.size() == fb.size()) {
			if (a < b)cout << fb << endl;
			else {
				fa = fb;
				fa.insert(0, 1, '1');
				cout << fa << endl;
			}
		}
		else if (fa.size() > fb.size()) {
			string c = fb;
			int difflen = static_cast<int>(fa.size()) - static_cast<int>(fb.size());
			int i = difflen - 1;
			string sub = fa.substr(0, difflen);
			string pos = sub + c;
			if (pos > fa) {
				cout << pos << endl;
				continue;
			}
			int carry = 0;
			while (i >= 0) {
				int val = sub[i] - '0';
				if (i == (difflen - 1)) {
					++val;
					int rem = val % 10;
					carry = val / 10;
					sub[i] = rem + '0';
				}
				else {
					if (carry == 0)break;
					int res = val + carry;
					sub[i] = (res % 10) + '0';
					carry = res / 10;
				}
				--i;
			}
			if (carry) {
				sub.insert(0, 1, '1');
			}
			sub += c;
			cout << sub << "\n";
		}
	}
	return 0;
}