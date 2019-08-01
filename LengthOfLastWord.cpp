class Solution {
public:
	int lengthOfLastWord(string s) {
		s.insert(0, 1, ' ');
		int l = static_cast<int>(s.size());
		if (l == 1)return 0;
		int res(0);
		int i = l - 1;
		bool st = static_cast<int>(0);
		while (i >= 0) {
			char x = s.at(i);
			if (isspace(x)) {
				if (st) {
					break;
				}
			}
			else {
				if (!st)st = 1;
				++res;
			}
			--i;
		}
		return res;
	}
};