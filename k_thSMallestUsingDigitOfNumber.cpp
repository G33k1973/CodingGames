#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		string s("");
		cin >> s;
		int c0 = 0;
		string t("");
		for (auto& x : s) {
			if (x != '0') {
				t.push_back(x);
			}
			else ++c0;
		}
		int k;
		cin >> k;
		--k;
		sort(begin(t), end(t), less<char>());
		while (k-- > 0) {
			std::next_permutation(begin(t), end(t));
		}
		t.insert(1, c0, '0');
		cout << t << "\n";
	}
	return 0;
}