int Solution::solve(vector<vector<int> > &A) {
	int n = int(A.size());
	if (n == 0)return 0;
	int m = int(A.front().size());
	if (m == 0)return 0;
	// vector<int> sum(n,0);
	 //vector<vector<int>> px(n,vector<int>(m,0));
	 //vector<vector<int>> sx(n,vector<int>(m,0));
	int i, j;
	/*
	for(i=0;i<n;++i){
		sum[i]=0;
		for(j=0;j<m;++j){
			px[i][j]=sum[i];
			sum[i]+=A[i][j];
		}
		for(j=m-2;j>=0;--j){
			sx[i][j]=sx[i][j+1]+A[i][j+1];
		}
	}
	*/
	int res = 0;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			int u, v;
			int left = n - i;
			vector<int> dp(left, 0);
			int sub = 0;
			for (v = j; v < m; ++v) {
				sub = 0;
				for (u = i; u < n; ++u) {
					dp[u - i] += A[u][v];
					sub += dp[u - i];
					res += sub;
				}
			}
		}
	}
	return res;
}
