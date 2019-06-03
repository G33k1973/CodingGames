#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int x[] = { -1,-1,-2,-2,+1,+1,+2,+2 };
int y[] = { -2,+2,-1,+1,-2,+2,-1,+1 };

bool isvalid(int i, int j, int n, int m) {
	return (i >= 0 && j >= 0 && i < n&&j < m);
}

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n, m;
		cin >> n >> m;
		int res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int subres = n * m - 1;
				for (int k = 0; k < 8; ++k) {
					int ni = i + x[k];
					int nj = j + y[k];
					if (isvalid(ni, nj, n, m))--subres;
				}
				res += subres;
			}
		}
		cout << res << "\n";
	}
	return 0;
}