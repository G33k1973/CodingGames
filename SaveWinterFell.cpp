#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef std::pair<int, int> ip;
#define pb push_back
#define mp make_pair
class graph {
private:
	int V;
	list<ip> * adj;
public:
	graph() {
		this->V = 0;
		this->adj = NULL;
	}
	graph(int V) {
		(*this).V = V;
		this->adj = new list<ip>[this->V];
	}
	void ae(int u, int v, int w) {
		this->adj[u - 1].pb(mp(v - 1, w));
		this->adj[v - 1].pb(mp(u - 1, w));
	}
	void dfs(vector<bool>& vis, int src, int tot, int& ans) {
		vis[src] = true;
		for (const auto& x : adj[src]) {
			int u = x.first;
			int w = x.second;
			if (!vis[u]) {
				dfs(vis, u, tot + w, ans);
			}
		}
		ans = std::max(ans, tot);
		vis[src] = false;
		return;
	}
	int solve() {
		int res = 0;
		for (int i = 0; i < this->V; ++i) {
			vector<bool> vis(this->V, false);
			dfs(vis, i, 0, res);
		}
		return res;
	}
};
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n;
		sc = scanf("%d", &n);
		graph G(n);
		for (int i = 0; i < n; ++i) {
			int u, v, w;
			sc = scanf("%d %d %d", &u, &v, &w);
			G.ae(u, v, w);
		}
		int res = G.solve();
		printf("%d\n", res);
	}
	return 0;
}