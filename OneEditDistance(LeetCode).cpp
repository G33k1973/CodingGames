class Solution {
public:
	bool isOneEditDistance(string s, string t) {
		int l = int(s.size()), n = int(t.size());
		if (abs(n - l) > 1)return false;
		int c = 0;
		int i = 0, j = 0;
		while (i < l&&j < n) {
			if (s[i] == t[j]) {
				++i, ++j;
				continue;
			}
			if (c == 1)return false;
			//remove s[i]
			if (i < l - 1 && s[i + 1] == t[j]) {
				++i;
				++c;
				continue;
			}
			//insert s[i]
			if (j < n - 1 && s[i] == t[j + 1]) {
				++j;
				++c;
				continue;
			}
			//replace
			if (j < n - 1 && i < l - 1 && s[i + 1] == t[j + 1]) {
				++i, ++j;
				++c;
				continue;
			}
			break;
		}
		cout << i << " " << j << " " << c << endl;
		return (i == l && j == n && c == 1) || (l > n&&i == l - 1 && j == n && c == 0) || (n > l&&i == l && j == n - 1 && c == 0) ||
			(n == l && i == l - 1 && j == n - 1 && c == 0);
	}
};