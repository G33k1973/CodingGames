#include <bits/stdc++.h>

using namespace std;
#define INF 0x3f3f3f3f
using ll = long long int;
#define sc static_cast<ll>
using ip = pair<int, ll>;
#define pb push_back
#define mp make_pair
int main()
{
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q-- > 0) {
		int n, m;
		cin >> n >> m;
		std::list<ip> * adj = new list<ip>[n]();
		unordered_map<int, unordered_map<int, int>> edges;
		for (int i = 0; i < m; ++i) {
			int u, v;
			ll w;
			cin >> u >> v >> w;
			--u, --v;
			auto it = edges.find(u);
			if (it != end(edges)) {
				auto it2 = it->second.find(v);
				if (it2 != end(it->second)) {
					if (it2->second > w)it2->second = w;
					continue;
				}
			}
			edges[u][v] = w;
		}
		for (auto& x : edges) {
			for (auto& y : x.second) {
				int u = x.first, v = y.first;
				ll w = y.second;
				adj[u].pb(mp(v, w));
				adj[v].pb(mp(u, w));
			}
		}
		int root;
		cin >> root;
		--root;
		std::set<pair<ll, int>> bst;
		bst.insert(mp(0, root));
		vector<ll> dist(n, INF);
		dist.at(root) = 0LL;
		while (!bst.empty()) {
			pair<ll, int> temp = *bst.begin();
			bst.erase(bst.begin());
			int node = temp.second;
			std::list<ip>::const_iterator it;
			for (it = adj[node].begin(); it != adj[node].end(); ++it) {
				int v = it->first;
				ll w = it->second;
				if (dist[v] > w + dist[node]) {
					if (dist[v] != INF)bst.erase(bst.find(mp(dist[v], v)));
					dist[v] = dist[node] + w;
					bst.insert(mp(dist[v], v));
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			if (i == root)continue;
			cout << ((dist[i] == INF) ? (-1) : (dist[i]));
			if (i != (n - 1))cout << " ";
		}
		cout << endl;
	}
	return 0;
}
