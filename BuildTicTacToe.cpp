class TicTacToe {
protected:
	vector<string> grid;
	unordered_map<int, char> h;
	int c;
	int n;
	bool IsWinner(char x) {
		int i, j;
		int r[n] = { 0 };
		int c[n] = { 0 };
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				if (grid[i][j] == x) {
					++r[i], ++c[j];
					if (r[i] == n)return 1;
					if (c[j] == n)return 1;
				}
			}
		}
		i = 0, j = 0;
		int tot = 0;
		while (i < n&&j < n) {
			if (grid[i++][j++] == x)++tot;
			else break;
		}
		if (tot == n)return 1;
		i = 0, j = n - 1;
		tot = 0;
		while (i < n&&j >= 0) {
			if (grid[i++][j--] == x)++tot;
			else break;
		}
		if (tot == n)return 1;
		return 0;
	}
public:
	/** Initialize your data structure here. */
	TicTacToe(int n) {
		this->c = -1;
		this->grid.assign(n, std::string(n, '-'));
		h[1] = 'X';
		h[2] = 'O';
		this->n = n;
	}

	/** Player {player} makes a move at ({row}, {col}).
		@param row The row of the board.
		@param col The column of the board.
		@param player The player, can be either 1 or 2.
		@return The current winning condition, can be either:
				0: No one wins.
				1: Player 1 wins.
				2: Player 2 wins. */
	int move(int row, int col, int player) {
		int move_ = player;
		char x = h[move_];
		grid[row][col] = x;
		if (this->IsWinner(x))return move_;
		return 0;
	}
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */