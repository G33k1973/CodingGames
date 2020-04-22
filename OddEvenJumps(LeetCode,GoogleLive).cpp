#define pb push_back
class Solution {
protected:
	map<int, vector<int>> bst;
	vector<vector<int>> dp;
	bool dfs(vector<int>& a, int n, int i, bool odd) {
		if (i == (n - 1))return 1;
		if (i >= n)return 0;
		if (dp[i][int(odd)] != -1)return dp[i][int(odd)];
		bool ans = false;
		if (odd) {
			auto ptr = bst.find(a[i]);
			while (ptr != bst.end()) {
				auto it = std::upper_bound(begin(ptr->second), end(ptr->second), i);
				if (it != end(ptr->second)) {
					ans = ans || dfs(a, n, *it, !odd);
					break;
				}
				++ptr;
			}
		}
		else {
			auto ptr = bst.find(a[i]);
			while (1) {
				auto it = std::upper_bound(begin(ptr->second), end(ptr->second), i);
				if (it != end(ptr->second)) {
					ans = ans || dfs(a, n, *it, !odd);
					break;
				}
				if (ptr == bst.begin())break;
				--ptr;
			}
		}
		return dp[i][int(odd)] = int(ans);
	}
public:
	int oddEvenJumps(vector<int>& A) {
		int n = int(A.size());
		if (n == 0)return 0;
		if (n == 1)return 1;
		for (int i = 0; i < n; ++i) {
			bst[A[i]].pb(i);
		}
		dp.assign(n, vector<int>(2, -1));
		int res = 0;
		for (int i = 0; i < n; ++i) {
			if (dfs(A, n, i, true))++res;
		}
		return res;
	}
};