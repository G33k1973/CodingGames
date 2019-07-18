#include <iostream>
#include <bits/stdc++.h>

int Xo[] = { -1,+1,+1,0,0,+1 };
int Y[] = { 0,-1,+1,-1,+1,0 };
int Xe[] = { -1,-1,-1,0,0,+1 };

int N = sizeof(Xo) / sizeof(Xo[0]);

bool isvalid(int i, int j, int n, int m) {
	return (i >= 0 && j >= 0 && i < n&&j < m);
}

int main(int argc, char ** argv) {
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n, m;
		sc = scanf("%d %d", &n, &m);
		int dp[n][m];
		memset(dp, 0, sizeof(dp));
		int i, j;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				int& x = dp[i][j];
				sc = scanf("%d", &x);
			}
		}
		int k, r, c;
		sc = scanf("%d %d %d", &k, &r, &c);
		if (k == 0) {
			int res = 0;
			int u = 0;
			int * ptrX = (c & 1) ? (Xo) : (Xe);
			while (u < N) {
				int nr = r + ptrX[u];
				int nc = c + Y[u];
				if (isvalid(nr, nc, n, m)) {
					res += dp[nr][nc];
				}
				++u;
			}
			printf("%d\n", res);
		}
		else if (k == 1) {
			bool vis[n][m];
			memset(vis, 0, sizeof(vis));
			vis[r][c] = 1;
			std::queue<std::pair<int, int>> pile;
			int res = 0;
			int u = 0;
			int * ptrX = (c & 1) ? (Xo) : (Xe);
			while (u < N) {
				int nr = r + ptrX[u];
				int nc = c + Y[u];
				if (isvalid(nr, nc, n, m)) {
					pile.push(std::make_pair(nr, nc));
					vis[nr][nc] = 1;
				}
				++u;
			}
			while (!pile.empty()) {
				std::pair<int, int> temp = pile.front();
				pile.pop();
				int nr = temp.first;
				int nc = temp.second;
				int * ptrX = (nc & 1) ? (Xo) : (Xe);
				int u = 0;
				while (u < N) {
					int nnr = nr + ptrX[u];
					int nnc = nc + Y[u];
					if (isvalid(nnr, nnc, n, m) && !vis[nnr][nnc]) {
						vis[nnr][nnc] = 1;
						res += dp[nnr][nnc];
					}
					++u;
				}
			}
			printf("%d\n", res);
		}
	}
}