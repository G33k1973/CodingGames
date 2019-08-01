class Solution {
private:
	bool isGood(string& sub) {
		int l = (int)sub.size();
		int co = 0;
		int i = 0;
		for (; i < l; ++i) {
			char x = sub.at(i);
			if (x == '(')++co;
			else if (x == ')') {
				if (co == 0)return 0;
				--co;
			}
		}
		return co == 0;
	}
public:
	int longestValidParentheses(string s) {
		int l = static_cast<int>(s.length());
		if (l == 0)return 0;
		int i, j, cl;
		vector<vector<bool>> dp(l, vector<bool>(l, false));
		int res = 0;
		for (cl = 1; cl <= l; ++cl) {
			for (i = 0; i <= (l - cl); ++i) {
				j = i + cl - 1;
				if (cl == 1)dp[i][j] = 0;
				else if (cl == 2) {
					if (s[i] == '('&&s[j] == ')') {
						dp[i][j] = 1;
						res = std::max(res, cl);
					}
					else dp[i][j] = 0;
				}
				else if (cl & 1) {
					dp[i][j] = 0;
				}
				else if (!(cl & 1)) {
					if (s[i] == '('&&s[j] == ')') {
						if (dp[i + 1][j - 1]) {
							dp[i][j] = true;
							res = max(res, cl);
						}
						else {
							string sub = s.substr(i, cl);
							if (this->isGood(sub)) {
								dp[i][j] = true;
								res = max(res, cl);
							}
						}
					}
					else {
						dp[i][j] = false;
					}
				}
			}
		}
		return res;
	}
};