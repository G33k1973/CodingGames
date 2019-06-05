#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int l;
		cin >> l;
		string s("");
		cin >> s;
		int c = 0;
		for (int i = l - 1; i >= 0; --i) {
			int x = (s[i] - '0') + c;
			if (i == (l - 1))++x;
			s[i] = (x % 2) + '0';
			c = x / 2;
			if (c == 0)break;
		}
		if (c == 1)s.insert(begin(s), 1, '1');
		cout << s << "\n";
	}
	return 0;
}