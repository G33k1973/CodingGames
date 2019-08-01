class Solution {
protected:
	bool isSafe(int r, int c, vector<string>& board) {
		for (int j = 0; j < c; ++j) {
			if (board[r][j] == 'Q')return 0;
		}
		for (int i = r, j = c; i >= 0 && j >= 0; --i, --j) {
			if (board[i][j] == 'Q')return 0;
		}
		for (int i = r, j = c; i < (int)board.size() && j >= 0; ++i, --j) {
			if (board[i][j] == 'Q')return 0;
		}
		return 1;
	}
	bool solveUtil(int c, int C, vector<string>& board, vector<vector<string>>& res) {
		if (c == C) {
			res.push_back(board);
			return true;
		}
		bool ans = false;
		for (int i = 0; i < C; ++i) {
			if (isSafe(i, c, board)) {
				board[i][c] = 'Q';
				solveUtil(c + 1, C, board, res);
				board[i][c] = '.';
			}
		}
		return ans;
	}
	void solve(int n, vector<vector<string>>& res) {
		if (n == 0)return;
		vector<string> board(n, string(n, '.'));
		solveUtil(0, n, board, res);
		return;
	}
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		solve(n, res);
		return res;
	}
};