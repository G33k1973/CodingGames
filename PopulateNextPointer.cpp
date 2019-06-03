void dfs(node* p, vector<node*>& arr) {
	if (p == 0)return;
	dfs(p->left, arr);
	arr.push_back(p);
	dfs(p->right, arr);
	return;
}

void populateNext(struct node* p)
{
	// Your code goes here
	if (p == 0)return;
	vector<node*> arr;
	dfs(p, arr);
	for (int i = 0; i < (int)arr.size(); ++i) {
		node * curr = arr.at(i);
		if (i != ((int)arr.size() - 1)) {
			curr->next = arr.at(i + 1);
		}
	}
	return;
}