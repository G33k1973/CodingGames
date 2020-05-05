/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};
*/
#define pb push_back
class Codec {
protected:
	string nochildren = "#";
	string childrensize = "SIZE";
	string stopsize = "#";
	void dfs(Node * root, string& sroot) {
		if (root == 0)return;
		int x = root->val;
		string val = to_string(x);
		sroot += val;
		int sz = int(root->children.size());
		if (sz == 0) {
			sroot += nochildren;
			return;
		}
		sroot += childrensize;
		val = to_string(sz);
		sroot += val;
		sroot += stopsize;
		for (Node* x : root->children) {
			dfs(x, sroot);
		}
		return;
	}
	Node * build(string& data, int l, int& i) {
		if (i >= l)return NULL;
		int j(i);
		int val = 0;
		while (j < l&&isdigit(data[j])) {
			val = val * 10 + (data[j] - '0');
			++j;
		}
		//cout<<val<<endl;
		Node * root = new Node(val);
		if (j == l)return root;
		if (data[j] == '#') {
			i = ++j;
			return root;
		}
		j += 4;
		val = 0;
		while (j < l&&isdigit(data[j])) {
			val = val * 10 + (data[j] - '0');
			++j;
		}
		i = ++j;
		//cout<<val<<endl;
		for (int k = 0; k < val; ++k) {
			Node * next = build(data, l, i);
			root->children.push_back(next);
		}
		return root;
	}
public:
	// Encodes a tree to a single string.
	string serialize(Node* root) {
		string r = "";
		dfs(root, r);
		//cout<<r<<endl;
		return r;
	}

	// Decodes your encoded data to tree.
	Node* deserialize(string data) {
		if (data.empty())return nullptr;
		int i = 0, l = int(data.size());
		return build(data, l, i);
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));