/*
// Definition for a QuadTree node.
class Node {
public:
	bool val;
	bool isLeaf;
	Node* topLeft;
	Node* topRight;
	Node* bottomLeft;
	Node* bottomRight;

	Node() {}

	Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = _topLeft;
		topRight = _topRight;
		bottomLeft = _bottomLeft;
		bottomRight = _bottomRight;
	}
};
*/
class Solution {
private:
	int n;
	int GetVal(const vector<vector<int>>& grid, int iul, int jul, int ibr, int jbr) {
		int val(-1);
		int i, j;
		for (i = iul; i <= ibr; ++i) {
			for (j = jul; j <= jbr; ++j) {
				if (val == -1) {
					val = grid[i][j];
				}
				else if (val != grid[i][j])return -1;
			}
		}
		return val;
	}
	Node * build(const vector<vector<int>>& grid, int iul, int jul, int ibr, int jbr) {
		if (iul > ibr || jul > jbr)return NULL;
		Node * root = new Node();
		int x = this->GetVal(grid, iul, jul, ibr, jbr);
		if (x != -1) {
			root->val = bool(x);
			root->isLeaf = true;
			root->topLeft = root->topRight = root->bottomLeft = root->bottomRight = NULL;
			return root;
		}
		root->val = false;
		root->isLeaf = false;
		root->topLeft = build(grid, iul, jul, iul + (ibr - iul) / 2, jul + (jbr - jul) / 2);
		root->topRight = build(grid, iul, jul + (jbr - jul) / 2 + 1, iul + (ibr - iul) / 2, jbr);
		root->bottomLeft = build(grid, iul + (ibr - iul) / 2 + 1, jul, ibr, jul + (jbr - jul) / 2);
		root->bottomRight = build(grid, iul + (ibr - iul) / 2 + 1, jul + (jbr - jul) / 2 + 1, ibr, jbr);
		return root;
	}
public:
	Node* construct(vector<vector<int>>& grid) {
		int n = int(grid.size());
		if (n == 0)return 0;
		return build(grid, 0, 0, n - 1, n - 1);
	}
};