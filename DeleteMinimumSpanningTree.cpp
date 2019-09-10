#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int, int> ip;

class Graph {
private:
	int V;
	std::list<int> * adj;
	std::vector<pair<int, ip>> edges;
public:
	Graph(int V) {
		this->V = V;
		this->adj = new list<int>[this->V]();
	}
	void ae(int u, int v, int w) {
		adj[u].pb(v);
		adj[v].pb(u);
		edges.pb(mp(w, mp(u, v)));
		return;
	}
	void DFS(int src, bool visited[]) {
		visited[src] = 1;
		for (auto& x : adj[src]) {
			if (!visited[x])DFS(x, visited);
		}
		return;
	}
	bool isConnected() {
		bool visited[V];
		memset(&visited[0], false, sizeof(visited));
		DFS(0, visited);
		for (int i = 0; i < V; ++i) {
			if (!visited[i])return false;
		}
		return true;
	}
	int deleteMSP(void) {
		int res(0);
		std::sort(begin(edges), end(edges));
		for (int i = (int)edges.size() - 1; i >= 0; --i) {
			int u = edges[i].second.first;
			int v = edges[i].second.second;
			adj[u].remove(v);
			adj[v].remove(u);
			if (!isConnected()) {
				adj[u].pb(v);
				adj[v].pb(u);
				res += edges[i].first;
			}
		}
		return res;
	}
};

int main(int argc, char ** argv) {
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int V, E;
		sc = scanf("%d %d", &V, &E);
		Graph G(V);
		for (int i = 0; i < E; ++i) {
			int u, v, w;
			sc = scanf("%d %d %d", &u, &v, &w);
			G.ae(u, v, w);
		}
		int res = G.deleteMSP();
		printf("%d\n", res);
	}
	return 0;
}