struct node {
	vector<node*> a;
	int eow;
	node() : a(26, NULL) {
		eow = 0;
	}
} Node;

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		node* root = buildTrie(words), *temp;

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				string word = "";
				searchTrie(i, j, root, words, board, word);
			}
		}

		return out;
	}

	void searchTrie(int i, int j, node *root, vector<string>& words, vector<vector<char>>& board, string word) {
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#' || !root->a[board[i][j] - 'a']) return;

		char c = board[i][j];
		board[i][j] = '#';
		root = root->a[c - 'a'];
		word += c;

		if (root->eow && (s.find(word) == s.end())) {
			s.insert(word);
			out.push_back(word);
		}

		searchTrie(i - 1, j, root, words, board, word);
		searchTrie(i, j - 1, root, words, board, word);
		searchTrie(i + 1, j, root, words, board, word);
		searchTrie(i, j + 1, root, words, board, word);

		board[i][j] = c;

		return;
	}

	node* buildTrie(vector<string>& words) {
		node *root = new node(), *temp;

		for (int i = 0; i < words.size(); i++) {
			temp = root;
			for (int j = 0; j < words[i].size(); j++) {
				if (temp->a[words[i][j] - 'a'] == NULL) temp->a[words[i][j] - 'a'] = new node();
				temp = temp->a[words[i][j] - 'a'];
			}
			temp->eow = 1;
		}

		return root;
	}

private:
	unordered_set<string> s;
	vector<string> out;
};