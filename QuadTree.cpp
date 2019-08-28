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
	bool IsGood(vector<vector<int>>& grid, int inw, int jnw, int ise, int jse) {
		int i, j;
		int c = 0;
		bool pos = false;
		for (i = inw; i <= ise; ++i) {
			for (j = jnw; j <= jse; ++j) {
				if (c == 0) {
					c = !c;
					pos = grid[i][j];
				}
				else {
					if (grid[i][j] && !pos)return false;
					if (!grid[i][j] && pos)return false;
				}
			}
		}
		return true;
	}
	Node * build(vector<vector<int>>& grid, int inw, int jnw, int ise, int jse) {
		if (inw == ise && jnw == jse) {
			Node * temp = new Node(grid[inw][jnw], true, 0, 0, 0, 0);
			return temp;
		}
		if (IsGood(grid, inw, jnw, ise, jse)) {
			Node * temp = new Node(grid[inw][jnw], true, 0, 0, 0, 0);
			return temp;
		}
		Node * temp = new Node();
		temp->isLeaf = false;
		temp->val = false;
		temp->topLeft = build(grid, inw, jnw, (inw + ise) / 2, (jnw + jse) / 2);
		temp->topRight = build(grid, inw, (jnw + jse) / 2 + 1, (inw + ise) / 2, jse);
		temp->bottomLeft = build(grid, (inw + ise) / 2 + 1, jnw, ise, (jnw + jse) / 2);
		temp->bottomRight = build(grid, (inw + ise) / 2 + 1, (jnw + jse) / 2 + 1, ise, jse);
		return temp;
	}
public:
	Node* construct(vector<vector<int>>& grid) {
		int n = (int)grid.size();
		if (n == 0)return 0;
		int m = (int)grid[0].size();
		if (m == 0)return 0;
		Node * root = build(grid, 0, 0, n - 1, n - 1);
		return root;
	}
};