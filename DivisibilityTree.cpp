#include<bits/stdc++.h>
using namespace std;

int dfs(vector<int> adj[], int node, int vis[], int &ans)
{
	vis[node] = true;
	int num_vertex = 0;
	int sz = adj[node].size();
	for (int i = 0; i < sz; i++)
	{
		if (!vis[adj[node][i]])
		{
			int num_nodes = dfs(adj, adj[node][i], vis, ans);
			if (num_nodes % 2 == 0)
				ans++;
			else
				num_vertex += num_nodes;
		}
	}
	return num_vertex + 1;
}
int main()
{
	//code
	int t;
	cin >> t;
	while (t--)
	{
		int n, e;
		cin >> n >> e;
		vector<int> adj[n + 1];
		int i, x, y;
		for (i = 0; i < e; i++)
		{
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int vis[n + 1] = { 0 };
		int ans = 0;
		for (i = 1; i <= n; i++)
		{
			if (!vis[i])
			{
				dfs(adj, i, vis, ans);
			}
		}
		cout << ans << endl;
	}
	return 0;
}