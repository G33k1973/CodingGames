int Solution::solve(int A, int B, int C) {
	if (A == 0)return 0;
	if (A == 1)return max(B, C);
	if (A == (B + C))return 1;
	int mxcandies = max(B, C);
	int mncandies = min(B, C);
	int res = INT_MIN;
	int left = 0;
	while (left <= A) {
		int division1 = INT_MIN;
		if (A > left)division1 = mxcandies / (A - left);
		int division2 = INT_MIN;
		if (left > 0)
			division2 = mncandies / left;
		if (division1 == 0 && division2 == 0) {
			if (res != INT_MIN)break;
		}
		else if (division1 == INT_MIN) {
			res = max(res, division2);
		}
		else if (division2 == INT_MIN) {
			res = max(res, division1);
		}
		else {
			res = max(res, min(division1, division2));
		}
		++left;
	}
	return res;
}
