int mul(int x, int y, int p);
int MyPower(int x, int y, int p) {
	int res = 1;
	x = x % p;
	while (y > 0) {
		if (y & 1) {
			res = mul(res, x, p);// (res*x) % p;
		}
		y >>= 1;
		x = mul(x, x, p);
	}
	return res % p;
}
#define ms(a,b,p) (((a%p)+(b%p))%p)
int mul(int x, int y, int p) {
	int res = 0;
	x %= p;
	while (y > 0) {
		if (y & 1)res = ms(res, x, p);
		y >>= 1;
		x = (x * 2) % p;
	}
	return res % p;
}

int ModInverse(int n, int p) {
	return MyPower(n, p - 2, p);
}

int Solution::solve(int A, int B, int C) {
	vector<int> factor(A + 1, 0);
	factor.front() = 1;
	for (int i = 1; i <= A; ++i) {
		//factor[i] = (factor[i - 1] * i) % C;
		factor[i] = mul(factor[i - 1], i, C);
	}
	int p(C);
	//(((factor[A]*ModInverse(factor[B],C))%C)*(ModInverse(factor[A-B],C)%p)%p);
	int fact1 = mul(factor[A], ModInverse(factor[B], C), C);
	fact1 = mul(fact1, ModInverse(factor[A - B], C), C);
	return fact1;
}
