class Solution {
public:
	bool divisorGame(int N) {
		vector<int> dp(N + 1, 1);
		if (N == 1)return false;
		if (N == 2)return true;
		dp[0] = 0, dp[1] = 0, dp[2] = 1;
		for (int i = 3; i <= N; ++i) {
			int fails = 0, tot = 0;
			for (int j = 1; j*j <= i; ++j) {
				if (i%j == 0) {
					int d1 = j, d2 = i / j;
					if (d2 == i)d2 = 1;
					if (d1 == d2)++tot;
					else tot += 2;
					if (dp[i - d1]) {
						++fails;
					}
					if (d1 != d2 && dp[i - d2]) {
						++fails;
					}
				}
			}
			if (fails == tot)dp[i] = 0;
		}
		return dp[N];
	}
};