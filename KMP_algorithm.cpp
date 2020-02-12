class Solution {
private:
	void precompute(vector<int>& lps, string& s, int l) {
		int len = 0;
		int i = 1;
		while (i < l) {
			if (s[i] == s[len]) {
				++len;
				lps[i] = len;
				++i;
			}
			else {
				if (len != 0)len = lps[len - 1];
				else {
					++i;
				}
			}
		}
		return;
	}
	int KMP(string& text, string& pattern, vector<int>& lps, int n, int m) {
		int i = 0, j = 0;
		while (i < n) {
			if (text[i] == pattern[j]) {
				++i, ++j;
			}
			if (j == m) {
				return (i - m);
			}
			else if (text[i] != pattern[j]) {
				if (j != 0) {
					j = lps[j - 1];
				}
				else ++i;
			}
		}
		return -1;
	}
public:
	int strStr(string haystack, string needle) {
		int n = int(haystack.size());
		int m = int(needle.length());
		if (m > n)return -1;
		if (m == n) {
			return (haystack.compare(needle) == 0) ? (0) : (-1);
		}
		vector<int> lps(m, 0);
		precompute(lps, needle, m);
		return KMP(haystack, needle, lps, n, m);
	}
};