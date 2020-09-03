/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
protected:
	TreeNode * r;
	map<int, vector<TreeNode*>> rbt;
	int next_ = 0;
	std::map<int, vector<TreeNode*>>::iterator it;
private:
	void dfs(TreeNode* root, int h) {
		if (!root)return;
		rbt[h].push_back(root);
		dfs(root->left, h + 1);
		dfs(root->right, h + 1);
	}
	bool isfilled(int level) {
		return int(it->second.size() == (1 << level));
	}
public:
	CBTInserter(TreeNode* root) {
		this->r = root;
		dfs(root, 0);
		auto ptr = begin(rbt);
		while (ptr != end(rbt)) {
			int m = int(ptr->second.size());
			if (m != (1 << next_))break;
			++ptr;
			++next_;
		}
		it = ptr;
	}

	int insert(int v) {
		//cout<<next_<<endl;
		if (it == end(rbt)) {
			TreeNode* temp = prev(it, 1)->second.front();
			temp->left = new TreeNode(v);
			rbt[next_].push_back(temp->left);
			it = prev(rbt.end(), 1);
			return temp->val;
		}
		//check that level is not filled
		if (isfilled(next_)) {
			++next_;
			TreeNode* temp = it->second.front();
			temp->left = new TreeNode(v);
			rbt[next_].push_back(temp->left);
			it = prev(rbt.end(), 1);
			return temp->val;
		}
		int m = int(it->second.size());
		TreeNode * parent = prev(it, 1)->second.at((m) / 2);
		if ((m + 1) & 1) {
			parent->left = new TreeNode(v);
			it->second.push_back(parent->left);
		}
		else {
			parent->right = new TreeNode(v);
			it->second.push_back(parent->right);
		}
		return parent->val;
	}

	TreeNode* get_root() {
		return r;
	}
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */