using ip = pair<int, int>;
using iip = pair<ip, int>;//[[i,j],dist]
#define pb push_back
#define mp make_pair
bool isvalid(int i, int j, int n, int m) {
	return (i >= 0 && j >= 0 && i < n&&j < m);
}
int Solution::solve(vector<vector<int> > &A) {
	int n = int(A.size());
	if (n == 0)return -1;
	int m = int(A.front().size());
	if (m == 0)return -1;
	int X[4] = { 1,-1,0,0 };
	int Y[4] = { 0,0,-1,+1 };
	int c2 = 0, c0 = 0;
	queue<iip> pile;
	int i, j;
	vector<ip> arr;
	int nbuildings = 0;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (A[i][j] == 0) {
				arr.pb(mp(i, j));
				++c0;
			}
			else if (A[i][j] == 2)++c2;
			else {
				++nbuildings;
			}
		}
	}
	if (nbuildings == 0) {
		if (c2 == n * m)return -1;
		return 0;
	}
	if (nbuildings == (n*m))return -1;
	if (c0 == 0)return -1;
	int res = INT_MAX;
	for (const ip& x : arr) {
		int c = nbuildings;
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		visited[x.first][x.second] = true;
		while (!pile.empty())pile.pop();
		pile.push(mp(mp(x.first, x.second), 0));
		int sum = 0;
		while (!pile.empty()) {
			int sz = int(pile.size());
			int u = 0;
			while (u < sz) {
				iip current = pile.front();
				pile.pop();
				int oi = current.first.first;
				int oj = current.first.second;
				int w = current.second;
				for (int k = 0; k < 4; ++k) {
					int ni = oi + X[k];
					int nj = oj + Y[k];
					if (isvalid(ni, nj, n, m) && A[ni][nj] != 2) {
						if (!visited[ni][nj]) {
							visited[ni][nj] = true;
							if (A[ni][nj] == 1) {
								sum += w + 1;
								--c;
								if (c == 0) {
									res = min(res, sum);
									break;
								}
							}
							else pile.push(mp(mp(ni, nj), w + 1));
						}
					}
				}
				if (c == 0)break;
				++u;
			}
			if (c == 0)break;
		}
	}
	return (res == INT_MAX) ? (-1) : (res);
}
