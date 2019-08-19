class Solution {
protected:
	vector<int> extract(const std::string& s) {
		int l = static_cast<int>(s.size());
		int i = 0;
		std::unordered_map<char, int> h;
		int c = -1;
		vector<int> func;
		while (i < l) {
			char x = s.at(i++);
			auto it = h.find(x);
			if (it != end(h))func.push_back((*it).second);
			else {
				h[x] = ++c;
				func.push_back(c);
			}
		}
		return func;
	}
	vector<bool> visited;
	void dfs(string& s, int l, int i, char x, char y) {
		if (i == l)return;
		if (!visited[i] && s[i] == x) {
			visited[i] = true;
			s[i] = y;
		}
		dfs(s, l, i + 1, x, y);
		return;
	}
public:
	bool canConvert(string str1, string str2) {
		int n = static_cast<int>(str1.size());
		int m = static_cast<int>(str2.size());
		if (n != m)return false;
		bool ans(false);
		int i = 0;
		std::unordered_map<char, char> fun;
		while (i < n) {
			if (str1[i] == str2[i]) {
				++i;
				continue;
			}
			char y = str2[i];
			char x = str1[i];
			auto it = fun.find(x);
			if (it != end(fun) && it->second != y)return false;
			if (it == end(fun))fun[x] = y;
			++i;
		}
		visited.assign(n, false);
		for (auto& x : fun) {
			(*this).dfs(str1, n, 0, x.first, x.second);
		}
		return (str1.compare(str2) == 0);
	}
};