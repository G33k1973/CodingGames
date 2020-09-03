class Solution {
protected:
	unordered_map<string, string> h;
	string find(string& x) {
		auto it = h.find(x);
		if (it->second == x)return x;
		return find(it->second);
	}
	void merge(string& a, string& b) {
		string pa = find(a);
		string pb = find(b);
		if (pa == pb)return;
		h[pb] = pa;
		return;
	}
public:
	bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
		const int n = int(words1.size());
		const int m = int(words2.size());
		if (n != m)return false;
		if (!n)return true;
		for (auto& x : pairs) {
			string a = x.front(), b = x.back();
			auto ita = h.find(a);
			auto itb = h.find(b);
			if (ita == end(h) && itb == end(h)) {
				h.emplace(a, a);
				h.emplace(b, a);
			}
			else if (ita == end(h)) {
				string parent = find(b);
				h.emplace(a, parent);
			}
			else if (itb == end(h)) {
				string parent = find(a);
				h.emplace(b, parent);
			}
			else {
				merge(a, b);
			}
		}
		for (int i = 0; i < n; ++i) {
			string a = words1[i], b = words2[i];
			auto ita = h.find(a);
			auto itb = h.find(b);
			if (ita == end(h) && itb == end(h)) {
				if (a != b)return false;
				continue;
			}
			if (ita == end(h) || itb == end(h))return false;
			string pa = find(a), pb = find(b);
			if (pa != pb)return false;
		}
		return true;
	}
};