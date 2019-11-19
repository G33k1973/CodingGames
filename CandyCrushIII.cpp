class Solution {
public:
	vector<vector<int>> candyCrush(vector<vector<int>>& board) {
		if (board.size() == 0 || board[0].size() == 0) return board;
		int r_size = board.size(), c_size = board[0].size();
		bool crush_flag = true; //determine if the board is stable
		while (crush_flag) {
			crush_flag = false;
			for (int i = 0; i < r_size; i++) { // O(r * c) time
				for (int j = 0; j < c_size; j++) {
					if (!board[i][j]) continue; // skip the 0s
					eliminate(i, j, board, crush_flag);
				}
			}

			// fall
			for (int j = 0; j < c_size; j++) { // O(r * c) time
				int zero_num = 0; // count how many zeros so far in a col
				for (int i = r_size - 1; i >= 0; i--) {
					if (board[i][j] < 0) zero_num++;
					else board[i + zero_num][j] = board[i][j]; // drop the number by zero_num below it
					if (i == 0) {
						for (int k = 0; k < zero_num; k++) board[k][j] = 0; // fill the top with zeros
					}
				}
			}
		}

		return board;

	}
private:
	void eliminate(int i, int j, vector<vector<int>>& board, bool &crush_flag) { // flip the sign of the number if it needs to be crushed
		int r_size = board.size(), c_size = board[0].size();
		if (j >= 1 && j <= c_size - 2 && abs(board[i][j]) == abs(board[i][j - 1]) && abs(board[i][j]) == abs(board[i][j + 1])) {
			crush_flag = true;
			if (board[i][j] > 0) board[i][j] = -board[i][j];
			if (board[i][j - 1] > 0) board[i][j - 1] = -board[i][j - 1];
			if (board[i][j + 1] > 0) board[i][j + 1] = -board[i][j + 1];
		}
		if (i >= 1 && i <= r_size - 2 && abs(board[i][j]) == abs(board[i - 1][j]) && abs(board[i][j]) == abs(board[i + 1][j])) {
			crush_flag = true;
			if (board[i][j] > 0) board[i][j] = -board[i][j];
			if (board[i - 1][j] > 0) board[i - 1][j] = -board[i - 1][j];
			if (board[i + 1][j] > 0) board[i + 1][j] = -board[i + 1][j];
		}
	}
};