class Solution {
public:
	bool isOneEditDistance(string s, string t) {
		int n = (int)s.size();
		int m = (int)t.size();
		if (n == 0 && m == 0)return false;
		if (abs(n - m) > 1)return false;
		if (m == 0 && n == 1)return true;
		if (n == 0 && m == 1)return true;
		int i = 0, j = 0, differences(0);
		while (i < n&&j < m) {
			char x = s.at(i);
			char y = t.at(j);
			if (x == y) {
				++i, ++j;
			}
			else if (n == m) {
				s[i] = y;
				++differences;
				break;
			}
			else if ((n - 1) == m) {
				s.erase(i, 1);
				++differences;
				break;
			}
			else if ((n + 1) == m) {
				s.insert(i, 1, y);
				++differences;
				break;
			}
		}
		if (differences == 0 && (n + 1) == m)return true;
		if (differences == 0 && (n - 1) == m)return true;
		return ((differences == 1) && (s == t));
	}
};