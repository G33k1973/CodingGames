#define pb push_back
#define CHARS 255
bool IsGood(int *a, int *b) {
	for (int i = 0; i <= CHARS; ++i) {
		if (b[i] > a[i])return 0;
	}
	return 1;
}
string Solution::minWindow(string A, string B) {
	int n = int(A.length());
	int m = int(B.length());
	if (m > n)return "";
	int b[CHARS + 1] = { 0 };
	for (auto& x : B)++b[x];
	int a[CHARS + 1] = { 0 };
	for (auto& x : A)++a[x];
	if (!IsGood(a, b))return "";
	int start = 0, end = -1;
	int h[CHARS + 1] = { 0 };
	int i = 0;
	pair<int, int> ans{ 0,-1 };
	int minl = INT_MAX;
	while (i < n) {
		++h[A[i]];
		while (IsGood(h, b)) {
			int dist = i - start + 1;
			if (dist < minl) {
				minl = dist;
				ans.first = start, ans.second = i;
			}
			--h[A[start++]];
		}
		++i;
	}
	while (IsGood(h, b)) {
		int dist = i - start + 1;
		if (dist < minl) {
			minl = dist;
			ans.first = start, ans.second = i;
		}
		--h[A[start++]];
	}
	if (ans.second == -1)return "";
	return A.substr(ans.first, minl);
}
