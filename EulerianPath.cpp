bool dfs(int src, int tot, const int& V, int Edges, int origin, const std::list<int>* adj) {
	if (Edges == 0 && tot >= V)return true;
	if (Edges == 0 && tot < V)return false;
	bool ans = false;
	for (std::list<int>::const_iterator ptr = adj[src].begin(); ptr != adj[src].end(); ++ptr) {
		ans = ans || dfs(*ptr, tot + 1, V, Edges - 1, origin, adj);
	}
	return ans;
}
bool Graph::isEulerianCycle()
{
	//add code here.
	{
		for (int i = 0; i < V; i++)
			if (adj[i].size() != in[i])
				return false;

		return true;
	}
	int E = 0;
	for (int i = 0; i < this->V; ++i) {
		E += (int)adj[i].size();
	}
	for (int i = 0; i < this->V; ++i) {
		if (in[i] == 0)continue;
		vector<bool> visited(this->V, false);
		bool ans = dfs(i, 1, this->V, E, i, adj);
		if (ans == true)return ans;
	}
	return false;
}