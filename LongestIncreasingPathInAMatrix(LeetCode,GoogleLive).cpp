class Solution {
private:
	int n, m;
	int X[4] = { +1,-1,0,0 };
	int Y[4] = { 0,0,-1,+1 };
	vector<vector<int>> dp;
	bool isvalid(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m);
	}
	int LongestPath(int i, int j, vector<vector<int>>& matrix) {
		if (dp[i][j] != -1)return dp[i][j];
		int res = 0;
		for (int k = 0; k < 4; ++k) {
			int ni = i + X[k], nj = j + Y[k];
			if (isvalid(ni, nj) && matrix[ni][nj] > matrix[i][j])
				res = max(res, 1 + LongestPath(ni, nj, matrix));
		}
		return dp[i][j] = res;
	}
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		n = int(matrix.size());
		if (n == 0)return 0;
		m = int(matrix.front().size());
		if (m == 0)return 0;
		int res = 0;
		dp.assign(n, vector<int>(m, -1));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				res = max(res, 1 + LongestPath(i, j, matrix));
			}
		}
		return res;
	}
};