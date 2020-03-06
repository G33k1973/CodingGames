#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
using ll = unsigned long long int;
#define sc static_cast<ll>
int Solution::solve(vector<int> &A, int B, int C, int D) {
	int n = int(A.size());
	if (n < 2)return 0;
	for (int& i : A) {
		i %= B;
	}
	int i, j;
	ll res = 0ULL;
	for (i = 0; i < n - 1; ++i) {
		for (j = i + 1; j < n; ++j) {
			int sum = (A[i] + A[j]) % B;
			int prd = (A[i] * A[j]) % B;
			if ((sum == C) && (prd == D))res = ms(res, 1ULL);
		}
	}
	return int(res);
}
