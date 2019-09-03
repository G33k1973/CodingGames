class Solution {
public:
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
		// Build adjacency list graph with edge color annotation
		// 0 - red color and 1 - blue color
		vector<vector<vector<int>>> graph(n);

		for (auto& e : red_edges) {
			graph[e[0]].push_back({ 0, e[1] });
		}

		for (auto& e : blue_edges) {
			graph[e[0]].push_back({ 1, e[1] });
		}

		// Level order BFS 
		// Visited each node with a incoming edge color annotation
		vector<int> dist(n, -1);
		vector<vector<bool>> visited(n, vector<bool>(2, false));
		queue<pair<int, int>> qu;
		int depth = -1;

		// Star node 0 with red and blue color
		qu.push({ 0, 0 });
		qu.push({ 0, 1 });

		visited[0][0] = true;
		visited[0][1] = true;
		dist[0] = 0;

		while (!qu.empty()) {
			++depth;

			int size = qu.size();
			for (int i = 0; i < size; ++i) {
				auto[v, c] = qu.front();

				qu.pop();
				dist[v] = dist[v] == -1 ? depth : min(dist[v], depth);

				for (auto& e : graph[v]) {
					if (e[0] == c) {
						continue;
					}

					int nv = e[1];
					int nc = 1 ^ c;

					if (visited[nv][nc]) {
						continue;
					}

					visited[nv][nc] = true;
					qu.push({ nv, nc });
				}
			}
		}

		return dist;
	}
};