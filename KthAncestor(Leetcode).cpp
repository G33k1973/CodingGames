class TreeAncestor {
public:
	vector<int> ar[50005];
	pair<int, int> child[50005];
	TreeAncestor(int n, vector<int>& parent) {
		bool vis[n];
		memset(vis, false, sizeof(vis));
		for (int i = 1; i < parent.size(); i++)
		{
			vis[parent[i]] = true;
		}
		for (int i = 0; i < n; i++)
		{
			if (vis[i] == false)
			{
				vector<int> v1;
				int node = i;
				child[i] = { i,0 };
				int c = 1;
				while (node != -1)
				{
					node = parent[node];
					if (node == -1)
						break;
					child[node] = { i,c++ };
					v1.push_back(node);
				}
				ar[i] = v1;
			}
		}
	}

	int getKthAncestor(int node, int k) {
		int p = child[node].first;
		int step = child[node].second;
		int size = ar[p].size() - step;
		if (k > size)
			return -1;
		return ar[p][k - 1 + step];
	}
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */