#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		string s("");
		cin >> s;
		int l = static_cast<int>(s.size());
		int c = -1;
		for (int i = 0; i < l; ++i) {
			char x = s.at(i);
			int ix;
			++c;
			if (isupper(x)) {
				ix = static_cast<int>(x) - 10 + c;
			}
			else if (islower(x)) {
				ix = static_cast<int>(x) - 10 + c;
			}
			cout << ix;
		}
		cout << "\n";
	}
	return 0;
}