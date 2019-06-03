#include<bits/stdc++.h> 

using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	void countPathsUtil(int, int, bool[],
		int &);

public:
	Graph(int V);
	void addEdge(int u, int v);
	int countPaths(int s, int d);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V + 1];
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}

int Graph::countPaths(int s, int d)
{
	bool *visited = new bool[V + 1];
	memset(visited, false, sizeof(visited));

	int pathCount = 0;
	countPathsUtil(s, d, visited, pathCount);
	return pathCount;
}

void Graph::countPathsUtil(int u, int d, bool visited[],
	int &pathCount)
{
	visited[u] = true;

	if (u == d)
		pathCount++;

	else
	{
		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
			if (!visited[*i])
				countPathsUtil(*i, d, visited, pathCount);
	}
	visited[u] = false;
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		int u, v;
		Graph g(N);
		while (M--) {
			cin >> u >> v;
			g.addEdge(u, v);
		}
		int s, e;
		cin >> s >> e;
		cout << g.countPaths(s, e) << endl;
	}
	return 0;
}