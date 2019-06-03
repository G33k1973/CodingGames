/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree Node
struct Node
{
	int data;
	Node* left, * right;
}; */
void printleft(Node *node)
{
	if (node == NULL)
		return;

	if (node->left)
	{
		cout << node->data << " ";
		printleft(node->left);
	}
	else if (node->right)
	{
		cout << node->data << " ";
		printleft(node->right);
	}

}
void printright(Node *node)
{
	if (node == NULL)
		return;

	if (node->right)
	{

		printright(node->right);
		cout << node->data << " ";
	}
	else if (node->left)
	{

		printright(node->left);
		cout << node->data << " ";
	}

}
void printleaves(Node *node)
{
	if (node)
	{
		printleaves(node->left);
		if (node->left == NULL && node->right == NULL)
		{
			cout << node->data << " ";
		}
		printleaves(node->right);
	}
}
void printBoundary(Node *root)
{

	if (root)
	{
		cout << root->data << " ";
		printleft(root->left);
		printleaves(root);
		printright(root->right);
	}
}