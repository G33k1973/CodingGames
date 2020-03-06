struct bt {
	bt * left, *right;
	int val;
	bt() {

	}
	bt(int x) :val(x) {
		left = right = NULL;
	}
};
int findIndex(vector<int>& inorder, int n, int val) {
	int i;
	for (i = 0; i < n; ++i) {
		if (inorder[i] == val)return i;
	}
	return INT_MAX;
}
bool possible = true;
bt * buildTree(vector<int>& preorder, vector<int>& inorder, int n, int& i, int low, int high) {
	if (low > high)return NULL;
	if (i == n)return NULL;
	int rootval = preorder.at(i);
	bt * root = new bt(rootval);
	++i;
	int index = findIndex(inorder, n, rootval);
	if (index == INT_MAX) {
		possible = false;
		return NULL;
	}
	if (low == high)return root;
	root->left = buildTree(preorder, inorder, n, i, low, index - 1);
	if (possible == false)return NULL;
	root->right = buildTree(preorder, inorder, n, i, index + 1, high);
	if (possible == false)return NULL;
	return root;
}
void postorder(vector<int>& arr, bt* root) {
	if (root != 0) {
		postorder(arr, root->left);
		postorder(arr, root->right);
		arr.push_back(root->val);
	}
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
	possible = true;
	int n = int(A.size());
	int m = int(B.size());
	int o = int(C.size());
	if (n != m || n != o || m != o)return false;
	int i = 0;
	bt * root = buildTree(A, B, n, i, 0, n - 1);
	if (i != n)return 0;
	vector<int> temp;
	postorder(temp, root);
	return temp == C;
}
