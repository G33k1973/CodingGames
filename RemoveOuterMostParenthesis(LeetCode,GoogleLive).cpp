class Solution {
public:
	string removeOuterParentheses(string S) {
		int sum = 0, tail = 0;
		string str;
		for (int i = 0; i < S.size(); i++) {
			S[i] == '(' ? sum++ : sum--;
			if (sum == 0) {
				str.append(S, tail + 1, i - tail - 1);
				tail = i + 1;
				sum = 0;
			}
		}
		return str;
	}
};