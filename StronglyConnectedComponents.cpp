#define MAX 10000
vector<int>*  GetTranspose(int V, vector<int> adj[]) {
	vector<int>* trans = new vector<int>[V + 1];
	for (int i = 0; i <= V; ++i) {
		//if(adj[i].empty())continue;
		for (auto it = adj[i].begin(); it != adj[i].end(); ++it) {
			trans[*it].push_back(i);
		}
	}
	return trans;
}
void DFS1(int src, int V, vector<int> adj[], vector<bool>& vis, stack<int>& st) {
	vis.at(src) = true;
	for (auto it = adj[src].begin(); it != adj[src].end(); ++it) {
		if (!vis[*it])DFS1(*it, V, adj, vis, st);
	}
	st.push(src);
}
void DFS2(int src, int V, vector<int> adj[], vector<bool>& vis) {
	vis.at(src) = true;
	for (auto it = adj[src].begin(); it != adj[src].end(); ++it) {
		if (!vis[*it])DFS2(*it, V, adj, vis);
	}
	return;
}
int kosaraju(int V, vector<int> adj[])
{
	// Your code here
	std::stack<int> Stack_;
	vector<bool> vis(V + 1, false);
	for (int i = 0; i < V; ++i) {
		if (!vis[i]) {
			DFS1(i, V, adj, vis, Stack_);
		}
	}
	int res = 0;
	vector<int>* adj2 = GetTranspose(V, adj);
	std::fill(begin(vis), end(vis), false);
	while (!Stack_.empty()) {
		int Node = Stack_.top();
		Stack_.pop();
		if (!vis[Node]) {
			DFS2(Node, V, adj2, vis);
			++res;
		}
	}
	return res;
}