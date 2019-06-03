struct Node {
	int data;
	Node * left, *right;
	Node() {
		left = right = 0;
	}
	Node(int x) {
		this->data = x;
		this->left = this->right = NULL;
	}
};
int Search(int in[], int l, int h, int data) {
	int k;
	for (int i = l; i <= h; ++i) {
		if (in[i] == data)return i;
	}
	return k;
}
int preindex = 0;
Node * BuildTree(int in[], int pre[], int l, int h) {
	if (l > h)return NULL;
	Node * root = new Node(pre[preindex++]);
	if (l == h)return root;
	int _index_ = Search(in, l, h, pre[preindex - 1]);
	root->left = BuildTree(in, pre, l, _index_ - 1);
	root->right = BuildTree(in, pre, _index_ + 1, h);
	return root;
}
void PostOrder(Node * root) {
	if (root == 0)return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->data << " ";
}
void printPostOrder(int in[], int pre[], int n)
{
	//Your code here
	preindex = 0;
	Node * root = BuildTree(in, pre, 0, n - 1);
	PostOrder(root);
}