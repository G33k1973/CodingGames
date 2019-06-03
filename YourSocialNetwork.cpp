#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class graph {
private:
	int V;
	std::list<int> * adj;
public:
	graph() {
		this->adj = NULL;
		this->V = 0;
	}
	graph(int V) {
		this->V = V;
		this->adj = new list<int>[this->V];
	}
	void ae(int u, int v) {
		this->adj[u - 1].push_back(v - 1);
	}
	void DFSutil(int s, int c, map<int, int>& m) {
		for (auto& x : this->adj[s]) {
			m[x] = c;
			DFSutil(x, c + 1, m);
		}
	}
	void solve() {
		for (int i = 1; i < this->V; ++i) {
			map<int, int> m;
			this->DFSutil(i, 1, m);
			if (m.empty())continue;
			int sm = int(m.size());
			auto it = begin(m);
			while (it != end(m)) {
				cout << i + 1 << ' ' << it->first + 1 << ' ' << it->second << ' ';
				++it;
			}
		}
		cout << "\n";
	}
};
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		graph g(n);
		for (int i = 2; i <= n; ++i) {
			int x;
			cin >> x;
			g.ae(i, x);
		}
		g.solve();
	}
	return 0;
}