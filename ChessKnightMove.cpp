#define M 1000000007
using ll = unsigned long long int;
#define ms(a,b) (((a%M)+(b%M))%M)
vector<vector<char>> grid{ {'1','2','3'},{'4','5','6'},{'7','8','9'},{'#','0','#'} };
int x[] = { 2,2,-2,-2,1,1,-1,-1 };
int y[] = { 1,-1,1,-1,2,-2,2,-2 };
class Solution {
	int n, m;
	vector<vector<vector<ll>>> dp;
	bool isvalid(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m&&grid[i][j] != '#');
	}
	ll dfs(int N, int i, int j) {
		if (N == 1)return 1;
		if (dp[i][j][N] != 0)return dp[i][j][N];
		ll ans = 0;
		for (int k = 0; k < 8; ++k) {
			int ni = i + x[k];
			int nj = j + y[k];
			if (isvalid(ni, nj)) {
				ans = ms(ans, dfs(N - 1, ni, nj));
			}
		}
		return dp[i][j][N] = ans;
	}
public:
	int knightDialer(int N) {
		n = (int)grid.size();
		m = (int)grid[0].size();
		dp.assign(n, vector<vector<ll>>(m, vector<ll>(N + 1, 0)));
		ll res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == '#')continue;
				res = ms(res, dfs(N, i, j));
			}
		}
		return res;
	}
};