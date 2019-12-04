#define pb push_back
#define mp make_pair
class Solution {
protected:
	vector<string> res;
	std::map<int, multiset<string>, greater<int>> mymap;
	std::unordered_map<std::string, int> dict;
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		int n = static_cast<int>(words.size());
		assert(k <= n);
		if (n == 0)return res;
		if (n == 1)return words;
		if (res.size() > 0)res.clear();
		for (auto& x : words) {
			if (dict.count(x) == 0) {
				++dict[x];
				auto it = mymap.find(1);
				if (it == end(mymap))
					mymap.insert(mp(1, std::multiset<string>{x}));
				else
					it->second.insert(x);
			}
			else {
				int oldfreq = dict.find(x)->second;
				auto it = mymap.find(oldfreq);
				auto it2 = it->second.erase(it->second.find(x));
				if (it->second.empty())mymap.erase(it);
				++dict[x];
				mymap[++oldfreq].insert(x);
			}
		}
		std::map<int, multiset<string>, greater<int>>::const_iterator ptr = begin(mymap);
		while (k > 0) {
			int sz = int(ptr->second.size());
			if (sz <= k) {
				res.insert(res.end(), ptr->second.begin(), ptr->second.end());
				k -= sz;
			}
			else {
				res.insert(res.end(), ptr->second.begin(), std::next(ptr->second.begin(), k));
				break;
			}
			++ptr;
		}
		return res;
	}
};