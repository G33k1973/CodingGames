#include <bits/stdc++.h>
using namespace std;
enum color { WHITE, GRAY, BLACK };
bool IsCyclic(vector<unordered_set<int>>& graph, int src, unordered_set<int>& seen, vector<color>& Col) {
	Col[src] = GRAY;
	seen.insert(src);
	bool ans = false;
	for (auto& x : graph[src]) {
		if (Col[x] == WHITE && IsCyclic(graph, x, seen, Col))return true;
		if (Col[x] == GRAY)return true;
	}
	Col[src] = BLACK;
	seen.erase(src);
	return ans;
}
int findStreets(int n, int m, vector< vector<int> >& street, vector<unordered_set<int>>& graph) {
	// Complete this function
	int res = 0;
	unordered_set<int> CycleNodes;
	for (int i = 0; i < m; ++i) {
		int u = street[i][0];
		int v = street[i][1];
		if (CycleNodes.count(u) > 0 && CycleNodes.count(v) > 0) {
			++res;
			continue;
		}
		vector<color> Col(n, WHITE);
		Col[u] = GRAY;
		unordered_set<int> seen{ u };
		bool cyclic = IsCyclic(graph, v, seen, Col);
		if (cyclic) {
			for (auto& x : seen)CycleNodes.insert(x);
			++res;
		}
	}
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++) {
		int n;
		int m;
		cin >> n >> m;
		vector<unordered_set<int>> graph(n, unordered_set<int>{});
		vector<vector<int>> street(m, vector<int>(2, 0));
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			--u, --v;
			street[i][0] = u;
			street[i][1] = v;
			auto it = graph[u].find(v);
			if (it == end(graph[u])) {
				graph[u].insert(v);
			}
		}
		int result = findStreets(n, m, street, graph);
		cout << result << endl;
	}
	return 0;
}