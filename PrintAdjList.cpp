//https://practice.geeksforgeeks.org/problems/print-adjacency-list/1
{
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
class Graph
{
	int V;
	vector<int> *adj;

public:
	Graph(int V);
	void addEdge(int u, int v);
	void printGraph();
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new vector<int>[V + 1];
}
void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
//Position this line where user code will be pasted.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int v, e;
		cin >> v >> e;
		int a, b;
		Graph g(v);
		for (int i = 0; i < e; i++)
		{
			cin >> a >> b;
			g.addEdge(a, b);

		}
		g.printGraph();

	}
	return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

// The Graph structure is as folows
void Graph::printGraph()
{
	string s("-> ");
	// Your code here
	for (int i = 0; i < (*this).V; ++i) {
		std::vector<int>::iterator it;
		cout << i;
		if (this->adj[i].empty()) {
			cout << endl;
			continue;
		}
		else cout << s;
		for (it = this->adj[i].begin(); it != this->adj[i].end(); ++it) {
			if (std::next(it, 1) != this->adj[i].end())cout << *it << s;
			else cout << *it;
		}
		cout << endl;
	}
	//cout<<endl;
}