class Solution {
private:
	int n, m;
	vector<string> res;
	bool isvalid(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m);
	}
	int X[4] = { 1,-1,0,0 };
	int Y[4] = { 0,0,-1,+1 };
	bool dfs(vector<vector<char>>& board, int i, int j, int c, int l, string& s) {
		if (c == l)return true;
		char old = board[i][j];
		board[i][j] = '#';
		bool ans = false;
		for (int u = 0; u < 4; ++u) {
			int ni = i + X[u];
			int nj = j + Y[u];
			if (isvalid(ni, nj) && board[ni][nj] != '#'&&board[ni][nj] == s[c]) {
				ans = ans || dfs(board, ni, nj, c + 1, l, s);
			}
		}
		board[i][j] = old;
		return ans;
	}
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		this->n = int(board.size());
		if (n == 0)return vector<string>{};
		this->m = int(board[0].size());
		if (m == 0)return vector<string>{};
		for (string& i : words) {
			int l = int(i.size());
			if (l == 0)continue;
			bool suc = false;
			for (int u = 0; u < n; ++u) {
				for (int v = 0; v < m; ++v) {
					if (board[u][v] == i.front()) {
						suc = suc || dfs(board, u, v, 1, l, i);
						if (suc)break;
					}
				}
				if (suc)break;
			}
			if (suc)res.push_back(i);
		}
		return res;
	}
};