class Solution {
private:
	enum COLORS { WHITE = 0, GRAY, BLACK };
	vector<COLORS> cols;
	unordered_map<int, vector<int>> graph;
	vector<bool> IsRoot;
	vector<int> r;
	bool IsCyclic(int src, stack<int>& ms) {
		cols[src] = GRAY;
		for (int& x : graph[src]) {
			if (cols[x] == WHITE && IsCyclic(x, ms))return true;
			if (cols[x] == GRAY)return true;
		}
		cols[src] = BLACK;
		ms.push(src);
		return false;
	}
public:
	vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
		if (n == 0)return r;
		vector<int> checker(n, 0);
		std::iota(begin(checker), end(checker), 0);
		IsRoot.assign(n, true);
		cols.assign(n, WHITE);
		for (vector<int>& x : prerequisites) {
			int u = x.front(), v = x.back();
			if (IsRoot[v])IsRoot[v] = false;
			graph[u].push_back(v);
		}
		for (int i = 0; i < n; ++i) {
			if (cols[i] == WHITE && IsRoot[i]) {
				stack<int> pile;
				if (IsCyclic(i, pile))return vector<int>{};
				vector<int> temp;
				while (!pile.empty()) {
					temp.push_back(pile.top());
					pile.pop();
				}
				reverse(begin(temp), end(temp));
				r.insert(r.end(), temp.begin(), temp.end());
			}
		}
		vector<int> rr(r);
		sort(begin(rr), end(rr));
		if (rr != checker)return vector<int>{};
		return r;
	}
};