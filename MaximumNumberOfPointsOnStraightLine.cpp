int GCD(int x, int y) {
	if (x == 0)return y;
	return GCD(y%x, x);
}

int Solution::maxPoints(vector<int> &A, vector<int> &B) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int n = static_cast<int>(A.size());
	int m = static_cast<int>(B.size());
	assert(n == m);
	if (n == 0)return 0;
	if (n == 1)return 1;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		int x1 = A[i], y1 = B[i];
		unordered_map<string, int> h;
		string s("");
		for (int j = 0; j < n; ++j) {
			if (j == i)continue;
			int x2 = A[j], y2 = B[j];
			if (x1 == x2) {
				s = "x" + to_string(x1);
			}
			else if (y1 == y2) {
				s = "y" + to_string(y1);
			}
			else {
				int num = y2 - y1, den = x2 - x1;
				int prod = num * den;
				bool positiveslope = (prod > 0);
				if (positiveslope)num = abs(num), den = abs(den);
				else num = -abs(num), den = abs(den);
				int z = GCD(abs(num), abs(den));
				num /= z, den /= z;
				s = to_string(num) + "/" + to_string(den);
			}
			++h[s];
			if ((h[s] + 1) > res)res = h[s] + 1;
		}
	}
	return res;
}
