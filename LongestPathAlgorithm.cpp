#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef std::pair<int, int> ip;
#define pb push_back
#define mp make_pair
#define NINF -999999
class Graph {
private:
	int V;
	std::list<ip> * adj;
	void TopologicalSort(int src, std::vector<bool>& visited, stack<int>& s) {
		visited.at(src) = 1;
		for (auto& x : this->adj[src]) {
			int u = x.first;
			int w = x.second;
			if (!visited[u])this->TopologicalSort(u, visited, s);
		}
		s.push(src);
	}
	int LongestPath(int src, const std::unordered_set<int>& memo) {
		std::vector<bool> visited(this->V, false);
		stack<int> s;
		this->TopologicalSort(src, visited, s);
		vector<int> dist(this->V, NINF);
		dist.at(src) = 0;
		int res = INT_MIN;
		while (!s.empty()) {
			int u = s.top();
			s.pop();
			std::list<ip>::iterator ptr = this->adj[u].begin();
			while (ptr != this->adj[u].end()) {
				int v = ptr->first;
				int w = ptr->second;
				if (dist[v] < dist[u] + w) {
					dist[v] = dist[u] + w;
					if (memo.count(v) > 0)res = max(res, dist[v]);
				}
				++ptr;
			}
		}
		return res;
	}
public:
	Graph() {
		(*this).V = -1;
		(*this).adj = nullptr;
	}
	Graph(int V) {
		this->V = V;
		this->adj = new list<ip>[this->V]();
	}
	void ae(int u, int v, int w) {
		--u, --v;
		this->adj[u].pb(mp(v, w));
		this->adj[v].pb(mp(u, w));
	}
	int solve() {
		unordered_set<int> leaves;
		for (int i = 0; i < V; ++i) {
			if (this->adj[i].size() == 1)leaves.insert(i);
		}
		std::unordered_set<int>::iterator ptr = begin(leaves);
		while (ptr != end(leaves)) {
			int src = *ptr;
			++ptr;
		}
		int res = INT_MIN;
		for (const auto& x : leaves) {
			res = std::max(res, this->LongestPath(x, leaves));
		}
		return res;
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
			int u, v, w;
			cin >> u >> v >> w;
			G.ae(u, v, w);
		}
		cout << G.solve() << "\n";
	}
	return 0;
}