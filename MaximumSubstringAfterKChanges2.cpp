#include <bits/stdc++.h>
using namespace std;
// function to find the maximum length of  
// substring having character ch 
int findLen(string& A, int n, int k, char ch)
{
	int maxlen = 1;
	int cnt = 0;
	int l = 0, r = 0;

	// traverse the whole string 
	while (r < n) {

		/* if character is not same as ch
		   increase count */
		if (A[r] != ch)
			++cnt;

		/* While  count > k  traverse the string
		   again until count becomes less than k
		   and decrease the count when characters
		   are not same */
		while (cnt > k) {
			if (A[l] != ch)
				--cnt;
			++l;
		}

		/* length of substring will be rightIndex -
		   leftIndex + 1. Compare this with the maximum
		   length and return maximum length */
		maxlen = max(maxlen, r - l + 1);
		++r;
	}
	return maxlen;
}

// function which returns maximum length of substring 
int answer(string& A, int n, int k, unordered_set<char>& memo)
{
	int maxlen = 1;
	for (int i = 0; i < 26; ++i) {
		if (memo.count(i + 'A') > 0)
			maxlen = max(maxlen, findLen(A, n, k, i + 'A'));
		if (memo.count(i + 'a') > 0)
			maxlen = max(maxlen, findLen(A, n, k, i + 'a'));
	}
	return maxlen;
}
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		string s("");
		std::unordered_set<char> memo;
		for (int i = 0; i < n; ++i) {
			char x;
			cin >> x;
			s.push_back(x);
			if (memo.count(x) == 0)memo.insert(x);
		}
		{
			int res = answer(s, n, k, memo);
			cout << res << '\n';
			continue;
		}
		int res = 0;
		char p;
		for (int i = 0; i < n; ++i) {
			int dist = n - i;
			if (dist <= res)break;
			if (i&&p == s[i])continue;
			int j = i + 1;
			int kk = k;
			int sub = 1;
			while (j < n&&kk >= 0) {
				if (s[j] == s[i]) {
					++sub;
					++j;
					continue;
				}
				if (kk == 0)break;
				--kk;
				++sub;
				++j;
			}
			res = max(res, sub);
			p = s[i];
		}
		cout << res << "\n";
	}
	return 0;
}