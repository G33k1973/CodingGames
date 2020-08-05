#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
bool isprime(long x) {
	if (x == 1)return false;
	if (x == 2 || x == 3)return true;
	if (x % 2 == 0 || x % 3 == 0)return false;
	for (long j = long(5); j*j <= x; j += long(6)) {
		if (x%j == 0 || x % (j + long(2)) == 0)return false;
	}
	return true;
}
// Complete the solve function below.
string solve(long n, long k) {
	long N = long(2)*k;
	if (n < N)return "No";
	if (k == 1) {
		if (isprime(n))return "Yes";
		return "No";
	}
	if (k == 2) {
		if (!(n & 1))return "Yes";
		if (isprime(n - 2))return "Yes";
		else return "No";
	}
	return "Yes";
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		string nk_temp;
		getline(cin, nk_temp);

		vector<string> nk = split_string(nk_temp);

		long n = stol(nk[0]);

		long k = stol(nk[1]);

		string result = solve(n, k);

		fout << result << "\n";
	}

	fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
