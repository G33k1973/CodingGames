#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
#define M 1000000007
#define ms(a,b) (((a%M)+(b%M))%M)
#define sc static_cast<ll>
ll mul(ll a, ll b) {
	ll res = 0ULL;
	a %= M;
	while (b > 0) {
		if (b & 1) {
			res = ms(res, a);
		}
		b >>= 1;
		a = (a * 2ULL) % M;
	}
	return (res%M);
}
ll fex(ll b, ll n) {
	ll res = 1ULL;
	b %= M;
	while (n > 0) {
		if (n & 1)res = mul(res, b);
		n >>= 1;
		b = mul(b, b);
	}
	return res;
}
vector<string> split_string(string);

// Complete the solve function below.
ll solve(int n, int m) {
	if (n == 1)return m;
	if (m == 2) {
		if (n == 2)return m;
		return 0;
	}
	ll res = mul(sc(m), sc(m - 1));
	ll sub = fex(sc(m - 2), sc(n - 2));
	res = mul(res, sub);
	return res;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		string nm_temp;
		getline(cin, nm_temp);

		vector<string> nm = split_string(nm_temp);

		int n = stoi(nm[0]);

		int m = stoi(nm[1]);

		ll result = solve(n, m);

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