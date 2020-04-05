#define INF 0x3f3f3f3f
class Solution {
private:
	int sum = 0;
	vector<int> dp;
	int dfs(vector<int>& a, int n, int i) {
		if (i == n)return 0;
		if (dp[i] != -INF)return dp[i];
		int ans = INT_MIN, sub = 0;
		for (int j = i; j <= min(n - 1, i + 2); ++j) {
			sub += a[j];
			ans = max(ans, sub - dfs(a, n, j + 1));
		}
		return dp[i] = ans;
	}
public:
	string stoneGameIII(vector<int>& stoneValue) {
		int n = int(stoneValue.size());
		if (n == 0)return "Tie";
		sum = accumulate(begin(stoneValue), end(stoneValue), 0);
		dp = vector<int>(n, -INF);
		int res = dfs(stoneValue, n, 0);
		if (res > 0)return "Alice";
		if (res < 0)return "Bob";
		return "Tie";
	}
};