#include <iostream>
#include <bits/stdc++.h>
using namespace std;
std::unordered_map<char, int> hs{ {'R',0},{'B',1},{'Y',2},{'G',3} };
std::unordered_map<int, char> hs2{ {0,'R'},{1,'B'},{2,'Y'},{3,'G'} };
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		string s("");
		int sol[4] = { 0 };
		cin >> s;
		int j = -1;
		int l = (int)s.size();
		int i = 0;
		int c = 0;
		int h[4] = { 0 };
		while (i < l) {
			if (s[i] == '!') {
				++i;
				if (c) {
					memset(h, 0, sizeof(h));
					c = 0;
				}
				continue;
			}
			else {
				if (c == 0)j = i;
				++h[hs[s[i]]];
				++c, ++i;
				if (c == 4) {
					break;
				}
			}
		}
		int h2[4] = { 0 };
		memcpy(h2, h, sizeof(h));
		for (i = j - 1; i >= 0; --i) {
			if (s[i] != '!') {
				--h[hs[s[i + 4]]];
				++h[hs[s[i]]];
			}
			else {
				--h[hs[s[i + 4]]];
				for (int k = 0; k < 4; ++k) {
					if (h[k] == 0) {
						++sol[k];
						++h[k];
						s[i] = hs2[k];
						break;
					}
				}
			}
		}
		for (i = j + 4; i < l; ++i) {
			if (s[i] != '!') {
				--h2[hs[s[i - 4]]];
				++h2[hs[s[i]]];
			}
			else {
				--h2[hs[s[i - 4]]];
				for (int k = 0; k < 4; ++k) {
					if (h2[k] == 0) {
						++sol[k];
						++h2[k];
						s[i] = hs2[k];
						break;
					}
				}
			}
		}
		for (int k = 0; k < 4; ++k) {
			cout << hs2[k] << sol[k];
		}
		cout << endl;
	}
	return 0;
}