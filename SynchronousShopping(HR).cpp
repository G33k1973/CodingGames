#include <bits/stdc++.h>
#define N 1025
#define oo 1234567890

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector< pair<int, int> > road[N];
priority_queue<iii, vector<iii>, greater<iii> > Q;

int n, m, k, ans, fish[N], dis[N][N];

void dijkstra()
{
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j < (1 << k); ++j) dis[i][j] = oo;
	Q.push(iii(0, ii(1, fish[1])));
	dis[1][fish[1]] = 0;
	// dis[i][state] : smallest weights to achieve state at node i

	while (Q.size())
	{
		// st : state   nst : new state   u,v : node   du, uv : weight
		int u = Q.top().second.first,
			du = Q.top().first,
			st = Q.top().second.second;
		Q.pop();

		if (du != dis[u][st]) continue;

		for (auto i : road[u]) {
			int v = i.second,
				uv = i.first,
				nst = st | fish[v];
			if (dis[v][nst] > uv + du) {
				dis[v][nst] = uv + du;
				Q.push(iii(dis[v][nst], ii(v, nst)));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		int t, x; fish[i] = 0;
		cin >> t;
		while (t--) {
			cin >> x;
			fish[i] |= (1 << (x - 1));
			/*fish[i] : represent types of fish at node i by bitmask technique
						we call this as a state */
		}
	}
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		road[u].push_back(make_pair(w, v));
		road[v].push_back(make_pair(w, u));
	}

	dijkstra();

	ans = oo;
	for (int i = 0; i < (1 << k); ++i)
		for (int j = i; j < (1 << k); ++j)
			if ((i | j) == (1 << k) - 1) // means achieve state 11...111(k times) 
				ans = min(ans, max(dis[n][i], dis[n][j]));
	cout << ans;
	return 0;
}