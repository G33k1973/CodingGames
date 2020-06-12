#include <bits/stdc++.h>

using namespace std;

// Complete the stringSimilarity function below.
void getlps(vector<int>& lps, string& s, int l) {
	int len = 0, i = 1;
	while (i < l) {
		if (s[len] == s[i]) {
			++len;
			lps[i] = len;
			++i;
		}
		else {
			if (len != 0)len = lps[len - 1];
			else ++i;
		}
	}
}
using ll = long long int;
#define sc static_cast<ll>
ll stringSimilarity(string s) {
	const int n = static_cast<int>(s.length());
	if (n == 0)return 0;
	if (n == 1)return 1;
	int L, R, k;
	ll ans(sc(n));
	vector<int> Z(n, 0);
	// [L,R] make a window which matches with prefix of s 
	L = R = 0;
	for (int i = 1; i < n; ++i)
	{
		// if i>R nothing matches so we will calculate. 
		// Z[i] using naive way. 
		if (i > R)
		{
			L = R = i;

			// R-L = 0 in starting, so it will start 
			// checking from 0'th index. For example, 
			// for "ababab" and i = 1, the value of R 
			// remains 0 and Z[i] becomes 0. For string 
			// "aaaaaa" and i = 1, Z[i] and R become 5 
			while (R < n && s[R - L] == s[R])
				R++;
			Z[i] = R - L;
			ans += sc(Z[i]);
			R--;
		}
		else
		{
			// k = i-L so k corresponds to number which 
			// matches in [L,R] interval. 
			k = i - L;

			// if Z[k] is less than remaining interval 
			// then Z[i] will be equal to Z[k]. 
			// For example, str = "ababab", i = 3, R = 5 
			// and L = 2 
			if (Z[k] < R - i + 1) {
				Z[i] = Z[k];
				ans += sc(Z[i]);
			}

			// For example str = "aaaaaa" and i = 2, R is 5, 
			// L is 0 
			else
			{
				// else start from R and check manually 
				L = i;
				while (R < n && s[R - L] == s[R])
					R++;
				Z[i] = R - L;
				ans += sc(Z[i]);
				R--;
			}
		}
	}
	return ans;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		string s;
		getline(cin, s);

		ll result = stringSimilarity(s);

		fout << result << "\n";
	}

	fout.close();

	return 0;
}
