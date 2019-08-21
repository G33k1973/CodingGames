class Solution {
protected:
	string find(std::unordered_map<string, string>& h, string s) {
		if (h[s] == s)return s;
		return find(h, h[s]);
	}
public:
	bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
		std::unordered_map<string, string> h;
		for (auto& x : pairs) {
			h[x[0]] = x[0];
			h[x[1]] = x[1];
		}
		for (int i = 0; i < (int)pairs.size(); ++i) {
			string a = pairs[i][0];
			string b = pairs[i][1];
			string pa = find(h, a);
			string pb = find(h, b);
			if (pa != pb) {
				h[pa] = pb;
			}
		}
		int n = (int)words1.size();
		int m = (int)words2.size();
		if (n != m)return false;
		for (int i = 0; i < n; ++i) {
			if (words1[i] == words2[i])continue;
			string p1 = find(h, words1[i]);
			string p2 = find(h, words2[i]);
			if (p1 != p2)return false;
		}
		return true;
	}
};