#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define N 255

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		string s("");
		cin >> s;
		int res = 0;
		int i;
		int l = static_cast<int>(s.size());
		for (i = 1; i < l - 1; ++i) {
			int c = 0;
			char fix = ' ';
			int L = i - 1, H = i + 1;
			while (L >= 0 && H < l) {
				if (c == 0) {
					if (s[L] != s[H])break;
					fix = s.at(L);
					++c;
				}
				else {
					if (s[L] != s[H] || (s[L] == s[H] && s[L] != fix))break;
				}
				++res;
				--L, ++H;
			}
		}
		for (i = 0; i < l - 1; ++i) {
			char c = s.at(i);
			int j = i + 1;
			while (j < l) {
				int dist = j - i + 1;
				if (s[j] == c && (!(dist & 1)))++res;
				if (s[j] != c)break;
				++j;
			}
		}
		cout << res << "\n";
	}
	return 0;
}