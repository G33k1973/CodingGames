class Solution {
public:

	vector<vector<int>> adjacent;
	vector<int> low;
	vector<int> find;
	int time = 0;

	vector<vector<int>> res;

	void getAdjacent(vector<vector<int>>& conn, int n) {
		adjacent.resize(n);
		for (vector<int> e : conn) {
			adjacent[e[0]].push_back(e[1]);
			adjacent[e[1]].push_back(e[0]);
		}
	}

	void dfs_visit(int curr, int parent) {
		time++;
		find[curr] = time;
		low[curr] = time;
		for (int n : adjacent[curr]) {
			if (n == parent) continue;
			if (find[n] == 0) {
				// not visit
				dfs_visit(n, curr);
				// Tarjan algorithm: if low[son] > find[parent]
				if (low[n] > find[curr]) {
					vector<int> t = { n, curr };
					res.push_back(t);
				}
			}
			low[curr] = min(low[curr], low[n]);
		}

	}

	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		getAdjacent(connections, n);
		low.resize(n);
		find.resize(n);
		dfs_visit(0, -1);
		return res;
	}
};