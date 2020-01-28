class Solution {
public:
	string countAndSay(int n) {
		if (n == 1)return "1";
		string s = string(1, '1');
		for (int i = 2; i <= n; ++i) {
			int c(1);
			char x = s.front();
			string temp("");
			for (int j = 1; j < (int)s.size(); ++j) {
				if (s[j] == x)++c;
				else {
					temp += to_string(c);
					temp += string(1, x);
					c = 1, x = s[j];
				}
			}
			temp += to_string(c);
			temp += string(1, x);
			s = temp;
		}
		return s;
	}
};