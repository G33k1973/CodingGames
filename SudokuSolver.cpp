#define N 9
#define pb push_back
typedef std::pair<int, int> ip;
#define mp make_pair
class Solution {
protected:
	unordered_set<int> rows[N], cols[N];
	vector<vector<char>> solution;
	bool isvalid_1(ip& curr, int val, vector<vector<char>>& board) {
		int i = curr.first, j = curr.second;
		if (rows[i].count(val) > 0)return 0;
		if (cols[j].count(val) > 0)return 0;
		int rs = i / 3;
		rs *= 3;
		int re = rs + 2;
		int cs = j / 3;
		cs *= 3;
		int ce = cs + 2;
		int u, v;
		int h[10] = { 0 };
		h[val]++;
		//cout<<rs<<" "<<re<<" "<<cs<<" "<<ce<<endl;
		for (u = rs; u <= re; ++u) {
			for (v = cs; v <= ce; ++v) {
				if (board[u][v] == '.')continue;
				int y = board[u][v] - '0';
				if (h[y] > 0)return 0;
				++h[y];
			}
		}
		return 1;
	}
	bool isvalid_2(vector<vector<char>>& board) {
		int i, j;
		for (i = 0; i < 3; ++i) {
			for (j = 0; j < 3; ++j) {
				int re = (i + 1) * 3, rs = i * 3;
				int ce = (j + 1) * 3, cs = j * 3;
				int h[10] = { 0 };
				for (int u = rs; u < re; ++u) {
					for (int v = cs; v < ce; ++v) {
						int y = board[u][v] - '0';
						if (h[y] > 0)return 0;
						++h[y];
					}
				}
			}
		}
		return true;
	}
	bool solve(vector<vector<char>>& board, int cum, const std::vector<ip>& arr) {
		if (cum < 0) {
			solution = board;
			return true;
		}
		bool ans = false;
		for (int i = 1; i < 10; ++i) {
			ip current = arr.at(cum);
			if (isvalid_1(current, i, board)) {
				board[current.first][current.second] = '0' + i;
				rows[current.first].insert(i);
				cols[current.second].insert(i);
				ans = ans || solve(board, cum - 1, arr);
				if (ans == false) {
					rows[current.first].erase(i);
					cols[current.second].erase(i);
					board[current.first][current.second] = '.';
				}
				else return true;
			}
		}
		return ans;
	}
public:
	void solveSudoku(vector<vector<char>>& board) {
		vector<ip> pts;
		int i, j;
		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				char x = board[i][j];
				if (x == '.')pts.pb(mp(i, j));
				else {
					int y = x - '0';
					rows[i].insert(y);
					cols[j].insert(y);
				}
			}
		}
		solve(board, (int)pts.size() - 1, pts);
		board = move(solution);
	}
};