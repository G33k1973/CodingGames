/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef TreeNode node;
#define pb push_back
class Solution {
public:
	void printLeaves(node* root, vector<int>& a)
	{
		if (root == NULL)
			return;

		printLeaves(root->left, a);

		// Print it if it is a leaf node 
		if (!(root->left) && !(root->right))
			a.pb(root->val);

		printLeaves(root->right, a);
	}

	// A function to print all left boundary nodes, except a leaf node. 
	// Print the nodes in TOP DOWN manner 
	void printBoundaryLeft(node* root, vector<int>& a)
	{
		if (root == NULL)
			return;

		if (root->left) {

			// to ensure top down order, print the node 
			// before calling itself for left subtree 
			a.pb(root->val);
			printBoundaryLeft(root->left, a);
		}
		else if (root->right) {
			a.pb(root->val);
			printBoundaryLeft(root->right, a);
		}
		// do nothing if it is a leaf node, this way we avoid 
		// duplicates in output 
	}

	// A function to print all right boundary nodes, except a leaf node 
	// Print the nodes in BOTTOM UP manner 
	void printBoundaryRight(node* root, vector<int>& a)
	{
		if (root == NULL)
			return;

		if (root->right) {
			// to ensure bottom up order, first call for right 
			// subtree, then print this node 
			printBoundaryRight(root->right, a);
			a.pb(root->val);
		}
		else if (root->left) {
			printBoundaryRight(root->left, a);
			a.pb(root->val);
		}
		// do nothing if it is a leaf node, this way we avoid 
		// duplicates in output 
	}

	// A function to do boundary traversal of a given binary tree 
	void printBoundary(node* root, vector<int>& a)
	{
		if (root == NULL)
			return;

		a.pb(root->val);

		// Print the left boundary in top-down manner. 
		printBoundaryLeft(root->left, a);

		// Print all leaf nodes 
		printLeaves(root->left, a);
		printLeaves(root->right, a);

		// Print the right boundary in bottom-up manner 
		printBoundaryRight(root->right, a);
	}
	vector<int> boundaryOfBinaryTree(TreeNode* root) {
		vector<int> res;
		if (root == 0)return res;
		this->printBoundary(root, res);
		return res;
	}
};