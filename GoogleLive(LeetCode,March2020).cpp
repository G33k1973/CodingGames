#define pb push_back
class Solution {
public:
	string reverseWords(string s) {
		int l = int(s.size());
		s += " ";
		++l;
		string sub("");
		string res("");
		int i = 0;
		while (i < l) {
			if (isspace(s[i])) {
				if (sub.size() > 0) {
					int n = int(sub.length());
					int j = n - 1;
					while (j >= 0)res.pb(sub[j--]);
					sub.clear();
				}
				res += " ";
			}
			else
				sub.pb(s[i]);
			++i;
		}
		res.pop_back();
		return res;
	}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define pb push_back
class Solution {
private:
	vector<ListNode*> arr;
	int n;
public:
	ListNode* swapPairs(ListNode* head) {
		n = 0;
		if (head == 0)return head;
		ListNode * current = head;
		while (current) {
			++n;
			arr.pb(current);
			current = current->next;
		}
		if (n == 1)return head;
		int i = 0;
		head = 0;
		while (i < n) {
			if (i == 0) {
				head = arr[i + 1];
				head->next = arr[i];
				arr[i]->next = 0;
			}
			else {
				if (i + 1 >= n) {
					arr[i - 2]->next = arr[i];
					arr[i]->next = NULL;
					break;
				}
				arr[i - 2]->next = arr[i + 1];
				arr[i + 1]->next = arr[i];
				arr[i]->next = 0;
			}
			i += 2;
		}
		return head;
	}
};

class Solution {
private:
	int n, m;
	bool isvalid(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m);
	}
	int X[4] = { 1,-1,0,0 };
	int Y[4] = { 0,0,1,-1 };
	bool dfs(vector<vector<char>>& grid, int i, int j, string& s, int l, int c) {
		if (c == l - 1)return true;
		char x = grid[i][j];
		grid[i][j] = '#';
		bool ans = false;
		for (int k = 0; k < 4; ++k) {
			int ni = i + X[k];
			int nj = j + Y[k];
			if (isvalid(ni, nj) && grid[ni][nj] != '#'&&grid[ni][nj] == s[c + 1]) {
				ans = ans || dfs(grid, ni, nj, s, l, c + 1);
			}
		}
		grid[i][j] = x;
		return ans;
	}
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		n = int(board.size());
		if (n == 0)return vector<string>{};
		m = int(board.front().size());
		if (m == 0)return vector<string>{};
		int i, j;
		vector<string> arr;
		for (string& x : words) {
			if (x.empty())continue;
			bool ans = false;
			for (i = 0; i < n; ++i) {
				for (j = 0; j < m; ++j) {
					if (board[i][j] == x[0]) {
						ans = ans || dfs(board, i, j, x, int(x.length()), 0);
						if (ans)break;
					}
				}
				if (ans)break;
			}
			if (ans)arr.push_back(x);
		}
		return arr;
	}
};