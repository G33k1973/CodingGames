// A : given string
// return the required string
bool isPal(const std::string& s, int i, int j) {
	while (i < j) {
		if (s[i++] != s[j--])return false;
	}
	return true;
}
string longestPalindrome(string A) {
	// code here
	string& s = A;
	int l = int(A.length());
	if (l < 2)return A;
	{
		int i, j, cl;
		for (cl = l; cl >= 1; --cl) {
			for (i = 0; i <= (l - cl); ++i) {
				if (isPal(A, i, i + cl - 1))return A.substr(i, cl);
			}
		}
		return "";
	}
	std::pair<int, int> ans(0, -1);//first->length,second->starting index
	vector<vector<bool>> dp(l, vector<bool>(l, false));
	int i, j, cl;
	for (cl = 1; cl <= l; ++cl) {
		for (i = 0; i <= (l - cl); ++i) {
			j = i + cl - 1;
			if (cl == 1) {
				dp[i][j] = true;
				if (cl > ans.first)ans.first = cl, ans.second = i;
			}
			else if (cl == 2) {
				dp[i][j] = (s[i] == s[j]);
				if (dp[i][j] && cl > ans.first) {
					ans.first = cl, ans.second = i;
				}
			}
			else {
				dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1]);
				if (dp[i][j] && cl > ans.first) {
					ans.first = cl, ans.second = i;
				}
			}
		}
	}
	return s.substr(ans.second, ans.first);
}