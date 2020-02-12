#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		if (N == 0)return -1;
		unordered_map<int, unordered_map<int, int>> ev;
		unordered_map<int, vector<pair<int, int>>> graph;
		for (vector<int>& i : times) {
			int u = i.front();
			int v = i.at(1);
			int w = i.back();
			int oldweight = INT_MAX;
			auto it = ev.find(u);
			if (it != end(ev)) {
				auto it2 = it->second.find(v);
				if (it2 != end(it->second)) {
					oldweight = it2->second;
					if (oldweight <= w)continue;
					it2->second = w;
					auto it3 = graph.find(u);
					for (pair<int, int>& j : it3->second) {
						if (j.first == v) {
							j.second = w;
							break;
						}
					}
					continue;
				}
			}
			ev[u][v] = w;
			graph[u].push_back(make_pair(v, w));
		}
		vector<int> dist(N + 1, INF);
		std::set<pair<int, int>> bst;
		dist.at(K) = 0;
		bst.insert(mp(0, K));
		while (!bst.empty()) {
			pair<int, int> current = *bst.begin();
			bst.erase(bst.begin());
			int node = current.second;
			int weight = current.first;
			for (auto& x : graph[node]) {
				int v = x.first;
				int w = x.second;
				if (dist[v] > dist[node] + w) {
					if (dist[v] != INF) {
						bst.erase(bst.find(make_pair(dist[v], v)));
					}
					dist[v] = dist[node] + w;
					bst.insert(mp(dist[v], v));
				}
			}
		}
		int res = INT_MIN;
		int j = 0;
		for (auto& i : dist) {
			if (j == 0) {
				++j;
				continue;
			}
			if (i == INF)return -1;
			res = max(res, i);
		}
		return res;
	}
};