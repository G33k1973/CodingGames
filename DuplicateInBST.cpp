void dfs(Node * root, string & s, int& gd) {
	if (root == 0) {
		s.push_back('#');
		return;
	}
	s.push_back(root->data);
	++gd;
	dfs(root->left, s, gd);
	dfs(root->right, s, gd);
	return;
}
void dfs(Node * r, unordered_map<string, int>& m, int& res) {
	if (r == 0)return;
	dfs(r->left, m, res);
	if (res == 1)return;
	string s("");
	int cnt = 0;
	dfs(r, s, cnt);
	if (cnt >= 2) {
		//cout << s << endl;
		auto it = m.find(s);
		if (it != end(m)) {
			res = 1;
			return;
		}
		else ++m[s];
	}
	dfs(r->right, m, res);
	if (res == 1)return;
	return;
}
bool dupSub(Node *root)
{
	//your code here
	if (root == NULL)return false;
	std::unordered_map<std::string, int> hs;
	int res = 0;
	dfs(root, hs, res);
	return (res == 1);
}