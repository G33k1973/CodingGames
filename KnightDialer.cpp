#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
using ll = long long int;
int X[] = { 1,1,-1,-1,2,2,-2,-2 };
int Y[] = { 2,-2,2,-2,1,-1,1,-1 };
class Solution {
protected:
	vector<vector<int>> board;
	vector<vector<vector<ll>>> dp;
	int n, m;
	bool isvalid(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m&&board[i][j] >= 0);
	}
	ll dfs(int N, int i, int j) {
		if (N == 0)return 1LL;
		if (dp[i][j][N] != -1)return dp[i][j][N];
		ll ans = 0;
		for (int k = 0; k < 8; ++k) {
			int ni = i + X[k], nj = j + Y[k];
			if (isvalid(ni, nj))ans = ms(ans, dfs(N - 1, ni, nj));
		}
		return dp[i][j][N] = ans;
	}
public:
	int knightDialer(int N) {
		vector<vector<int>> grid{ {1,2,3},{4,5,6},{7,8,9},{-1,0,-1} };
		board = std::move(grid);
		this->n = 4;
		this->m = 3;
		dp.assign(n + 1, vector<vector<ll>>(m + 1, vector<ll>(N, -1)));
		ll res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (board[i][j] == -1)continue;
				res = ms(res, dfs(N - 1, i, j));
			}
		}
		return res;
	}
};