
/*structure of the node of the linked list is as
struct Node
{
	int data;
	Node* right, *down;
};*/
// n is the size of the matrix
// function must return the pointer to the first element 
// of the in linked list i.e. that should be the element at arr[0][0]
Node* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
	// code here
	Node * h = NULL;
	Node * c = NULL;
	Node * temp[n], *temp2[n];
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (i == 0 && j == 0) {
				h = new Node;
				h->data = mat[i][j];
				h->right = h->down = NULL;
				c = h;
			}
			else if (i == 0) {
				c->right = new Node;
				c->right->data = mat[i][j];
				c->right->right = c->right->down = NULL;
				c = c->right;
			}
			else if (i > 0) {
				if (j == 0) {
					temp2[j]->down = new Node;
					temp2[j]->down->data = mat[i][j];
					temp2[j]->down->down = temp2[j]->down->right = NULL;
					c = temp2[j]->down;
				}
				else {
					c->right = new Node;
					c->right->data = mat[i][j];
					c->right->right = c->right->down = NULL;
					c = c->right;
					temp2[j]->down = c;
				}
			}
			temp[j] = c;
		}
		for (j = 0; j < n; ++j) {
			temp2[j] = temp[j];
		}
	}
	return h;
}