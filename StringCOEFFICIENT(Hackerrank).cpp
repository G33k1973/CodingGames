#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minStringCoeff' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER p
 */
#define pb push_back
int minStringCoeff(string s, int p) {
	int l = static_cast<int>(s.size());
	if (l < 3)return 0;
	if (p == l)return 0;
	int c0(0), c1(0);
	vector<int> left, right;
	int i = 1;
	char fc = s.front();
	if (fc == '0')++c0;
	else if (fc == '1')++c1;
	char prev = fc;
	while (i < l) {
		char x = s.at(i);
		if (x != prev) {
			left.pb(i);
		}
		if (x == '0')++c0;
		else if (x == '1')++c1;
		prev = x;
		++i;
	}
	if (p >= min(c0, c1))return 0;
	char lc = s.back();
	prev = lc;
	i = l - 2;
	while (i >= 0) {
		char x = s.at(i);
		if (x != prev) {
			right.pb(i);
		}
		prev = x;
		--i;
	}
	int n = static_cast<int>(left.size());
	int m = static_cast<int>(right.size());
	vector<int> memoleft{ left.front() }, memoright{ right.front() };
	for (i = 2; i < n; i += 2) {
		memoleft.push_back(left[i]);
	}
	memoleft.push_back(l);
	for (i = 2; i < m; i += 2) {
		memoright.push_back(right[i]);
	}
	memoright.push_back(-1);
	n = int(memoleft.size());
	m = int(memoright.size());
#define PRINT
#undef PRINT
#if defined PRINT
	for (int i = 0; i < n; ++i)cout << memoleft[i] << " ";
	cout << endl;
	for (int i = 0; i < n; ++i)cout << memoright[i] << " ";
	cout << endl;
#endif
	if (p >= min(n, m))return 0;
	int ans = INT_MAX;
	for (i = 0; i <= p; ++i) {
		int j = p - i;
		//compute string Co-efficient between
		int u = memoleft.at(i), v = memoright.at(j);
		++v, --u;
		auto it = std::lower_bound(begin(left), end(left), u);
		int sub = 0;
		while (it != std::prev(left.end())) {
			auto itnext = next(it, 1);
			if (*itnext > v)break;
			sub += *itnext - *it;
			++it;
		}
		//cout<<u<<" "<<v<<" "<<sub<<endl;
		ans = min(sub, ans);
	}
	return ans;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string first_multiple_input_temp;
	getline(cin, first_multiple_input_temp);

	vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

	int n = stoi(first_multiple_input[0]);

	int p = stoi(first_multiple_input[1]);

	string s;
	getline(cin, s);
	n = s.size();

	int res = minStringCoeff(s, p);

	fout << res << "\n";

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
