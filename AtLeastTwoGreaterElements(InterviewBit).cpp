#define pb push_back
vector<int> Solution::solve(vector<int> &A) {
	int n = static_cast<int>(A.size());
	if (n < 3)return vector<int>{};
	vector<int> B(A);
	sort(begin(B), end(B));
	auto it = std::unique(begin(B), end(B));
	B.resize(int(it - begin(B)));
	vector<int> res;
	int m = static_cast<int>(B.size());
	if (m < 2)return vector<int>{};
	for (int& i : A) {
		auto it = std::upper_bound(begin(B), end(B), i);
		int diff = static_cast<int>(it - begin(B));
		diff = m - diff;
		if (diff >= 2)res.pb(i);
	}
	return res;
}
