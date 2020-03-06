class Solution {
public:
	bool isAnagram(string s, string t) {
		int n = int(s.size());
		int m = int(t.size());
		if (n != m)return false;
		if (n == 0)return true;
		int CHARS(255);
		vector<int> h(CHARS + 1, 0), h2(CHARS + 1, 0);
		for (char & x : s)++h[x];
		for (char & x : t)++h2[x];
		return (h == h2);
	}
};
using ll = long long int;
#define sc static_cast<ll>
class Solution {
public:
	ll titleToNumber(string s) {
		int l = int(s.length());
		int i = 0;
		ll res = 0LL;
		while (i < l) {
			int j = s[i] - 'A';
			++j;
			res = res * 26LL + sc(j);
			++i;
		}
		return res;
	}
};

#define pb push_back
class Solution {
private:
	int n, m;
	bool dfs(vector<vector<char>>& board, int i, int j, string& s, int l, int c) {
		if (c == l - 1)return true;
		char x = board[i][j];
		board[i][j] = '#';
		static int X[4] = { 1,-1,0,0 };
		static int Y[4] = { 0,0,-1,+1 };
		bool ans = false;
		for (int k = 0; k < 4; ++k) {
			int ni = i + X[k];
			int nj = j + Y[k];
			if (ni >= 0 && ni < n&&nj >= 0 && nj < m&&board[ni][nj] == s[c + 1]) {
				ans = ans || dfs(board, ni, nj, s, l, c + 1);
			}
		}
		board[i][j] = x;
		return ans;
	}
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (word.empty())return true;
		n = int(board.size());
		if (n == 0)return false;
		m = int(board.front().size());
		if (m == 0)return false;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (board[i][j] == word.front()) {
					bool ans = dfs(board, i, j, word, int(word.size()), 0);
					if (ans)return 1;
				}
			}
		}
		return false;
	}
};