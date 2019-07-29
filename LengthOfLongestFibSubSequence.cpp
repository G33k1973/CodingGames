class Solution {
private:
	int dfs(const std::vector<int>& A, int n, int i, const std::unordered_map<int, vector<int>>& h, int p1, int p2) {
		if (i == n)return 0;
		int target = p1 + p2;
		auto it = h.find(target);
		if (it == end(h))return 0;
		auto it2 = std::lower_bound(begin(it->second), end(it->second), i);
		if (it2 == end(it->second))return 0;
		return 1 + dfs(A, n, *it2 + 1, h, p2, target);
	}
public:
	int lenLongestFibSubseq(vector<int>& A) {
		int l = (int)A.size();
		if (l < 2)return l;
		unordered_map<int, vector<int>> h;
		for (int i = 0; i < l; ++i) {
			h[A[i]].push_back(i);
		}
		int i, j;
		int res(1);
		for (i = 0; i < l; ++i) {
			int x = A[i];
			int mxup = l - i;
			if (mxup <= res)break;
			for (int j = i + 1; j < l; ++j) {
				int mx = 1 + l - j;
				if (mx <= res)break;
				int y = A[j];
				if (y < x)continue;
				int sub = 2 + dfs(A, l, j + 1, h, x, y);
				res = max(sub, res);
			}
		}
		return (res > 2) ? (res) : (0);
	}
};