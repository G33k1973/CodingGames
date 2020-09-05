using ip = pair<int, int>;
using pq = std::priority_queue<ip, vector<ip>, greater<ip>>;
#define mp make_pair
#define pb push_back
class Solution {
protected:
	std::list<ip>* adj;
	vector<int> parent;
public:
	int minimumCost(int N, vector<vector<int>>& connections) {
		if (N == 0)return -1;
		if (N == 1)return 0;
		parent.assign(N, -1);
		adj = new std::list<ip>[N]();
		for (auto& x : connections) {
			int u = x[0] - 1, v = x[1] - 1, w = x[2];
			adj[u].pb(mp(v, w));
			adj[v].pb(mp(u, w));
		}
		vector<bool> MST(N, false);
		pq pile;
		pile.push(mp(0, 0));
		int INF = 0x3f3f3f3f;
		vector<int> dist(N, INF);
		dist[0] = 0;
		while (!pile.empty()) {
			ip cur = pile.top();
			pile.pop();
			int node = cur.second;
			int cost = cur.first;
			MST[node] = true;
			auto it = adj[node].begin();
			while (it != adj[node].end()) {
				int v = (*it).first, w = (*it).second;
				if (!MST[v] && dist[v] > w) {
					dist[v] = w;
					parent[v] = node;
					pile.push(mp(dist[v], v));
				}
				++it;
			}
		}
		int res(0);
		for (int i = 1; i < N; ++i) {
			if (dist[i] == INF)return -1;
			res += dist[i];
		}
		return res;
	}
};