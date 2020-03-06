using ll = unsigned long long int;
#define sc static_cast<ll>
ll GetSum(int x) {
	return (x & 1) ? (sc((x - 1) / 2)*sc(x)) : (sc(x / 2)*sc(x - 1));
}
int Solution::solve(int A) {
	if (A < 3)return 0;
	int A2 = int(ceil(1.*A / 2.));
	int res = 1;
	for (int i = 1; i <= A2; ++i) {
		ll sub2 = 0;
		for (int j = i;; ++j) {
			sub2 += sc(j);
			if (sub2 > A)break;
			if (sub2 == A) {
				++res;
				break;
			}
		}
	}
	return res;
}
