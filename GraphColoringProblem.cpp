#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
bool isSafe(int v, const std::vector<std::vector<bool>>& graph, int V, int color[], int c)
{
	for (int i = 0; i < V; i++)
		if (graph[v][i] && c == color[i])
			return false;
	return true;
}

/* A recursive utility function to solve m coloring problem */
bool graphColoringUtil(const std::vector<std::vector<bool>>& graph, int V, int m, int color[], int v)
{
	/* base case: If all vertices are assigned a color then
	   return true */
	if (v == V)
		return true;

	/* Consider this vertex v and try different colors */
	for (int c = 1; c <= m; c++)
	{
		/* Check if assignment of color c to v is fine*/
		if (isSafe(v, graph, V, color, c))
		{
			color[v] = c;

			/* recur to assign colors to rest of the vertices */
			if (graphColoringUtil(graph, V, m, color, v + 1) == true)
				return true;

			/* If assigning color c doesn't lead to a solution
			   then remove it */
			color[v] = 0;
		}
	}

	/* If no color can be assigned to this vertex then return false */
	return false;
}

/* This function solves the m Coloring problem using Backtracking.
  It mainly uses graphColoringUtil() to solve the problem. It returns
  false if the m colors cannot be assigned, otherwise return true and
  prints assignments of colors to all vertices. Please note that there
  may be more than one solutions, this function prints one of the
  feasible solutions.*/
int graphColoring(const std::vector<std::vector<bool>>& graph, int V, int m)
{
	// Initialize all color values as 0. This initialization is needed 
	// correct functioning of isSafe() 
	int color[V];
	for (int i = 0; i < V; i++)
		color[i] = 0;

	// Call graphColoringUtil() for vertex 0 
	if (graphColoringUtil(graph, V, m, color, 0) == false)
	{
		return 0;
	}

	// Print the solution 
	return 1;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int m;
		cin >> m;
		int e;
		cin >> e;
		std::vector<std::vector<bool>> G(n, std::vector<bool>(n, false));
		for (int i = 0; i < e; ++i) {
			int u, v;
			cin >> u >> v;
			--u, --v;
			G[u][v] = 1;
			G[v][u] = 1;
		}
		cout << graphColoring(G, n, m) << endl;
	}
	return 0;
}