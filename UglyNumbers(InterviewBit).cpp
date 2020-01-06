vector<int> Solution::solve(int A, int B, int C, int D) {
	vector<int> seq(D, 0);
	int nextA = 1, nextB = 1, nextC = 1;
	int nextsmallest;
	int fA = A, fB = B, fC = C;
	int iA = -1, iB = -1, iC = -1;
	for (int i = 0; i < D; ++i) {
		nextsmallest = min(fA, min(fB, fC));
		seq[i] = nextsmallest;
		if (nextsmallest == fA) {
			++iA;
			fA = A * seq[iA];
		}
		if (nextsmallest == fB) {
			++iB;
			fB = B * seq[iB];
		}
		if (nextsmallest == fC) {
			++iC;
			fC = C * seq[iC];
		}
	}
	return seq;
}
