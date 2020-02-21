int Solution::solve(TreeNode* root)
{
	// The size of minimum vertex cover is zero if tree is empty or there 
	// is only one node 
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 0;

	// Calculate size of vertex cover when root is part of it 
	int size_incl = 1 + solve(root->left) + solve(root->right);

	// Calculate size of vertex cover when root is not part of it 
	int size_excl = 0;
	if (root->left)
		size_excl += 1 + solve(root->left->left) + solve(root->left->right);
	if (root->right)
		size_excl += 1 + solve(root->right->left) + solve(root->right->right);

	// Return the minimum of two sizes 
	return min(size_incl, size_excl);
}