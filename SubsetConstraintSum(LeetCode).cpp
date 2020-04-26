#define INF 0x3f3f3f3f
class Solution {
private:
	vector<int> dp;
	int dfs(vector<int>& a, int n, int i, int k) {
		if (i == n - 1) {
			return max(0, a.back());
		}
		if (i >= n)return 0;
		if (dp[i] != INT_MIN)return dp[i];
		int ans = -INF;
		for (int j = i + 1; j <= min(n - 1, i + k); ++j) {
			ans = max(ans, a[i] + dfs(a, n, j, k));
		}
		return dp[i] = ans;
	}
public:
	int constrainedSubsetSum(vector<int>& nums, int k) {
		int n = int(nums.size());
		if (n == 0)return 0;
		if (k == 1) {
			int res = 0;
			int mx = INT_MIN;
			for (int& x : nums) {
				if (x > mx)mx = x;
				if (x > 0)res += x;
			}
			if (res == 0)return mx;
			return res;
		}
		dp.assign(n, INT_MIN);
		int res = INT_MIN;
		for (int i = 0; i <= n - k; ++i) {
			res = max(res, dfs(nums, n, i, k));
		}
		return res;
	}
};