class TicTacToe {
protected:
	int n;
	struct MyTTP {
		vector<int> r, c;
		int n;
		int diag, adiag;
		MyTTP() {
			diag = adiag = 0;
		}
		MyTTP(int n) {
			this->n = n;
			r.assign(n, 0);
			c.assign(n, 0);
			diag = 0;
			adiag = 0;
		}
		bool CheckWin() {
			for (int i = 0; i < n; ++i) {
				if (r[i] == n || c[i] == n)return true;
			}
			if (diag == n || adiag == n)return true;
			return false;
		}
		MyTTP& Update(int row, int col) {
			++r[row];
			++c[col];
			if (TicTacToe::isondiagonal(row, col, n))++diag;
			if (TicTacToe::isonantidiagonal(row, col, n))++adiag;
			return *this;
		}
	};
	static bool isondiagonal(int i, int j, int n) {
		return ((i == j));
	}
	static bool isonantidiagonal(int i, int j, int n) {
		return (i == (n - 1 - j));
	}
	vector<struct MyTTP> players;
public:
	/** Initialize your data structure here. */
	TicTacToe(int n) {
		this->n = n;
		struct MyTTP temp(n);
		players.push_back(temp);
		players.push_back(temp);
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
		assert(player >= 1 && player <= 2);
		int i = player - 1;
		players.operator[](i).Update(row, col);
		if (players[i].CheckWin())return player;
		return 0;
	}
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */