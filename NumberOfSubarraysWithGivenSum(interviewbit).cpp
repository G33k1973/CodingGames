using ll = long long int;
int Solution::solve(vector<int> &A, int B) {
	int n = int(A.size());
	if (n == 0)return 0;
	unordered_map<ll, vector<int>> h;
	ll sum = 0;
	int i = 0;
	int res(0);
	while (i < n) {
		sum += static_cast<ll>(A[i]);
		if (sum == static_cast<ll>(B))++res;
		auto it = h.find(sum - static_cast<ll>(B));
		if (it != end(h))res += int(it->second.size());
		h[sum].push_back(i);
		++i;
	}
	return res;
}
