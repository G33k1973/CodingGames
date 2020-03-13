string Solution::solve(string A) {
	int l = int(A.size());
	if (l < 2)return A;
	vector<int> h(26, 0);
	string b = "";
	int i = 0, j = 0;
	while (i < l) {
		int k = A[i] - 'a';
		++h[k];
		while (j <= i && h[A[j] - 'a'] > 1)++j;
		if (j > i)b += "#";
		else b.push_back(A[j]);
		++i;
	}
	return b;
}
