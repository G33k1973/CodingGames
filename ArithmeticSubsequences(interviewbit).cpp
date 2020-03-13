int dfs(vector<int>& A, int n, int i, unordered_map<int, vector<int>>& h, int x, int delta,
	unordered_map<int, unordered_map<int, int>>& dp, int c) {
	if (i == n) {
		return 0;
	}
	int ans = (c < 3) ? (0) : (1);
	if (delta != INT_MAX) {
		/*
		auto it=dp.find(i);
		if(it!=end(dp)){
			auto it2=it->second.find(delta);
			if(it2!=end(it->second))return it2->second;
		}
		*/
		auto it3 = h.find(x + delta);
		if (it3 == end(h)) {
			return ans;
		}
		auto it4 = lower_bound(begin(it3->second), end(it3->second), i);
		if (it4 == end(it3->second)) {
			return ans;
		}
		while (it4 != end(it3->second)) {
			ans = ans + dfs(A, n, *it4, h, A[*it4], delta, dp, c + 1);
			++it4;
		}
	}
	else {
		ans = ans + dfs(A, n, i + 1, h, x, delta, dp, c);
		ans = ans + dfs(A, n, i + 1, h, A[i], A[i] - x, dp, c + 2);
	}
	return dp[i][delta] = ans;
}
int Solution::solve(vector<int> &A) {
	int n = int(A.size());
	if (n < 3)return 0;
	unordered_map<int, unordered_map<int, int>> dp;
	unordered_map<int, vector<int>> h;
	for (int i = 0; i < n; ++i) {
		h[A[i]].push_back(i);
	}
	int res = 0;
	for (int i = 0; i < n - 2; ++i) {
		res = res + dfs(A, n, i + 1, h, A[i], INT_MAX, dp, 0);
	}
	return res;
}
