#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define pb push_back
#define mp make_pair


int main() {
	int q;
	cin >> q;
	while (q--) {
		string s("");
		cin >> s;
		if (is_sorted(begin(s), end(s))) {
			cout << "-1\n";
			continue;
		}
		std::prev_permutation(begin(s), end(s));
		s += "\n";
		cout << s;
	}
}