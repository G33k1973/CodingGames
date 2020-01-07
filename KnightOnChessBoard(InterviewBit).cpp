int X[8] = { 2,2,-2,-2,1,1,-1,-1 };
int Y[8] = { 1,-1,1,-1,2,-2,2,-2 };
bool isvalid(int i, int j, int n, int m) {
	return (i >= 0 && j >= 0 && i < n&&j < m);
}
using ip = std::pair<int, int>;
using iip = std::pair<ip, int>;
#define pb push_back
#define mp make_pair
int Solution::knight(int A, int B, int C, int D, int E, int F) {
	if (A == 0 || B == 0)return -1;
	int n = A, m = B;
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	visited[C - 1][D - 1] = true;
	std::queue<iip> pile;
	pile.push(mp(mp(C - 1, D - 1), 0));
	while (!pile.empty()) {
		int sz = static_cast<int>(pile.size());
		int i = 0;
		while (i < sz) {
			iip current = pile.front();
			pile.pop();
			int oi = current.first.first, oj = current.first.second;
			int w = current.second;
			if (oi == (E - 1) && oj == (F - 1))return w;
			for (int u = 0; u < 8; ++u) {
				int ni = oi + X[u];
				int nj = oj + Y[u];
				if (isvalid(ni, nj, n, m) && !visited[ni][nj]) {
					visited[ni][nj] = true;
					pile.push(mp(mp(ni, nj), w + 1));
				}
			}
			++i;
		}
	}
	return -1;
}