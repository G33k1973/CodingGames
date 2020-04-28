class Solution {
public:
	int longestValidParentheses(string s) {
		int l = int(s.size());
		if (l < 2)return 0;
		int i = 0, j, res = 0;
		while (i < l - 1) {
			if (s[i] == ')') {
				++i;
				continue;
			}
			int j = i;
			int no = 0, nc = 0;
			while (j < l) {
				if (s[j] == '(')++no;
				else {
					++nc;
					if (no == 0)break;
					--no;
					--nc;
					if (no == 0 && nc == 0)res = max(res, j - i + 1);
				}
				++j;
			}
			++i;
		}
		return res;
	}
};