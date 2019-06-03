#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
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
	void DFSutil(vector<bool>& vis, int s, int& cnt, int black) {
		vis[s] = true;
		for (auto& x : this->adj[s]) {
			if ((black == -1 || x != black) && !vis[x]) {
				DFSutil(vis, x, cnt, black);
			}
		}
		++cnt;
		return;
	}
	bool DFS() {
		for (int i = -1; i < this->V; ++i) {
			vector<bool> vis(this->V, false);
			int s = (i == -1) ? (0) : ((i == (V - 1)) ? (i - 1) : (i + 1));
			int tot = 0;
			this->DFSutil(vis, s, tot, i);
			//cout<<tot<<endl;
			if (i == -1 && tot != this->V)return 0;
			if (i > -1 && tot != (this->V - 1))return 0;
		}
		return 1;
	}
};
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int N, E;
		sc = scanf("%d %d", &N, &E);
		Graph G(N);
		for (int i = 0; i < E; ++i) {
			int u, v;
			sc = scanf("%d %d", &u, &v);
			G.ae(u, v);
		}
		cout << G.DFS() << endl;
	}
	return 0;
}