int Solution::longestValidParentheses(string A) {
	int l = int(A.length());
	if (l < 2)return 0;
	{
		string s(A);
		stack<int> st;
		st.push(-1);
		int res = 0;
		for (int i = 0; i < l; ++i) {
			if (s[i] == '(') st.push(i);
			else {
				st.pop();
				if (!st.empty())
					res = max(res, i - st.top());
				else
					st.push(i);
			}
		}
		return res;
	}
	int i = 0;
	int res = 0;
	while (i < l) {
		int maxvalid = l - i;
		if (maxvalid <= res)break;
		if (A[i] == '(') {
			int no = 1;
			int j = i + 1;
			while (j < l) {
				if (A[j] == '(')++no;
				else if (A[j] == ')') {
					if (no > 0) {
						--no;
						if (no == 0)res = max(res, j - i + 1);
					}
					else break;
				}
				++j;
			}
		}
		++i;
	}
	return res;
}
