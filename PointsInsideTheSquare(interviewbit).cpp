int Solution::solve(int A, int B, int C, int D) {
	if (A == C && B == D)return 0;
	int deltax = C - A - 1;
	int deltay = D - B - 1;
	return deltax * deltay;
}
