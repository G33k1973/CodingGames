#define pb push_back
class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		int n = int(arr1.size());
		int m = int(arr2.size());
		if (n == 0)return vector<int>{};
		if (m == 0)return arr1;
		map<int, vector<int>, less<int>> dict;
		for (int i = 0; i < n; ++i) {
			dict[arr1[i]].push_back(i);
		}
		vector<int> res;
		for (const auto& x : arr2) {
			auto it = dict.find(x);
			assert(it != end(dict));
			for (auto& y : it->second) {
				res.pb(it->first);
			}
			it = dict.erase(it);
		}
		if (dict.size() > 0) {
			auto ptr = begin(dict);
			while (ptr != end(dict)) {
				for (auto& y : ptr->second) {
					res.pb(ptr->first);
				}
				++ptr;
			}
		}
		return res;
	}
};