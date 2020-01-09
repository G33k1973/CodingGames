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
protected:
	int n, m;
	int Check(const vector<vector<int>>& grid, int iul, int jul, int idr, int jdr) {
		int res = -1;
		int c = 0;
		for (int i = iul; i <= idr; ++i) {
			for (int j = jul; j <= jdr; ++j) {
				if (c == 0) {
					++c;
					res = grid[i][j];
				}
				else {
					if (grid[i][j] != res)return -1;
				}
			}
		}
		return res;
	}
	Node * build(const vector<vector<int>>& grid, int iul, int jul, int idr, int jdr) {
		if (iul > idr || jul > jdr)return NULL;
		Node * temp = new Node();
		int color = Check(grid, iul, jul, idr, jdr);
		if (color != -1) {
			temp->val = static_cast<bool>(color);
			temp->isLeaf = true;
			temp->topLeft = temp->topRight = temp->bottomLeft = temp->bottomRight = NULL;
			return temp;
		}
		temp->val = false;
		temp->isLeaf = false;
		temp->topLeft = build(grid, iul, jul, iul + (idr - iul) / 2, jul + (jdr - jul) / 2);
		temp->topRight = build(grid, iul, jul + (jdr - jul) / 2 + 1, iul + (idr - iul) / 2, jdr);
		temp->bottomLeft = build(grid, iul + (idr - iul) / 2 + 1, jul, idr, jul + (jdr - jul) / 2);
		temp->bottomRight = build(grid, iul + (idr - iul) / 2 + 1, jul + (jdr - jul) / 2 + 1, idr, jdr);
		return temp;
	}
public:
	Node* construct(vector<vector<int>>& grid) {
		n = static_cast<int>(grid.size());
		if (n == 0)return 0;
		m = static_cast<int>(grid.front().size());
		if (m == 0)return 0;
		return build(grid, 0, 0, n - 1, m - 1);
	}
};