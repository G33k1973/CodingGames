#define pb push_back
int Solution::solve(int A, vector<vector<int> > &B) {
	if (A < 3)return 1;
	vector<vector<int>> graph(A, vector<int>());
	for (vector<int>& i : B) {
		int u = i.front();
		int v = i.back();
		graph[u].pb(v);
		graph[v].pb(u);
	}
	vector<bool> visited(A, false);
	enum COLORS { WHITE, RED, BLACK };
	vector<COLORS> colors(A, WHITE);
	for (int k = 0; k < A; ++k) {
		if (visited[k])continue;
		std::queue<int> pile;
		pile.push(k);
		colors.at(k) = RED;
		visited.at(k) = true;
		while (!pile.empty()) {
			int sz = int(pile.size());
			int i = 0;
			while (i < sz) {
				int node = pile.front();
				pile.pop();
				for (int& j : graph[node]) {
					if (!visited[j]) {
						if (colors[node] == RED) {
							colors[j] = BLACK;
						}
						else
							colors[j] = RED;
						visited[j] = true;
						pile.push(j);
					}
					else {
						if (colors[j] == colors[node])return 0;
					}
				}
				++i;
			}
		}
	}
	return 1;
}
