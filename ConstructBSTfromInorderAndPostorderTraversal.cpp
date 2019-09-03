/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef TreeNode Node;
class Solution {
protected:
	Node * newNode(int x) {
		Node * current = new Node(x);
		return current;
	}
	/* Recursive function to construct binary of size n
	   from  Inorder traversal in[] and Postorder traversal
	   post[].  Initial values of inStrt and inEnd should
	   be 0 and n -1.  The function doesn't do any error
	   checking for cases where inorder and postorder
	   do not form a tree */
	Node* buildUtil(vector<int>& in, vector<int>& post, int inStrt,
		int inEnd, int* pIndex)
	{
		// Base case 
		if (inStrt > inEnd)
			return NULL;

		/* Pick current node from Postorder traversal using
		   postIndex and decrement postIndex */
		Node* node = newNode(post[*pIndex]);
		(*pIndex)--;

		/* If this node has no children then return */
		if (inStrt == inEnd)
			return node;

		/* Else find the index of this node in Inorder
		   traversal */
		int iIndex = search(in, inStrt, inEnd, node->val);

		/* Using index in Inorder traversal, construct left and
		   right subtress */
		node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex);
		node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex);

		return node;
	}

	// This function mainly initializes index of root 
	// and calls buildUtil() 
	Node* buildTree(vector<int>& in, vector<int>& post, int n)
	{
		int pIndex = n - 1;
		return buildUtil(in, post, 0, n - 1, &pIndex);
	}

	/* Function to find index of value in arr[start...end]
	   The function assumes that value is postsent in in[] */
	int search(vector<int>& arr, int strt, int end, int value)
	{
		int i;
		for (i = strt; i <= end; i++) {
			if (arr[i] == value)
				break;
		}
		return i;
	}
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int n = static_cast<int>(inorder.size());
		if (n == 0)return 0;
		if (n == 1)return new TreeNode(inorder[0]);
		return buildTree(inorder, postorder, n);
	}
};