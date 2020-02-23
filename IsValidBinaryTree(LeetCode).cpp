#define pb push_back
class Solution {
private:
	unordered_map<int, vector<int>> graph;
public:
	bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
		if (n == 0)return true;
		vector<bool> isroot(n, true);
		int nr(n);
		for (int i = 0; i < n; ++i) {
			if (leftChild[i] != -1) {
				graph[i].pb(leftChild[i]);
				if (isroot.at(leftChild[i]) == true) {
					isroot.at(leftChild[i]) = false;
					--nr;
				}
				else return false;
			}
			if (rightChild[i] != -1) {
				graph[i].pb(rightChild[i]);
				if (isroot.at(rightChild[i]) == true) {
					isroot.at(rightChild[i]) = false;
					--nr;
				}
				else return false;
			}
		}
		if (nr != 1)return false;
		return true;
	}
};