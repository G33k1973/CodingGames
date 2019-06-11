#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	cin >> q;
	cin.ignore();
	while (q--) {
		string s("");
		getline(cin, s);
		int ch = 0, dots = 0, digits = 0;
		for (auto&x : s) {
			if (isdigit(x))++digits;
			else if (isalpha(x))++ch;
			else if (x == '.')++dots;
			else ++ch;
		}
		if (dots == 0 && ch == 0)cout << "4\n";
		else if (ch > 0 || (dots > 1 || dots == 1 && digits == 0)) {
			int l = static_cast<int>(s.size());
			cout << l << "\n";
		}
		else if (dots == 1) {
			auto pos = s.find('.');
			string t = s.substr(pos + 1);
			if (t.size() >= 6)cout << "8\n";
			else cout << "4\n";
		}
	}
	return 0;
}