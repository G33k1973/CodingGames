#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getNumberOfIntegers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING L
 *  2. STRING R
 *  3. INTEGER K
 */
#define M 1000000007
using ll = unsigned long long int;
#define ms(a,b) (((a%M)+(b%M))%M)
string findDiff(string str1)
{
	string str = "";
	string str2 = "1";
	int n1 = str1.length(), n2 = str2.length();

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;

	for (int i = 0; i < n2; i++)
	{
		int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);

		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}

	// subtract remaining digits of larger number 
	for (int i = n2; i < n1; i++)
	{
		int sub = ((str1[i] - '0') - carry);

		// if the sub value is -ve, then make it positive 
		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}

	// reverse resultant string 
	reverse(str.begin(), str.end());
	int erlen = 0;
	while (str[erlen] == '0')++erlen;
	str.erase(0, erlen);
	return str;
}
int getNumberOfIntegers(string L, string R, int k) {
	int res = 0;

	int n = int(R.size());
	vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(2, vector<ll>(k + 1, 0ULL)));
	dp[0][0][0] = 1;
	for (int i = 0; i < n; ++i) {
		int sm = 0;
		while (sm < 2) {
			for (int j = 0; j < k + 1; ++j) {
				int x = 0;
				while (x <= (sm ? 9 : R[i] - '0')) {
					int u = sm || x < (R[i] - '0');
					int v = j + (x > 0);
					dp[i + 1][u][v] = ms(dp[i + 1][u][v], dp[i][sm][j]);
					++x;
				}
			}
			++sm;
		}
	}
	//L=findDiff(L);
	//cout<<L<<endl;
	int m = int(L.size());
	vector<vector<vector<ll>>> dp2(m + 1, vector<vector<ll>>(2, vector<ll>(k + 1, 0ULL)));
	dp2[0][0][0] = 1;
	for (int i = 0; i < m; ++i) {
		int sm = 0;
		while (sm < 2) {
			for (int j = 0; j < k + 1; ++j) {
				int x = 0;
				while (x <= (sm ? 9 : L[i] - '0')) {
					int u = sm || x < (L[i] - '0');
					int v = j + (x > 0);
					dp2[i + 1][u][v] = ms(dp2[i + 1][u][v], dp2[i][sm][j]);
					++x;
				}
			}
			++sm;
		}
	}
	res = ms(dp[n][0][k], dp[n][1][k]);
	ll sub = ms(dp2[m][0][k], dp2[m][1][k]);
	//cout<<res<<" "<<sub<<endl;
	res = (res%M - sub % M + M) % M;
	return int(res);
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string L;
	getline(cin, L);

	string R;
	getline(cin, R);

	string K_temp;
	getline(cin, K_temp);

	int K = stoi(ltrim(rtrim(K_temp)));

	int ans = getNumberOfIntegers(L, R, K);

	fout << ans << "\n";

	fout.close();

	return 0;
}

string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}
