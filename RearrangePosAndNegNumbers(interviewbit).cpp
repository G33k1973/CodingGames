vector<int> Solution::solve(vector<int> &A) {
	int n = int(A.size());
	if (n < 2)return A;
	queue<int> pn, nn;
	for (int& i : A) {
		if (i >= 0)pn.push(i);
		else nn.push(i);
	}
	int c = 0;
	while (c < n) {
		if (c & 1) {
			if (!pn.empty()) {
				A[c] = pn.front();
				pn.pop();
			}
			else {
				while (!nn.empty()) {
					A[c++] = nn.front();
					nn.pop();
				}
			}
		}
		else {
			if (!nn.empty()) {
				A[c] = nn.front();
				nn.pop();
			}
			else {
				while (!pn.empty()) {
					A[c++] = pn.front();
					pn.pop();
				}
			}
		}
		++c;
	}
	return A;
}
