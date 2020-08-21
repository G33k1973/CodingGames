using ip = pair<int, int>;
using iip = pair<int, ip>;//for queue:{ring index,{key index,distance}}
#define mp make_pair
#define pb push_back
class Solution {
public:
	int findRotateSteps(string ring, string key) {
		//index at which we are on ring -> key
		//{char reachable, {index in ring,distance}}
		unordered_map<int, unordered_map<char, vector<pair<int, int>>>> h;
		const int n = int(ring.size());
		const int m = int(key.size());
		if (!m)return 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int distance = 0;
				if (j <= i)distance = min(i - j, n - i + j);
				else if (j > i)distance = min(j - i, n - j + i);
				h[i][ring[j]].pb(mp(j, distance));
			}
		}
		int start = 0;//start index
		//index of ring,index of key,travelled distance
		int res = INT_MAX;
		queue<iip> pile;
		pile.push(mp(start, mp(0, 0)));
		bool out(false);
		unordered_map<int, unordered_map<int, int>> seen;
		while (!pile.empty()) {
			int sz = int(pile.size());
			int u = 0;
			while (u < sz) {
				iip current = pile.front();
				pile.pop();
				int ringindex = current.first;
				int keyindex = current.second.first;
				int weight = current.second.second;
				if (keyindex == m) {
					res = min(res, weight);
					++u;
					continue;
				}
				char target = key[keyindex];
				auto it = h.find(ringindex);
				auto it2 = it->second.find(key[keyindex]);
				for (auto& y : it2->second) {
					//nu index is y.first
					//distance is y.second+1
					auto ptr = seen.find(y.first);
					if (ptr != end(seen)) {
						auto ptr2 = ptr->second.find(keyindex + 1);
						if (ptr2 != end(ptr->second)) {
							if (ptr2->second <= weight + y.second + 1)continue;
						}
					}
					pile.push(mp(y.first, mp(keyindex + 1, weight + y.second + 1)));
				}
				++u;
			}
		}
		return res;
	}
};