class Solution {
private:
	vector<string> board;
	bool filled = false;
	bool issorted(vector<string>& a, int col, int rows, bool& strict) {
		char ch{ '#' };
		for (int i = 0; i < rows; ++i) {
			if (i == 0)ch = a[i][col];
			else {
				if (a[i][col] < ch)return false;
				if (a[i][col] == ch && strict)strict = false;
				ch = a[i][col];
			}
		}
		return true;
	}
	bool issorted2(vector<string>& a, int col, int rows, bool& strict) {
		string s = "", t = "";
		for (int i = 0; i < rows; ++i) {
			if (i == 0) {
				s = board[i] + string(1, a[i][col]);
				//cout<<s<<endl;
			}
			else {
				t = board[i] + string(1, a[i][col]);
				//cout<<t<<endl;
				if (s > t)return false;
				if (s == t && strict)strict = false;
				s = move(t);
			}
		}
		return true;
	}
public:
	int minDeletionSize(vector<string>& A) {
		const int n = int(A.size());
		if (n == 0)return 0;
		if (n == 1)return 0;
		const int m = int(A.front().size());
		if (!m)return 0;
		int res = 0;
		for (int j = 0; j < m; ++j) {
			if (!filled) {
				bool strict = true;
				if (issorted(A, j, n, strict)) {
					if (strict)break;
					else {
						filled = true;
						for (int i = 0; i < n; ++i) {
							board.emplace_back(string(1, A[i][j]));
						}
					}
				}
				else {
					++res;
				}
			}
			else {
				bool strict = true;
				if (issorted2(A, j, n, strict)) {
					if (strict)break;
					else {
						for (int i = 0; i < n; ++i)board[i].push_back(A[i][j]);
					}
				}
				else ++res;
			}
		}
		return res;
	}
};