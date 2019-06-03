#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define pb push_back
#define mp make_pair
class Graph {
private:
	int V;
	std::list<int> * adj;
public:
	Graph(int V) {
		this->V = V;
		this->adj = new list<int>[V]();
	}
	void ae(int u, int v) {
		this->adj[u].pb(v);
		this->adj[v].pb(u);
	}
	void DFSutil(int src, std::vector<bool>& vis, int l, int& res, int bestsofar, bool& out) {
		if (l > bestsofar) {
			out = true;
			return;
		}
		vis.operator[](src) = true;
		std::list<int>::const_iterator ptr;
		for (ptr = begin(adj[src]); ptr != end(adj[src]); ++ptr) {
			if (!vis[*ptr]) {
				DFSutil(*ptr, vis, l + 1, res, bestsofar, out);
				if (out)return;
			}
		}
		res = max(res, l);
	}
	int DFS() {
		std::pair<int, int> res{ INT_MAX,-1 };
		for (int i = 0; i < this->V; ++i) {
			vector<bool> visited(this->V, false);
			int maxlen = INT_MIN;
			bool out = false;
			this->DFSutil(i, visited, 0, maxlen, res.first, out);
			if (maxlen < res.first)res = mp(maxlen, i);
		}
		return res.first;
	}
};

int main(int argc, char ** argv) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		Graph G(n);
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v;
			--u, --v;
			G.ae(u, v);
		}
		int res = G.DFS();
		cout << res << "\n";
	}
}