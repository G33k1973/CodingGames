#define pb push_back
class Solution {
protected:
	struct Videos {
		string s;
		int freq;
		Videos() {}
		Videos(int a, string& b) :freq(a), s(b) {}
		bool operator<(const struct Videos& ob)const {
			if (freq == ob.freq)return this->s < ob.s;
			return this->freq < ob.freq;
		}
	};
	static bool comp(const struct Videos& a, const struct Videos& b) {
		return a.operator<(b);
	}
	std::unordered_map<string, int> h;
	vector<string> res;
	unordered_set<int> visited;
	unordered_map<int, unordered_set<int>> graph;
	int n;
public:
	vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
		(*this).n = static_cast<int>(watchedVideos.size());
		if (n == 0)return res;
		int i = 0;
		for (auto& x : friends) {
			for (auto& y : x) {
				graph[i].insert(y);
			}
			++i;
		}
		int lev = 0;
		std::queue<int> pile;
		pile.push(id);
		visited.insert(id);
		while (!pile.empty()) {
			++lev;
			int sz = static_cast<int>(pile.size());
			i = 0;
			while (i < sz) {
				int src = pile.front();
				pile.pop();
				for (auto& x : graph[src]) {
					if (visited.count(x) == 0) {
						pile.push(x);
						visited.insert(x);
						if (lev == level) {
							for (auto& y : watchedVideos[x])++h[y];
						}
					}
				}
				++i;
			}
			if (lev == level)break;
		}
		vector<struct Videos> arr;
		for (auto& x : h) {
			string s = x.first;
			int freq = x.second;
			struct Videos current(freq, s);
			arr.pb(current);
		}
		sort(begin(arr), end(arr), Solution::comp);
		for (auto& x : arr)res.pb(x.s);
		return res;
	}
};