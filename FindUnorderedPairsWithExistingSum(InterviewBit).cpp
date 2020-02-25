using ll = long long int;
#define sc static_cast<ll>
int Solution::solve(vector<int> &A) {
	int n = static_cast<int>(A.size());
	if (n < 3)return 0;
	unordered_set<ll> h;
	for (int& i : A)h.insert(sc(i));
	int i, j, c = 0;
	for (i = 0; i < n - 1; ++i) {
		for (j = i + 1; j < n; ++j) {
			ll x = sc(A[i]) + sc(A[j]);
			if (h.count(x))++c;
		}
	}
	return c;
}
