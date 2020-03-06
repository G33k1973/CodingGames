using ll = long long int;
#define sc static_cast<ll>
int Solution::solve(vector<int> &A) {
	int n = static_cast<int>(A.size());
	if (n == 0)return 0;
	unordered_map<ll, int> h;
	ll sum = 0;
	int i = 0;
	while (i < n) {
		sum += sc(A[i]);
		if (sum == 0)return 1;
		auto it = h.find(sum);
		if (it != end(h))return 1;
		++h[sum];
		++i;
	}
	return 0;
}
