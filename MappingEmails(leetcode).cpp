#define pb push_back
class Solution {
protected:
	vector<vector<string>> res;

public:
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		int n = int(accounts.size());
		if (n == 0)return res;
		unordered_map<string, int> mapping;
		for (int i = 0; i < n; ++i) {
			int m = int(accounts[i].size());
			if (m == 1) {
				res.pb(vector<string>{accounts[i].front()});
			}
			else {
				bool found = false;
				unordered_set<int> seen;
				int index = INT_MAX;
				for (int j = 0; j < m - 1; ++j) {
					string email = accounts[i][j + 1];
					auto it = mapping.find(email);
					if (it == end(mapping) || it->second == i) {
						mapping[email] = i;
						if (seen.count(i) == 0)seen.insert(i);
					}
					else {
						if (found == false)found = true;
						if (seen.count(it->second) == 0)seen.insert(it->second);
						index = min(index, it->second);
						mapping[email] = index;
					}
				}
				//for(auto& z: seen)cout<<z<<" ";
				//cout<<endl;
				if (found == true) {
					//cout<<index<<endl;
					for (auto& x : mapping) {
						if (seen.count(x.second) > 0)mapping[x.first] = index;
					}
				}
			}
		}
		unordered_map<int, set<string>> lib;
		for (auto& x : mapping) {
			lib[x.second].insert(x.first);
		}
		for (auto& x : lib) {
			vector<string> temp{ accounts[x.first].front() };
			temp.insert(temp.end(), begin(x.second), end(x.second));
			res.pb(temp);
		}
		return res;
	}
};