#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'clique' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */
using ll = long long int;
#define sc static_cast<ll>
ll turan(ll n, ll k) {
	ll res = (n & 1) ? (((n - 1) / 2)*n) : ((n / 2)*(n - 1));
	ll cl = static_cast<ll>(std::ceil(static_cast<double>(n) / static_cast<double>(k)));
	ll ml = (n%k);
	ll mdiv = 0LL;
	if (cl & 1) {
		mdiv = (((cl - 1) / 2)*cl);
	}
	else {
		mdiv = ((cl / 2)*(cl - 1));
	}
	res -= ml * mdiv;
	res -= (k - ml)*mdiv;
	return res;
}
ll get_calc(ll m, ll n) {
	ll g1 = n % m;
	ll g2 = m - g1;
	ll sz1 = n / m + 1;
	ll sz2 = n / m;

	return g1 * sz1 * g2 * sz2 + g1 * (g1 - 1) * sz1 * sz1 / 2 + g2 * (g2 - 1) * sz2 * sz2 / 2;
}
ll clique(int n, int m) {
	ll low = 1, high = n + 1;
	while (low + 1 < high) {
		ll middle = low + (high - low) / 2;
		ll valturan = get_calc(middle, sc(n));
		if (valturan < sc(m)) {
			low = middle;
		}
		else {
			high = middle;
		}
	}
	return high;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string t_temp;
	getline(cin, t_temp);

	int t = stoi(ltrim(rtrim(t_temp)));

	for (int t_itr = 0; t_itr < t; t_itr++) {
		string first_multiple_input_temp;
		getline(cin, first_multiple_input_temp);

		vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

		int n = stoi(first_multiple_input[0]);

		int m = stoi(first_multiple_input[1]);

		ll result = clique(n, m);

		fout << result << "\n";
	}

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

vector<string> split(const string &str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}
