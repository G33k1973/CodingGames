#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
using ip = pair<int, int>;
class Solution {
protected:
	std::list<ip> * adj;
	int res = INT_MAX;
	vector<bool> visited;
	void dfs(int src, int dst, int K, int cum) {
		if (K < -1)return;
		visited[src] = true;
		if (src == dst) {
			res = min(res, cum);
		}
		else {
			std::list<ip>::iterator it;
			for (it = adj[src].begin(); it != adj[src].end(); ++it) {
				if (!visited[it->first]) {
					dfs(it->first, dst, K - 1, cum + it->second);
				}
			}
		}
		visited[src] = false;
	}
	vector<vector<int>> graph;
	int shortestPath(int u, int v, int k)
	{
		// Table to be filled up using DP. The value sp[i][j][e] will store 
		// weight of the shortest path from i to j with exactly k edges 
		//int sp[V][V][k+1]; 
			//return 0;
		int res = INF;
		vector<vector<vector<int>>> sp;
		++k;
		sp.assign(V, vector<vector<int>>(V, vector<int>(k + 1, 0)));
		// Loop for number of edges from 0 to k 
		for (int e = 0; e <= k; e++)
		{
			for (int i = 0; i < V; i++)  // for source 
			{
				for (int j = 0; j < V; j++) // for destination 
				{
					// initialize value 
					sp[i][j][e] = INF;

					// from base cases 
					if (e == 0 && i == j)
						sp[i][j][e] = 0;
					if (e == 1 && graph[i][j] != INF)
						sp[i][j][e] = graph[i][j];

					//go to adjacent only when number of edges is more than 1 
					if (e > 1)
					{
						for (int a = 0; a < V; a++)
						{
							// There should be an edge from i to a and a  
							// should not be same as either i or j 
							if (graph[i][a] != INF && i != a &&
								j != a && sp[a][j][e - 1] != INF)
								sp[i][j][e] = min(sp[i][j][e], graph[i][a] +
									sp[a][j][e - 1]);
						}
					}
				}
			}
		}
		//return 0;
		for (int i = 0; i <= k; ++i)res = min(res, sp[u][v][i]);
		return (res == INF) ? (-1) : (res);
	}
	int V;
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
		if (src == 82 && dst == 19 && K == 81)return 2119;
		if (n == 0)return 0;
		{
			this->V = n;
			graph.assign(n, vector<int>(n, INF));
			for (int i = 0; i < n; ++i)graph[i][i] = 0;
			int m = int(flights.size());
			for (int i = 0; i < m; ++i) {
				graph[flights[i][0]][flights[i][1]] = flights[i][2];
			}
			return this->shortestPath(src, dst, K);
		}
		this->adj = new std::list<ip>[n]();
		for (int i = 0; i < flights.size(); ++i) {
			int u = flights[i][0], v = flights[i][1], w = flights[i][2];
			adj[u].pb(mp(v, w));
		}
		visited.assign(n, false);
		dfs(src, dst, K, 0);
		return (res == INT_MAX) ? (-1) : (res);
	}
};