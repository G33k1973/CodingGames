#define pb push_back
class Solution {
protected:
	vector<int> r;
public:
	vector<int> findAnagrams(string s, string p) {
		int n = int(s.length());
		int m = int(p.length());
		if (m > n)return r;
		if (m == 0)return r;
		int i = 0, start = 0, c = 0;
		constexpr int CH = 26;
		vector<int> h(CH, 0);
		for (const char& x : p) {
			int y = x - 'a';
			++h[y];
		}
		vector<int> h2(CH, 0);
		while (i < n) {
			int y = s[i] - 'a';
			++h2[y];
			if (h2[y] <= h[y])++c;
			while (h2[y] > h[y]) {
				int z = s[start] - 'a';
				--h2[z];
				if (h2[z] < h[z])--c;
				++start;
			}
			if (c == m && (i - start + 1) == m) {
				r.pb(start);
				int z = s[start] - 'a';
				--h2[z];
				--c;
				++start;
			}
			++i;
		}
		return r;
	}
};