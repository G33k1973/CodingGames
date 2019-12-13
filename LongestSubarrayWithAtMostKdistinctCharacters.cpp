#define pb push_back
#define CHARS 255
class Solution {
private:
	int res;
public:
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		(*this).res = 0;
		int l = int(s.length());
		if (l == 0)return 0;
		if (k == 0)return 0;
		int h[CHARS + 1] = { 0 };
		int start = 0, i = 0, c = 0;
		while (i < l) {
			char y = s.operator[](i);
			if (h[y] == 0) {
				++c;
				while (c > k) {
					char z = s[start];
					if (h[z] > 1) {
						--h[z];
						++start;
					}
					else {
						--h[z];
						--c;
						++start;
						break;
					}
				}
				res = max(res, i - start + 1);
			}
			else {
				res = max(res, i - start + 1);
			}
			++h[y];
			++i;
		}
		res = max(res, l - start);
		return res;
	}
};