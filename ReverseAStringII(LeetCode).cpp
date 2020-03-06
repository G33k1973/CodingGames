class Solution {
public:
	string reverseStr(string s, int k) {
		int l = int(s.size());
		int i = 0;
		string result = "";
		while (i < l) {
			int left = l - i;
			if (left >= 2 * k) {
				int j = i + k - 1;
				while (j >= i) {
					result.push_back(s[j]);
					--j;
				}
				j = i + k;
				while (j < i + 2 * k) {
					result.push_back(s[j]);
					++j;
				}
				i = j;
			}
			else if (left < 2 * k) {
				int frev = i + k - 1;
				int j = min(l - 1, frev);
				while (j >= i) {
					result.push_back(s[j]);
					--j;
				}
				j = i + k;
				while (j < l) {
					result.push_back(s[j]);
					++j;
				}
				break;
			}
		}
		return result;
	}
};