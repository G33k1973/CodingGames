#define ALPHABET 26
class Trie {
protected:
	struct mytrie {
		mytrie* children[ALPHABET];
		bool endword;
		mytrie() {
			for (int i = 0; i < ALPHABET; ++i)
				children[i] = nullptr;
			this->endword = false;
		}
	};
	mytrie * root;
	struct mytrie* GetNode() {
		return new mytrie();
	}
public:
	/** Initialize your data structure here. */
	Trie() {
		root = GetNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		mytrie * crawler{ root };
		for (char& x : word) {
			int y = x - 'a';
			if (crawler->children[y] == nullptr) {
				crawler->children[y] = GetNode();
			}
			crawler = crawler->children[y];
		}
		crawler->endword = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		mytrie * crawler{ root };
		for (char& x : word) {
			int y = x - 'a';
			if (crawler->children[y] == nullptr)return false;
			crawler = crawler->children[y];
		}
		return crawler != nullptr && crawler->endword == true;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		mytrie * crawler{ root };
		for (char& x : prefix) {
			int y = x - 'a';
			if (crawler->children[y] == nullptr)return false;
			crawler = crawler->children[y];
		}
		return crawler != nullptr;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */