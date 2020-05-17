class Solution {
public:

	int find(vector<int>&parent, int node)
	{
		if (parent[node] == node)
			return node;
		return find(parent, parent[node]);
	}

	bool unionfunc(int stone1, int stone2, vector<int>&parent, vector<int>&size)
	{
		int set1 = find(parent, stone1);
		int set2 = find(parent, stone2);
		if (set1 == set2) return false;

		if (size[set1] <= size[set2])
		{
			parent[set1] = set2;
			size[set2]++;
		}
		else
		{
			parent[set2] = set1;
			size[set1]++;
		}
		return true;
	}

	int removeStones(vector<vector<int>>& stones) {
		int n = stones.size();
		int components = n;
		vector<int>parent(n);
		vector<int>size(n, 0);
		for (int i = 0; i < n; i++) parent[i] = i;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
				{
					if (unionfunc(i, j, parent, size)) components--;
				}
			}
		}
		return n - components;
	}
};