#define CHARS 255
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int l = static_cast<int>(s.length());
		if (l < 2)return l;
		int h[CHARS] = { 0 };
		int res = 1;
		int i = 0, j = 0;
		while (i < l) {
			char x = s.at(i);
			if (h[x] == 0) {
				++h[x];
			}
			else {
				res = max(res, i - j);
				while (h[x] == 1) {
					char y = s.at(j);
					++j;
					--h[y];
				}
				++h[x];
			}
			++i;
		}
		res = max(res, i - j);
		return res;
	}
};