#include<bits/stdc++.h>
using ip = pair<int, int>;
using iip = pair<int, ip>;
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
class Graph {
	struct Edge {
		int u, v, taxiride,notaxiride;
		Edge(int a, int b, int w,int w0) {
			u = a, v = b, taxiride = w, notaxiride = w0;
		}
		bool ismatch(int a, int b) {
			return ((u == a && v == b) || (u == b && v == a));
		}
	};
	vector<Edge> edg;
	int V;
	std::list<ip> * adj;
public:
	Graph() {
		V = INT_MIN;
		adj = 0;
	}
	Graph(int V) {
		this->V = V;
		this->adj = new list<ip>[this->V]();
	}
	void ae(int u, int v, int w1, int w2) {
		adj[u].pb(mp(v, w1));
		adj[v].pb(mp(u, w1));
		struct Edge temp(u, v, w2);
		edg.push_back(temp);
	}
	int Djakstra(int src, int dst) {
		int res(INF);
		for (struct Edge& i : edg) {
			vector<int> dist(V, INF);
			dist[src] = 0;
			std::set<ip> bst;
			bst.insert(mp(0, src));
			while (!bst.empty()) {
				ip current = *bst.begin();
				bst.erase(bst.begin());
				int node = current.second;
				int weight = current.first;
				std::list<ip>::const_iterator ptr = adj[node].begin();
				while (ptr != adj[node].end()) {
					int u = ptr->first;
					int w1 = ptr->second;
					if (dist[node] + w1 < dist[u]) {
						if (dist[u] != INF) {
							bst.erase(bst.find(mp(dist[u], u)));
						}
						dist[u] = dist[node] + w1;
						bst.insert(mp(dist[u], u));
					}
					if (i.ismatch(u, node)) {
						if (dist[node] + i.taxiride < dist[u]) {
							if (dist[u] != INF) {
								bst.erase(bst.find(mp(dist[u], u)));
							}
							dist[u] = dist[node] + i.taxiride;
							bst.insert(mp(dist[u], u));
						}
					}
					++ptr;
				}
			}
			if (dist[dst] != INF)res = min(dist[dst], res);
		}
		return (res==INF)?(-1):(res);
	}
};
int Solution::solve(int A, vector<vector<int> > &B, int C, int D) {
	Graph G(A);
	for (vector<int>& i : B) {
		int u = i[0] - 1, v = i[1] - 1, w1 = i[2], w2 = i[3];
		G.ae(u, v, w1, w2);
	}
	int res = G.Djakstra(C - 1, D - 1);
	return res;
}
