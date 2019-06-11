#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ip;
#define pb push_back
#define mp make_pair
class Graph {
	int V;
	std::list<ip> * adj;
public:
	Graph() {
		this->V = 0;
		this->adj = 0;
	}
	Graph(int a) :V(a) {
		this->adj = new list<ip>[this->V]();
	}
	void ae(int u, int v, int w) {
		this->adj[u - 1].pb(mp(v - 1, w));
		this->adj[v - 1].pb(mp(u - 1, w));
	}
	int bfs(int src) {
		vector<bool> visited(this->V, false);
		visited.at(src) = true;
		std::queue<ip> pile;
		pile.push(mp(src, 0));
		int res = 0;
		while (!pile.empty()) {
			int n = (int)pile.size();
			for (int i = 0; i < n; ++i) {
				ip temp = pile.front();
				pile.pop();
				int u = temp.first;
				int cost = temp.second;
				res = std::max(res, cost);
				for (auto& x : this->adj[u]) {
					int nnode = x.first;
					int weight = x.second;
					if (!visited.at(nnode)) {
						pile.push(mp(nnode, cost + weight));
						visited.at(nnode) = true;
					}
				}
			}
		}
		return res;
	}
	int solve() {
		int res = 0;
		for (int i = 0; i < this->V; ++i) {
			if (this->adj[i].size() == 1) {
				res = std::max(res, bfs(i));
			}
		}
		return res;
	}
};
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		Graph G(n);
		for (int i = 0; i < n - 1; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			G.ae(u, v, w);
		}
		int res = G.solve();
		cout << res << endl;
	}
	return 0;
}