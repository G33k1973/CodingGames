#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
class Solution {
private:
	std::list<pair<int, int>>* adj;
	int Djkastra(int K, int N) {
		vector<int> dist(N, INF);
		dist[K - 1] = 0;
		std::set<pair<int, int>> bst;
		bst.insert(mp(0, K - 1));
		while (!bst.empty()) {
			pair<int, int> temp = *bst.begin();
			bst.erase(bst.begin());
			int node = temp.second;
			int weight = temp.first;
			for (auto& x : adj[node]) {
				int dst = x.first, w = x.second;
				if (dist[node] + w < dist[dst]) {
					if (dist[dst] != INF) {
						bst.erase(bst.find(mp(dist[dst], dst)));
					}
					dist[dst] = dist[node] + w;
					bst.insert(mp(dist[dst], dst));
				}
			}
		}
		int sum = INT_MIN;
		for (int i = 0; i < N; ++i) {
			if (dist[i] == INF)return -1;
			sum = max(sum, dist[i]);
		}
		return sum;
	}
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		this->adj = new list<pair<int, int>>[N]();
		for (vector<int>& i : times) {
			int u = i[0] - 1;
			int v = i[1] - 1;
			int w = i.back();
			adj[u].pb(mp(v, w));
		}
		int res = this->Djkastra(K, N);
		delete[] this->adj;
		return res;
	}
};