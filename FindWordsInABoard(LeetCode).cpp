#define pb push_back
#define mp make_pair
class Solution {
private:
	int n, m;
	vector<pair<int, int>> DIRS{ {1,0},{-1,0},{0,-1},{0,+1} };
	bool isvalid(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m);
	}
	bool ispossible(vector<vector<char>>& board, int i, int j, int c, int l, string& s) {
		if (c == l)return true;
		char oc = board[i][j];
		board[i][j] = '#';
		bool ans = false;
		for (int k = 0; k < 4; ++k) {
			int ni = i + DIRS[k].first;
			int nj = j + DIRS[k].second;
			if (isvalid(ni, nj) && board[ni][nj] == s[c])ans = ans || ispossible(board, ni, nj, c + 1, l, s);
		}
		board[i][j] = oc;
		return ans;
	}
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		n = static_cast<int>(board.size());
		if (n == 0)return vector<string>{};
		m = static_cast<int>(board.front().size());
		if (m == 0)return vector<string>{};
		int maxlen = n * m;
		vector<string> r;
		int i = 0, j = 0;
		for (string& x : words) {
			int l = static_cast<int>(x.length());
			if (l == 0 || l > maxlen)continue;
			bool ans = false;
			for (i = 0; i < n; ++i) {
				for (j = 0; j < m; ++j) {
					if (board[i][j] == x.front()) {
						board[i][j] = '#';
						ans = ans || ispossible(board, i, j, 1, l, x);
						board[i][j] = x.operator[](0);
						if (ans == true)break;
					}
				}
				if (ans)break;
			}
			if (ans)r.push_back(x);
		}
		return r;
	}
};