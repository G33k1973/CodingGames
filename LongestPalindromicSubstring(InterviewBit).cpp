bool IsPal(string& s,int i,int j) {
	while (i < j) {
		if (s[i++] != s[j--])return false;
	}
	return true;
}
string Solution::longestPalindrome(string A) {
	int l = int(A.size());
	if (l < 2)return A;
	int i, j;
	string s = string(1, A.front());
	for (i = l; i > 1;--i) {
		for (j = 0;j<=(l-i);++j) {
			if (IsPal(A, j, j + i - 1))return A.substr(j, i);
		}
	}
	return string(1, A[0]);
}
