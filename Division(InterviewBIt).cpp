int Solution::divide(int A, int B) {
	if (A == 0)return 0;
	if (B == 0)return INT_MAX;
	if (B == 1)return A;
	bool neg = false;
	if (A < 0 && B>0)neg = !neg;
	if (A > 0 && B < 0)neg = !neg;
	double a = static_cast<double>(A);
	double b = static_cast<double>(B);
	a = abs(a);
	b = abs(b);
	double result = exp(log(a) - log(b));
	if (neg)result = -result;
	//cout << result << endl;
	if (floor(result) < static_cast<double>(INT_MIN) ||
		floor(result) > static_cast<double>(INT_MAX))return INT_MAX;
	return static_cast<int>(std::floor(result));
}
