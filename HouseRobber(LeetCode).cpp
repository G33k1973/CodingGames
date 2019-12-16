class Solution {
protected:
	vector<int> sol;
public:
	int rob(vector<int>& nums) {
		int n = static_cast<int>(nums.size());
		if (n == 0)return 0;
		if (n == 1)return nums.front();
		if (n == 2)return max(nums[0], nums[1]);
		int dp[n + 1] = { 0 };
		dp[0] = nums.front();
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < n; ++i) {
			dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
		}
		return dp[n - 1];
	}
};