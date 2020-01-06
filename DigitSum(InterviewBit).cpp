#define pb push_back
#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
std::unordered_map<int, unordered_map<int, int>> dp;
int dfs(int ndigits, int curdigit, int cursum, int B) {
	if (curdigit == ndigits) {
		if (cursum == B)return 1;
		return 0;
	}
	if (cursum > B)return 0;
	auto it = dp.find(curdigit);
	if (it != end(dp)) {
		auto it2 = it->second.find(cursum);
		if (it2 != end(it->second))return it2->second;
	}
	int ans = 0;
	for (int i = 0; i <= 9; ++i) {
		ans = ms(ans, dfs(ndigits, curdigit + 1, cursum + i, B));
	}
	return dp[curdigit][cursum] = ans;
}
int Solution::solve(int A, int B) {
	if (B == 0) {
		if (A > 1)return 0;
		if (A == 1)return 1;
	}
	if (dp.size() > 0)dp.clear();
	int ans = 0;
	for (int i = 1; i <= 9; ++i) {
		int sum(i);
		if (sum > B)break;
		ans = ms(ans, dfs(A, 1, i, B));
	}
	return ans;
}