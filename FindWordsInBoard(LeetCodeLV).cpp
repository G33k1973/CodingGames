class Solution {
protected:
	int n, m;
	vector<pair<int, int>> dirs{ {1,0},{-1,0},{0,1},{0,-1} };
	bool seek(vector<vector<char>>& board, int i, int j, int l, int c, const string& s) {
		if (c == l)return true;
		char oc = board[i][j];
		bool ans = false;
		board[i][j] = '#';
		auto isgood = [this](int i, int j) {
			return (i >= 0 && j >= 0 && i < this->n&&j < this->m);
		};
		for (auto& x : dirs) {
			int ni = i + x.first, nj = j + x.second;
			if (isgood(ni, nj) && board[ni][nj] == s[c])
				ans = ans || seek(board, ni, nj, l, c + 1, s);
		}
		board[i][j] = oc;
		return ans;
	}
	vector<string> a;
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		this->n = int(board.size());
		if (!n)return{};
		this->m = int(board.front().size());
		if (!m)return{};
		for (auto& x : words) {
			const int l = int(x.size());
			if (l > n*m)continue;
			if (!l)continue;
			bool ans = false;
			int i, j;
			for (i = 0; i < n; ++i) {
				for (j = 0; j < m; ++j) {
					if (board[i][j] == x.front()) {
						ans = seek(board, i, j, l, 1, x);
						if (ans)break;
					}
				}
				if (ans)break;
			}
			if (ans)a.push_back(x);
		}
		return a;
	}
};