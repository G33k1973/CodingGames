class Solution {
protected:
	vector<int> dp;
	vector<int> a;
	int dfs(vector<int>& days, int n, int i) {
		if (i >= n)return 0;
		if (dp[i] != -1)return dp[i];
		int ans1 = a[0] + dfs(days, n, i + 1);
		auto it = upper_bound(begin(days) + i, end(days), days[i] + 6);
		int ans7 = a[1];
		ans7 += dfs(days, n, int(it - begin(days)));
		int ans30 = a[2];
		it = upper_bound(begin(days) + i, end(days), days[i] + 29);
		ans30 += dfs(days, n, int(it - begin(days)));
		return dp[i] = min(ans1, min(ans7, ans30));
	}
public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		const int n = int(days.size());
		if (!n)return 0;
		assert(costs.size() == static_cast<std::size_t>(3));
		if (n == 1)return min(costs[0], min(costs[1], costs[2]));
		dp.assign(n, -1);
		a = costs;
		return dfs(days, n, 0);
	}
};