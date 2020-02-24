int mul(int a, int b, int m) {
	int res = 0;
	a = (a%m + m) % m;
	while (b) {
		if (b & 1)res = (res%m + m + a % m) % m;
		b >>= 1;
		a = (a * 2 + m) % m;
	}
	return (res%m);
}
int fex(int b, int n, int m) {
	int res = 1;
	b = (b%m + m) % m;
	while (n > 0) {
		if (n & 1)res = mul(res, b, m);
		n >>= 1;
		b = mul(b, b, m);
	}
	return res;
}

int Solution::Mod(int A, int B, int C) {
	if (A == 0)return 0;
	return fex(A, B, C);
}
