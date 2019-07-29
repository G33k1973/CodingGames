class Solution {
private:
	void dfs(const vector<string>& words, int n, int l, int i, const string& target, string& build, vector<string>& res, bool& suc) {
		if (i == (int)target.size()) {
			res.push_back(target);
			suc = 1;
			return;
		}
		if (suc)return;
		for (int j = l; j < n; ++j) {
			string temp = words.at(j);
			auto pos = target.find(temp, i);
			if (pos == i) {
				build += temp;
				dfs(words, n, l, i + (int)temp.size(), target, build, res, suc);
				if (suc)return;
				build.erase(i + 1, (int)temp.size());
			}
			if (suc)return;
		}
		return;
	}
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		int n = (int)words.size();
		sort(begin(words), end(words), [](const string& a, const string&b) {return a.size() > b.size(); });
		int i = 0;
		vector<string> res;
		while (i < n - 1) {
			int j = i + 1;
			string build("");
			bool suc = false;
			dfs(words, n, j, 0, words[i], build, res, suc);
			++i;
		}
		return res;
	}
};