class Solution {
public:
	int maxA(int N) {
		if (N <= 6)return N;
		int dp[N] = { 0 };
		for (int i = 1; i <= 6; ++i)dp[i - 1] = i;
		for (int i = 7; i <= N; ++i) {
			dp[i - 1] = 0;
			for (int j = i - 3; j >= 1; --j) {
				int curr = (i - j - 1)*dp[j - 1];
				if (curr > dp[i - 1])dp[i - 1] = curr;
			}
		}
		return dp[N - 1];
	}
};