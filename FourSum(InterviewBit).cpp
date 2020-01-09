#define pb push_back
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
	int n = static_cast<int>(A.size());
	vector<vector<int>> res;
	if (n < 4)return res;
	std::map<vector<int>, int> seen;
	int i, j, u, v;
	sort(begin(A), end(A), less<int>());
	for (i = 0; i < n - 3; ++i) {
		int x = A[i];
		if (x > B && B > 0)break;
		for (j = i + 1; j < n - 2; ++j) {
			int y = A[j];
			if (x + y > B && B > 0)break;
			for (u = j + 1; u < n - 1; ++u) {
				int z = (x + y + A[u]);
				if (z > B && B > 0)break;
				int target = B - z;
				if (binary_search(begin(A) + u + 1, end(A), target)) {
					vector<int> temp{ x,y,A[u],target };
					if (seen.find(temp) == end(seen)) {
						++seen[temp];
						res.push_back(temp);
					}
				}
			}
		}
	}
	return res;
}
