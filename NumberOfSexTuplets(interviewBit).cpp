#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
using ll = long long int;
#define sc static_cast<ll>
using ull = unsigned long long int;
#define sc2 static_cast<ull>
ull mul(ull a, ull b) {
	ull res = 0ULL;
	a %= M;
	while (b > 0) {
		if (b & 1)res = ms(res, a);
		b >>= 1;
		a = (a * 2ULL) % M;
	}
	return (res%M);
}
int Solution::solve(vector<int> &A) {
	int n = int(A.size());
	if (n == 0)return 0;
	unordered_map<ll, ull> LHS, RHS;
	int i, j, k;
	for (i = 0; i < n; ++i) {
		int x = A[i];
		for (j = 0; j < n; ++j) {
			int y = A[j];
			for (k = 0; k < n; ++k) {
				int z = A[k];
				ll lv = sc(x)*sc(y) + sc(z);
				ll rv = sc(x)*(sc(y) + sc(z));
				LHS[lv] = ms(LHS[lv], 1ULL);
				if (x != 0)RHS[rv] = ms(RHS[rv], 1ULL);
			}
		}
	}
	ull res(0LL);
	for (auto& x : LHS) {
		ull fx = x.second;
		auto it = RHS.find(x.first);
		if (it != end(RHS)) {
			ull fy = it->second;
			ull sub = mul(fx, fy);
			res = ms(res, sub);
		}
	}
	return int(res);
}
