#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char ** argv) {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		std::vector<std::string> g(n, std::string(n, 'X'));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				char& c = g.at(i).at(j);
				cin >> c;
			}
		}
		int res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (g[i][j] == 'X') {
					int w = 0;
					for (int k = j; k < n; ++k) {
						if (g[i][k] == 'X')++w;
						else break;
					}
					int sub = 0;
					int k, kk, kkk;
					for (k = 1; k <= w; ++k) {
						bool fl = 0;
						int B1 = min(n, i + k);
						int B2 = min(j + k, n);
						for (kk = i; kk < B1; ++kk) {
							for (kkk = j; kkk < B2; ++kkk) {
								if (kk > i&&kk<B1 - 1 && kkk>j&&kkk < B2 - 1)continue;
								if (g[kk][kkk] != 'X') {
									fl = 1;
									break;
								}
							}
							if (fl)break;
						}
						if (!fl && (kk - i) == (kkk - j))res = max(res, kk - i);
					}
				}
			}
		}
		cout << res << "\n";
	}
}