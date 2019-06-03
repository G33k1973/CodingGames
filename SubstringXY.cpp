#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		string s("");
		cin >> s;
		//start with y
		int l = static_cast<int>(s.size());
		int i = 0;
		int sy = 1;
		char p = ' ';
		int cnt = 0;
		while (i < l) {
			char c = s.at(i);
			if (sy == 1 && p == 'Y'&&c == 'X') {
				++cnt;
				sy = 0;
				++i;
				p = ' ';
			}
			if (sy == 0 && p == 'X'&&c == 'Y') {
				++cnt;
				break;
			}
			p = c;
			++i;
		}
		if (cnt == 2) {
			cout << "YES\n";
			continue;
		}
		i = 0;
		cnt = 0;
		sy = 0;
		p = ' ';
		while (i < l) {
			char c = s.at(i);
			if (sy == 1 && p == 'Y'&&c == 'X') {
				++cnt;
				break;
			}
			if (sy == 0 && p == 'X'&&c == 'Y') {
				++cnt;
				sy = 1;
				p = ' ';
				++i;
				continue;
			}
			p = c;
			++i;
		}
		if (cnt == 2) {
			cout << "YES\n";
			continue;
		}
		cout << "NO\n";
	}
	return 0;
}