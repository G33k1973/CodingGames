#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
int mul(int a, int b) {
	a %= M;
	int res = 0;
	while (b > 0) {
		if (b & 1)res = ms(res, a);
		b >>= 1;
		a = (a * 2) % M;
	}
	return (res%M);
}
unordered_set<int> primes;
void init(int n) {
	vector<bool> isprime(n + 1, true);
	for (int i = 2; i <= n; ++i) {
		if (isprime[i]) {
			primes.insert(i);
			for (int j = i * 2; j <= n; j += i) {
				isprime[j] = false;
			}
		}
	}
	return;
}
bool IsPrime(int x) {
	if (x == 1)return false;
	if (x == 2 || x == 3)return true;
	if (x % 2 == 0 || x % 3 == 0)return false;
	for (int j = 5; j*j <= x; j += 6) {
		if (x%j == 0 || (x % (j + 2)) == 0)return false;
	}
	return true;
}
int Solution::solve(vector<int> &A) {
	int n = int(A.size());
	if (n == 0)return 1;
	//if (primes.size() > 0)primes.clear();
	//int mx = *max_element(begin(A), end(A));
	//init(mx + 1);
	for (int& i : A) {
		//if (primes.count(i) == 0)i = 1;
		if (!IsPrime(i))i = 1;
	}
	int res = 1;
	for (auto& x : A) {
		int sub = mul(res, x + 1);
		res = sub;
	}
	return res;
}
