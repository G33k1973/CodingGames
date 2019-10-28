// you can use includes, for example:
#include <algorithm>
#include <climits>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector< vector<int> > &C) {
	// write your code in C++14 (g++ 6.2.0)
	int n = int(C.size());
	int m = int(C.front().size());
	vector<vector<int>> grid(C);
	for (int i = 0; i < n; ++i) {
		grid.push_back(grid[i]);
	}
	n <<= 1;
	for (int i = 0; i < n; ++i) {
		grid[i].insert(grid[i].end(), grid[i].begin(), grid[i].end());
	}
	m <<= 1;
	int ans = INT_MIN;
	int i, j;
	/*
	for(i=0;i<n;++i){
		for(j=0;j<m;++j){
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	n /= 2, m /= 2;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			int u, v;
			int row = n;
			int dp[row] = { 0 };
			for (v = j; v < j + m; ++v) {
				int sub = 0;
				for (u = i; u < i + n; ++u) {
					dp[u - i] += grid[u][v];
					sub += dp[u - i];
					//cout<<sub<<endl;
					ans = max(ans, sub);
				}
			}
		}
	}
	return ans;
	return ans;
}