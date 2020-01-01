#define pb push_back
vector<vector<string>> res;
void dfs(const std::string& s, int l, int i, vector<string>& temp, vector<vector<bool>>& dp) {
	if (i == l) {
		res.pb(temp);
		return;
	}
	int j;
	for (j = i; j < l; ++j) {
		if (dp[i][j]) {
			string a = s.substr(i, j - i + 1);
			temp.pb(a);
			dfs(s, l, j + 1, temp, dp);
			temp.pop_back();
		}
	}
	return;
}
bool comp(const vector<string>& a, const vector<string>& b) {
	int n = int(a.size());
	int m = int(b.size());
	int i = 0, j = 0;
	bool outcome = false;
	while (i < n&&j < m) {
		if (a[i].size() < b[j].size()) {
			outcome = true;
			break;
		}
		if (a[i].size() > b[j].size()) {
			outcome = false;
			break;
		}
		++i, ++j;
	}
	return outcome;
}
vector<vector<string> > Solution::partition(string A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int l = static_cast<int>(A.size());
	if (res.size() != 0)res.clear();
	if (l == 0)return res;
	if (l == 1) {
		return vector<vector<string>>{ {A}};
	}
	vector<vector<bool>> dp(l, vector<bool>(l, false));
	int i, j, cl;
	string& s = A;
	for (cl = 1; cl <= l; ++cl) {
		for (i = 0; i <= (l - cl); ++i) {
			j = i + cl - 1;
			if (cl == 1)dp[i][j] = true;
			else if (cl == 2) {
				dp[i][j] = (s[i] == s[j]);
			}
			else {
				dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
			}
		}
	}
	vector<string> temp;
	dfs(A, l, 0, temp, dp);
	std::sort(begin(res), end(res), comp);
	return res;
}
