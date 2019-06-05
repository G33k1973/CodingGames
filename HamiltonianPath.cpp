#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define pb push_back

class Graph {
private:
	int V;
	std::list<int> * adj;
public:
	Graph() {
		this->V = 0;
		this->adj = NULL;
	}
	Graph(int V) {
		this->V = V;
		this->adj = new list<int>[this->V]();
	}
	void ae(int u, int v) {
		this->adj[u].pb(v);
		this->adj[v].pb(u);
	}
	bool dfsUtil(int src, vector<bool>& visited, int cum) {
		if (cum == this->V)return true;
		visited.at(src) = 1;
		bool ans = false;
		for (std::list<int>::iterator ptr = this->adj[src].begin(); ptr != this->adj[src].end(); ++ptr) {
			if (!visited.at(*ptr)) {
				ans = ans || dfsUtil(*ptr, visited, cum + 1);
			}
		}
		visited.at(src) = 0;
		return ans;
	}
	bool solve() {
		for (int i = 0; i < this->V; ++i) {
			int tot = 0;
			vector<bool> visited(this->V, false);
			bool possible = dfsUtil(i, visited, 1);
			if (possible)return true;
		}
		return false;
	}
};

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n, m;
		cin >> n >> m;
		Graph G(n);
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			G.ae(--u, --v);
		}
		cout << G.solve() << endl;
	}
}