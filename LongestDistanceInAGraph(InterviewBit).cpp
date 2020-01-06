#define pb push_back
#define mp make_pair
typedef std::pair<int, int> ip;
vector<vector<int>> graph;
int n;
int Solution::solve(vector<int> &A) {
	n = int(A.size());
	if (n == 0)return 0;
	if (n == 1)return 0;
	if (n == 2)return 1;
	int root = -1;
	graph.assign(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		if (A[i] == -1) {
			root = i;
			continue;
		}
		graph[i].pb(A[i]);
		graph[A[i]].pb(i);
	}
	std::queue<ip> pile;
	vector<bool> visited(n, false);
	visited[root] = true;
	pile.push(mp(root, 0));
	vector<int> dist(n, 0);
	while (!pile.empty()) {
		int sz = int(pile.size());
		int i = 0;
		while (i < sz) {
			ip temp = pile.front();
			pile.pop();
			int u = temp.first;
			int w = temp.second;
			for (auto& x : graph[u]) {
				if (!visited[x]) {
					visited[x] = true;
					dist[x] = w + 1;
					pile.push(mp(x, dist[x]));
				}
			}
			++i;
		}
	}
	ip leafnode(-1, 0);
	for (int i = 0; i < n; ++i) {
		if (dist[i] > leafnode.second) {
			leafnode = mp(i, dist[i]);
		}
	}
	visited.assign(n, false);
	int src = leafnode.first;
	visited[src] = true;
	dist.assign(n, 0);
	while (!pile.empty())pile.pop();
	pile.push(mp(src, 0));
	while (!pile.empty()) {
		int sz = int(pile.size());
		int i = 0;
		while (i < sz) {
			ip temp = pile.front();
			pile.pop();
			int u = temp.first;
			int w = temp.second;
			for (auto& x : graph[u]) {
				if (!visited[x]) {
					visited[x] = true;
					dist[x] = w + 1;
					pile.push(mp(x, dist[x]));
				}
			}
			++i;
		}
	}
	int res = INT_MIN;
	for (int i = 0; i < n; ++i) {
		res = max(res, dist[i]);
	}
	return res;
}
