#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;


	while (t--) {

		int n, w, p, i, j;
		cin >> n >> w >> p;
		vector<int>wt(n), val(n);

		for (i = 0; i < n; i++)
			cin >> wt[i] >> val[i];


		vector<vector<int> >dp(n + 1, vector<int>(w + 1, 0));

		for (i = 0; i <= n; i++) {

			for (j = 0; j <= w; j++) {

				if (i == 0 || j == 0)
					dp[i][j] = 0;

				else if (j >= wt[i - 1])
					dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);

				else
					dp[i][j] = dp[i - 1][j];
			}
		}

		int res = dp[n][w];

		if (res < p)cout << "NO";
		else {

			int ans = 0;
			for (i = n; i > 0 && res > 0; i--) {

				if (res == dp[i - 1][w])
					continue;
				else {

					ans = ans + wt[i - 1];

					res = res - val[i - 1];
					w = w - wt[i - 1];
				}
			}
			cout << "YES" << " " << ans;

		}
		cout << endl;
	}
	return 0;
}