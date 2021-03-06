//https://leetcode.com/problems/critical-connections-in-a-network/discuss/391477/C%2B%2B-solution-with-some-visualization-...
class Solution {
public:
	int verbose = 0;
#define print if (verbose) cout
	void dfs(int v,          /* to vertex */
		int w,          /* from vertex */
		int et,         /* entry time */
		vector<vector<int>>& adj/*acency list of the graph */,
		vector<bool>& vi/*sited */,
		vector<int>& ts,
		vector<int>& mn,
		vector<int>& br/*idge*/) {

		vi[v] = 1;      /* mark vertex v as visited */
		ts[v] = et;     /* entry time stamp for vertex */
		mn[v] = et++;   /* minimum time stamp for vertex */
		print << "Timestamping vertex " << v << ": " << ts[v] << endl;
		for (auto x : adj[v]) { /* visit vertex's neighbors */
			if (x == w) continue;
			if (vi[x]) {
				mn[v] = min(mn[v], ts[x]);
				print << "Already visited: " << " v: " << v << " x: " << x << " mn[v]: " << mn[v] << " ts[x]: " << ts[x] << endl;
			}
			else {
				print << "Recur " << x << " " << v << endl;
				dfs(x, v, et, adj, vi, ts, mn, br);
				mn[v] = min(mn[v], mn[x]);
				print << "Checking edge (x, v): " << x << " " << v << " mn[v]: " << mn[v] << " mn[x]: " << mn[x] << " ts[v]: " << ts[v];
				if (mn[x] > ts[v]) { print << " (found)"; br.push_back(x); br.push_back(v); }
				cout << endl;
			}
		}
	}

	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		vector<vector<int>> bridges;
		vector<int> br/*idge*/;
		vector<vector<int>> adj(n);
		vector<bool> vi/*isited*/(n, 0);
		vector<int> ts(n, -1), mn(n, -1);

		/* Given all the edges, construct an adjacency list */
		for (auto c : connections) { adj[c[0]].push_back(c[1]); adj[c[1]].push_back(c[0]); }

		/* Do DFS for every vertex that has not been visited yet */
		for (int i = 0; i < n; i++) {
			if (!vi[i]) { print << "starting: " << i << endl; dfs(i, -1, 1, adj, vi, ts, mn, br); }
		}

		/* Pack found bridges into return vector */
		for (int i = 0; i < br.size(); i += 2) {
			vector<int> t; t.push_back(br[i + 1]); t.push_back(br[i]); bridges.push_back(t);
		}

		return bridges;
	}
};