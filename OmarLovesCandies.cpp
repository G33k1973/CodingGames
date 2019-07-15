#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n, m;
		sc = scanf("%d %d", &n, &m);
		int dp[n][m];
		long long int row[n] = { 0 };
		long long int px[n][m];
		memset(px, 0, sizeof(px));
		int i, j;
		for (i = 0; i < n; ++i) {
			int sub = 0;
			for (j = 0; j < m; ++j) {
				sc = scanf("%d", &dp[i][j]);
				px[i][j] = sub;
				sub += dp[i][j];
			}
			row[i] = sub;
		}
		int rmax = n - 1, cmax = m - 1;
		while (rmax >= 0 && dp[rmax][m - 1] > 0)--rmax;
		while (cmax >= 0 && dp[n - 1][cmax] > 0)--cmax;
		if (rmax < 0)++rmax;
		if (cmax < 0)++cmax;
		long long int res = 0;
		bool out = false;
		for (i = rmax; i < n; ++i) {
			long long int sub = 0, prev = 0;
			for (j = cmax; j < m; ++j) {
				sub = 0;
				for (int k = i; k < n; ++k) {
					sub += row[k] - px[k][j];
				}
				if (sub > 0 && sub < prev)break;
				prev = sub;
				res = max(res, sub);
			}
		}
		if (res == 0)res = dp[n - 1][m - 1];
		printf("%lld\n", res);
	}
	return 0;
}
