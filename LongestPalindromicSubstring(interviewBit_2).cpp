bool IsPal(string& s, int i, int j) {
	while (i < j) {
		if (s[i++] != s[j--])return false;
	}
	return true;
}
string res;
void dfs(string& A, int low, int high) {
	if (high - low + 1 <= int(res.size()))return;
	if (IsPal(A, low, high)) {
		res = A.substr(low, high - low + 1);
		return;
	}
	if (A[low + 1] == A[high])dfs(A, low + 1, high);
	if (A[low] == A[high - 1])dfs(A, low, high - 1);
	dfs(A, low + 1, high - 1);
	return;
}
string Solution::longestPalindrome(string A) {
	int l = int(A.size());
	if (l < 2)return A;
	int i = 0, j = l - 1;
	for (int cl = l; cl >= 1; --cl) {
		for (i = 0; i <= l - cl; ++i) {
			j = i + cl - 1;
			if (IsPal(A, i, j))return A.substr(i, cl);
		}
	}
	return "";
}
