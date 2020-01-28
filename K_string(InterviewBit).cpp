#define pb push_back
vector<int> Solution::solve(string A) {
	int l = int(A.length());
	vector<int> result;
	if (l == 0)return result;
	if (l == 1)return vector<int>{1};
	vector<vector<bool>> dp(l, vector<bool>(l, false));
	vector<vector<int>> DP(l, vector<int>(l, 0));
	result.assign(l, 0);
	int i, j, cl;
	for (cl = 1; cl <= l; ++cl) {
		for (i = 0; i <= (l - cl); ++i) {
			j = i + cl - 1;
			if (cl == 1) {
				dp[i][j] = true;
				DP[i][j] = 1;
				++result[cl - 1];
			}
			else if (cl == 2) {
				if (A[i] == A[j]) {
					dp[i][j] = true;
					DP[i][j] = 1;
					++result[0];
					if (A.substr(i, cl/2) == A.substr(i + (cl + 1) / 2, cl/2)) {
						if (DP[i][i + cl/2 - 1] == DP[i + (cl+1)/2][j]) {
							DP[i][j] += DP[i + (cl + 1) / 2][j];
							for(int k=2;k<=DP[i][j];++k)
							++result[k-1];
						}
					}
				}
			}
			else {
				dp[i][j] = (A[i] == A[j]) && (dp[i + 1][j - 1]);
				if (dp[i][j] == true) {
					++result[0];
					DP[i][j] = 1;
					if (A.substr(i, cl / 2) == A.substr(i + (cl + 1) / 2, cl / 2)) {
						if (DP[i][i + cl / 2 - 1] == DP[i + (cl + 1) / 2][j]) {
							DP[i][j] += DP[i + (cl + 1) / 2][j];
							for (int k = 2; k <= DP[i][j]; ++k)
								++result[k-1];
							//++result[DP[i][j] - 1];
						}
					}
				}
			}
		}
	}
	return result;
}
