#define pb push_back
class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		int n = int(nums.size());
		if (n == 0)return vector<int>{};
		if (n == 1)return nums;
		sort(begin(nums), end(nums));
		vector<vector<int>> dp(n, vector<int>());
		for (int i = 0; i < n; ++i)dp[i].pb(nums[i]);
		int i, j;
		std::tuple<int, int> ans = make_tuple(0, -1);
		for (i = 1; i < n; ++i) {
			for (j = 0; j < i; ++j) {
				if (((nums[i] % nums[j]) == 0) && dp[i].size() < 1 + dp[j].size())
					dp[i].pb(nums[j]);
			}
			if (dp[i].size() > std::get<0>(ans)) {
				std::get<0>(ans) = dp[i].size();
				std::get<1>(ans) = i;
			}
		}
		vector<int> r = dp[std::get<1>(ans)];
		unordered_map<int, int> h;
		for (auto& x : r)++h[x];
		r = vector<int>{};
		for (int i = 0; i < n; ++i) {
			if (h.count(nums[i])) {
				r.pb(nums[i]);
				--h[nums[i]];
				if (h[nums[i]] == 0)h.erase(nums[i]);
			}
		}
		return r;
	}
};