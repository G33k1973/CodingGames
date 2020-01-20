using ip = pair<int, int>;
using iip = pair<ip, int>;
int X[4] = { 1,-1,0,0 };
int Y[4] = { 0,0,-1,+1 };
bool isgood(int i, int j, int n, int m) {
	return (i >= 0 && j >= 0 && i < n&&j < m);
}
int Solution::solve(vector<vector<int> > &A) {
	int n = int(A.size());
	if (n == 0)return -1;
	int m = int(A.front().size());
	if (m == 0)return -1;
	int fo = 0;
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	queue<iip> pile;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (A[i][j] == 0)continue;
			else if (A[i][j] == 1)++fo;
			else {
				visited[i][j] = 1;
				pile.push(make_pair(make_pair(i, j), 0));
			}
		}
	}
	if (fo == 0)return 0;
	if (pile.empty())return -1;
	while (!pile.empty()) {
		int sz = int(pile.size());
		int i = 0;
		while (i < sz) {
			iip current = pile.front();
			pile.pop();
			int oi = current.first.first;
			int oj = current.first.second;
			int w = current.second;
			for (int j = 0; j < 4; ++j) {
				int ni = oi + X[j];
				int nj = oj + Y[j];
				if (isgood(ni, nj, n, m) && !visited[ni][nj] && A[ni][nj] == 1) {
					--fo;
					if (fo == 0)return w + 1;
					pile.push(make_pair(make_pair(ni, nj), w + 1));
					visited[ni][nj] = 1;
				}
			}
			++i;
		}
	}
	return -1;
}