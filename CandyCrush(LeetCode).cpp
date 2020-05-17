class Solution {
private:
	int n, m;
	void KillCol(vector<vector<int>>& board, int is, int js, int len) {
		int rs = is + len - 1;
		int left = is;
		int total = rs + 1;
		//cout<<is<<" "<<js<<" "<<rs<<" "<<left<<" "<<total<<endl;
		while (left > 0) {
			board[rs][js] = board[left - 1][js];
			--rs, --left, --total;
		}
		while (total > 0) {
			board[rs][js] = 0;
			--rs, --total;
		}
		return;
	}
	void KillRow(vector<vector<int>>& board, int is, int js, int len) {
		/*
		int cs=js+len-1;
		int left=js;
		int total=cs+1;
		while(left>0){
			board[is][cs]=board[is][left-1];
			--cs,--left,--total;
		}
		while(total>0){
			board[is][cs]=0;
			--cs,--total;
		}
		*/
		for (int j = js; j < js + len; ++j) {
			KillCol(board, is, j, 1);
		}
	}
public:
	vector<vector<int>> candyCrush(vector<vector<int>>& board) {
		this->n = static_cast<int>(board.size());
		if (!n)return board;
		this->m = static_cast<int>(board[0].size());
		if (!m)return board;
		while (1) {
			bool something = false;
			//seek in columns
			for (int j = 0; j < m; ++j) {
				int i = 0;
				int is = -1, js = j, c = 1;
				int x = board[i][j];
				if (!x)--c;
				++i;
				while (i < n) {
					int y = board[i][j];
					if (y == x) {
						if (y > 0) {
							++c;
							++i;
						}
						else if (y == 0) {
							c = 0;
							++i;
						}
					}
					else {
						if (c <= 1) {
							x = y;
							c = 1;
							if (!x)--c;
							++i;
							continue;
						}
						else {
							is = i - c;
							break;
						}
					}
				}
				if (is == -1 && c > 1) {
					is = i - c;
				}
				if (is != -1) {
					if (!something)something = true;
					KillCol(board, is, js, c);
					//if(j==2)return board;
					--j;
				}
			}
			//seek in rows;
			for (int i = 0; i < n; ++i) {
				int j = 0;
				int is = i, js = -1, c = 1;
				int x = board[i][j];
				if (!x)--c;
				++j;
				while (j < m) {
					int y = board[i][j];
					if (y == x) {
						if (y > 0) {
							++c, ++j;
						}
						else {
							c = 0;
							++j;
						}
					}
					else {
						if (c <= 1) {
							x = y;
							c = 1;
							if (!x)--c;
							++j;
							continue;
						}
						else {
							js = j - c;
							break;
						}
					}
				}
				if (js == -1 && c > 1) {
					js = j - c;
				}
				if (js != -1) {
					if (!something)something = true;
					KillRow(board, is, js, c);
					--i;
				}
			}
			if (!something)break;
		}
		return board;
	}
};