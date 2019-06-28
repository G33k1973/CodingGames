#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define pb push_back
#define mp make_pair
typedef std::pair<int, int> ip;
class Graph {
private:
	int V;
	std::list<ip> * adj;
	bool dfs(bool visited[], int src, int k) {
		visited[src] = 1;
		if (k <= 0)return true;
		bool ans = false;
		std::list<ip>::iterator ptr;
		for (ptr = this->adj[src].begin(); ptr != this->adj[src].end(); ++ptr) {
			int u = (*ptr).first;
			int w = (*ptr).second;
			if (!visited[u]) {
				ans = ans || dfs(visited, u, k - w);
			}
		}
		visited[src] = false;
		return ans;
	}
public:
	Graph() {
		this->V = -1;
		this->adj = nullptr;
	}
	Graph(int V) {
		(*this).V = V;
		this->adj = new list<ip>[this->V]();
	}
	void ae(int u, int v, int w) {
		this->adj[u].pb(mp(v, w));
		this->adj[v].pb(mp(u, w));
	}
	bool solve(int k) {
		bool visited[this->V];
		memset(&visited[0], false, sizeof(visited));
		return dfs(visited, 0, k);
	}
};

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int V, E, K;
		cin >> V >> E >> K;
		Graph G(V);
		for (int i = 0; i < E; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			G.ae(u, v, w);
		}
		cout << G.solve(K) << "\n";
	}
}