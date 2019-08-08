class Solution {
protected:
	vector<int> ext(const std::string& s) {
		vector<int> h(26, 0);
		for (auto& x : s) {
			++h[x - 'a'];
		}
		return std::move(h);
	}
	bool inter(const std::vector<int>& a, const std::vector<int>& b) {
		for (int i = 0; i < 26; ++i) {
			if (a[i] == 0 || b[i] == 0)continue;
			return 0;
		}
		return 1;
	}
public:
	int maxProduct(vector<string>& words) {
		int l = (int)words.size();
		if (l < 2)return 0;
		std::sort(begin(words), end(words), [](const string& a, const string& b) {return a.size() > b.size(); });
		vector<vector<int>> hs(l, vector<int>(26, 0));
		for (int i = 0; i < l; ++i) {
			hs[i] = ext(words[i]);
		}
		int i, j;
		int res = 0;
		for (i = 0; i < l - 1; ++i) {
			int li = (int)words[i].length();
			if (li*li <= res)break;
			for (j = i + 1; j < l; ++j) {
				int lj = (int)words[j].size();
				int sub = li * lj;
				if (sub <= res)break;
				if (inter(hs[i], hs[j]))res = max(res, sub);
			}
		}
		return res;
	}
};