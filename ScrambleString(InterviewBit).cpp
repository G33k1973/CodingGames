bool f(const string& s1, const string& s2, int b1, int b2, int l, vector<vector<vector<short > > >& dp);
int Solution::isScramble(const string s1, const string s2) {
	if (s1.size() == 0)
		return false;
	int n = s1.size();
	vector<short> v(n + 1, -1);
	vector<vector<short> > vv(n, v);
	vector<vector<vector<short> > > dp(n, vv);
	// dp is the memory notebook of the recursive function
	bool ret = f(s1, s2, 0, 0, n, dp);
	return ret;
}
bool f(const string& s1, const string& s2, int b1, int b2, int l, vector<vector<vector<short > > >& dp) {
	// function to handle the two sub_strings of s1 and s2, starting from b1 and b2 respectively, with a length of l
	// s1 & s2 are original strings
	if (dp[b1][b2][l] != -1) // got the result before
		return dp[b1][b2][l];
	if (l == 1)
		return s1[b1] == s2[b2];
	for (int i = 1; i < l; i++) {
		if (f(s1, s2, b1, b2 + l - i, i, dp) && f(s1, s2, b1 + i, b2, l - i, dp)) {
			dp[b1][b2][l] = true;
			return true;
		}
		if (f(s1, s2, b1, b2, i, dp) && f(s1, s2, b1 + i, b2 + i, l - i, dp)) {
			dp[b1][b2][l] = true;
			return true;
		}
	}
	dp[b1][b2][l] = false;
	return false;
}