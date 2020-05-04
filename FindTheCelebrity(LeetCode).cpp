/* The knows API is defined for you.
	  bool knows(int a, int b); */

class Solution {
public:
	int findCelebrity(int n) {
		if (n == 0)return -1;
		if (n == 1)return 0;
		vector<vector<bool>> graph(n, vector<bool>(n, false));
		vector<int> visited(n, 0);
		unordered_set<int> known;
		unordered_set<int> possibles;
		int i, j;
		for (i = 0; i < n; ++i) {
			int left = n - i;
			for (j = 0; j < n; ++j) {
				if (i == j || (visited[j] + left < n - 1))continue;
				graph[i][j] = knows(i, j);
				if (graph[i][j]) {
					if (known.count(i) == 0)known.insert(i);
					if (int(known.size()) == n)return -1;
					++visited[j];
					if (visited[j] == (n - 1))possibles.insert(j);
				}
			}
		}
		for (const int& x : possibles) {
			if (known.count(x) == 0)return x;
		}
		return -1;
	}
};