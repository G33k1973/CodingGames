class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		int n = int(s1.size());
		int m = int(s2.size());
		if (m == 0 && n > 0)return 0;
		if (n > m)return false;
		if (m == n) {
			sort(s1.begin(), s1.end());
			sort(s2.begin(), s2.end());
			return (s1.compare(s2) == 0);
		}
		int i = 0, start = 0, c = 0;
		constexpr int CHARS = 26;
		vector<int> h(CHARS, 0);
		for (const char& x : s1) {
			int y = x - 'a';
			++h[y];
		}
		vector<int> h2(CHARS, 0);
		while (i < m) {
			char x = s2[i];
			++h2[x - 'a'];
			if (h2[x - 'a'] <= h[x - 'a'])++c;
			while (h2[x - 'a'] > h[x - 'a']) {
				char y = s2[start];
				--h2[y - 'a'];
				if (h2[y - 'a'] < h[y - 'a'])--c;
				++start;
			}
			if (c == n && (i - start + 1) == n)return true;
			++i;
		}
		return false;
	}
};