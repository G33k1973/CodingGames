#define pb push_back
using ip = std::pair<int, int>;
#define mp make_pair
#define INF 0x3f3f3f3f
int x[] = { 1,-1,0,0 };
int y[] = { 0,0,-1,+1 };
class Solution {
protected:
	int n, m;
	vector<ip> arr, src;
	vector<vector<ip>> cont;
	bool isValid(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m);
	}
	void dfs(std::vector<std::vector<int>>& grid, int i, int j) {
		arr.pb(mp(i, j));
		grid[i][j] = INF;
		for (int k = 0; k < 4; ++k) {
			int ni = i + x[k];
			int nj = j + y[k];
			if (isValid(ni, nj) && grid[ni][nj] == 1) {
				dfs(grid, ni, nj);
			}
		}
		return;
	}
	bool IsMatch(const std::vector<ip>& a, const std::vector<ip>& b, const ip& srca, const ip& srcb) {
		if (a.size() != b.size())return 0;
		int aXstart = srca.first;
		int aYstart = srca.second;
		int bXstart = srcb.first;
		int bYstart = srcb.second;
		for (int i = 0; i < (int)a.size(); ++i) {
			int DXa = a[i].first - aXstart;
			int DYa = a[i].second - aYstart;
			int DXb = b[i].first - bXstart;
			int DYb = b[i].second - bYstart;
			if (DXa != DXb || DYa != DYb)return 0;
		}
		return true;
	}
public:
	int numDistinctIslands(vector<vector<int>>& grid) {
		this->src.clear();
		this->cont.clear();
		this->n = (int)grid.size();
		if (n == 0)return 0;
		this->m = (int)grid[0].size();
		if (m == 0)return 0;
		int i, j;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				if (grid[i][j] == INF || grid[i][j] == 0)continue;
				if (arr.size())arr.clear();
				src.pb(mp(i, j));
				dfs(grid, i, j);
				cont.pb(arr);
			}
		}
		int N = (int)cont.size();
		if (N < 2)return N;
		for (i = 0; i < N; ++i) {
			std::sort(cont[i].begin(), cont[i].end(), [](const ip& x, const ip& y) {if (x.first == y.first)return x.second < y.second; return x.first < y.first; });
		}
		int res = 0;
		vector<bool> vis(N, 0);
		for (i = 0; i < N; ++i) {
			if (vis[i])continue;
			for (j = i + 1; j < N; ++j) {
				if (this->IsMatch(cont[i], cont[j], src[i], src[j]))vis[j] = 1;
			}
			vis[i] = true;
			++res;
		}
		return res;
	}
};