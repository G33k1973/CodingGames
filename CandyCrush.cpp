class Solution {
protected:
	int n, m;
	bool IsGood(int& i, int j, int val, vector<vector<int>>& board) {
		int c = 1;
		while (i < n&&board[i][j] == val) {
			++i, ++c;
		}
		--i;
		return c >= 3;
	}
	bool IsGoodHorizontal(int i, int& j, int val, vector<vector<int>>& board) {
		int c = 1;
		while (j < m&&board[i][j] == val) {
			++j, ++c;
		}
		--j;
		return c >= 3;
	}
public:
	vector<vector<int>> candyCrush(vector<vector<int>>& board) {
		this->n = (int)board.size();
		this->m = (int)board[0].size();
		do {
			int i, j;
			int crushes(0);
			for (i = 0; i < n; ++i) {
				for (j = 0; j < m; ++j) {
					if (board[i][j] == 0)continue;
					if (i <= (n - 3)) {
						//check vertical
						int k = i + 1;
						if (IsGood(k, j, board[i][j], board)) {
							++crushes;
							int bottom = i - 1;
							int distance = k - i + 1;
							int b = i;
							int down = k;
							int c = 0;
							while (c < distance&&bottom >= 0) {
								board[down--][j] = board[bottom--][j];
								++c;
							}
							if (distance >= b) {
								int v = down - b;
								while (v >= 0) {
									board[v--][j] = 0;
								}
							}
							else {
								while (bottom >= 0) {
									board[down--][j] = board[bottom--][j];
								}
								bottom = k - b;
								while (bottom >= 0) {
									board[bottom--][j] = 0;
								}
							}
						}
					}
					if (j <= (m - 3)) {
						//check horizontal
						int k = j + 1;
						if (IsGoodHorizontal(i, k, board[i][j], board)) {
							++crushes;
							int bottom = j - 1;
							int distance = k - j + 1;
							int b = j;
							int down = k;
							int c = 0;
							while (c < distance&&bottom >= 0) {
								board[i][down--] = board[i][bottom--];
								++c;
							}
							if (distance >= b) {
								int v = down - b;
								while (v >= 0) {
									board[i][v--] = 0;
								}
							}
							else {
								while (bottom >= 0) {
									board[i][down--] = board[i][bottom--];
								}
								bottom = k - b;
								while (bottom >= 0) {
									board[i][bottom--] = 0;
								}
							}
						}
					}
				}
			}
			if (!crushes)break;
		} while (true);
		return board;
	}
};