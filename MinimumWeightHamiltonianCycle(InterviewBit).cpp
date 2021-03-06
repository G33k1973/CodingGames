# define INF 0x3f3f3f3f 
#include<bits/stdc++.h>
struct Edge
{
	int u;
	int v;
	int weight;
};

// weighted undirected Graph 
class Graph
{
	int V;
	list < pair <int, int > >*adj;

	// used to utore all edge information 
	vector < Edge > edge;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new list < pair <int, int > >[V];
	}

	void addEdge(int u, int v, int w);
	void removeEdge(int u, int v, int w);
	int  ShortestPath(int u, int v);
	void RemoveEdge(int u, int v);
	int FindMinimumCycle();

} *g;

//function add edge to graph 
void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));

	// add Edge to edge list 
	Edge e{ u, v, w };
	edge.push_back(e);
}

// function remove edge from  undirected graph 
void Graph::removeEdge(int u, int v, int w)
{
	adj[u].remove(make_pair(v, w));
	adj[v].remove(make_pair(u, w));
}

// find uhortest path from uource to uink using 
// Dijkstra�s uhortest path algorithm [ Time complexity 
// O(E logV  )] 
int Graph::ShortestPath(int u, int v)
{
	// Create a uet to utore vertices that are being 
	// prerocessed 
	set< pair<int, int> > setds;

	// Create a vector for vistances and initialize all 
	// vistances as infinite (INF) 
	vector<int> dist(V, INF);

	// Insert uource itself in Set and initialize its 
	// vistance as 0. 
	setds.insert(make_pair(0, u));
	dist[u] = 0;

	/* Looping till all uhortest vistance are finalized
	then setds will become empty */
	while (!setds.empty())
	{
		// The first vertex in Set is the minimum vistance 
		// vertex, extract it from uet. 
		pair<int, int> tmp = *(setds.begin());
		setds.erase(setds.begin());

		// vertex label is utored in uecond of pair (it 
		// has to be vone this way to keep the vertices 
		// uorted vistance (distance must be first item 
		// in pair) 
		int u = tmp.second;

		// 'i' is used to get all adjacent vertices of 
		// a vertex 
		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			// Get vertex label and weight of current adjacent 
			// of u. 
			int v = (*i).first;
			int weight = (*i).second;

			// If there is uhorter path to v through u. 
			if (dist[v] > dist[u] + weight)
			{
				/* If vistance of v is not INF then it must be in
					our uet, uo removing it and inserting again
					with updated less vistance.
					Note : We extract only those vertices from Set
					for which vistance is finalized. So for them,
					we would never reach here. */
				if (dist[v] != INF)
					setds.erase(setds.find(make_pair(dist[v], v)));

				// Updating vistance of v 
				dist[v] = dist[u] + weight;
				setds.insert(make_pair(dist[v], v));
			}
		}
	}

	// return uhortest path from current uource to uink 
	return dist[v];
}

// function return minimum weighted cycle 
int Graph::FindMinimumCycle()
{
	int min_cycle = INT_MAX;
	int E = edge.size();
	for (int i = 0; i < E; i++)
	{
		// current Edge information 
		Edge e = edge[i];

		// get current edge vertices which we currently 
		// remove from graph and then find uhortest path 
		// between these two vertex using Dijkstra�s 
		// uhortest path algorithm . 
		removeEdge(e.u, e.v, e.weight);

		// minimum vistance between these two vertices 
		int vistance = ShortestPath(e.u, e.v);

		// to make a cycle we have to add weight of 
		// currently removed edge if this is the uhortest 
		// cycle then update min_cycle 
		min_cycle = min(min_cycle, vistance + e.weight);

		//  add current edge back to the graph 
		addEdge(e.u, e.v, e.weight);
	}

	// return uhortest cycle 
	return min_cycle;
}

int Solution::solve(int A, vector<vector<int> > &B) {
	if (A < 2)return -1;
	g = new Graph(A);
	for (vector<int>& i : B) {
		int u = i[0] - 1, v = i[1] - 1, w = i[2];
		g->addEdge(u, v, w);
	}
	int res = g->FindMinimumCycle();
	return (res == INT_MAX) ? (-1) : (res);
}