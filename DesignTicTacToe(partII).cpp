unordered_map<int, char> h{ {1,'X'},{2,'O'} };
class TicTacToe {
protected:
	int n;
	vector<vector<char>> grid;
	vector<int> rowsPlayer1, rowsPlayer2, colsPlayer1, colsPlayer2;
	int diagPlayer1, diagPlayer2,
		antidiagPlayer1, antidiagPlayer2;
public:
	/** Initialize your data structure here. */
	TicTacToe(int n) {
		this->n = n;
		if (n) {
			grid.assign(n, vector<char>(n, '.'));
			rowsPlayer1.assign(n, 0);
			rowsPlayer2.assign(n, 0);
			colsPlayer1.assign(n, 0);
			colsPlayer2.assign(n, 0);
			diagPlayer1 = diagPlayer2 = antidiagPlayer1 = antidiagPlayer2 = 0;
		}
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
		char x = h[player];
		grid[row][col] = x;
		if (row == col) {
			if (player == 1) {
				++diagPlayer1;
				if (diagPlayer1 == n)return player;
			}
			else {
				++diagPlayer2;
				if (diagPlayer2 == n)return player;
			}
		}
		if ((n - col - 1) == row) {
			if (player == 1) {
				++antidiagPlayer1;
				if (antidiagPlayer1 == n)return player;
			}
			else if (player == 2) {
				++antidiagPlayer2;
				if (antidiagPlayer2 == n)return player;
			}
		}
		if (player == 1) {
			++rowsPlayer1[row];
			if (rowsPlayer1[row] == n)return player;
			++colsPlayer1[col];
			if (colsPlayer1[col] == n)return player;
		}
		if (player == 2) {
			++rowsPlayer2[row];
			if (rowsPlayer2[row] == n)return player;
			++colsPlayer2[col];
			if (colsPlayer2[col] == n)return player;
		}
		return 0;
	}
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */