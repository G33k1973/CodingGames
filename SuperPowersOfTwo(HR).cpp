#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

using ll = long long int;
ll ms(ll a, ll b, ll c) {
	return (((a%c) +
		(b%c)) % c);
}
#define sc static_cast<ll>
// Complete the solve function below.
ll mul(ll a, ll b, ll c) {
	ll res = 0LL;
	a %= c;
	while (b > 0) {
		if (b & 1) {
			res = ms(res, a, c);
		}
		b >>= 1;
		a = (a * 2LL) % c;
	}
	return (res%c);
}
ll fex(ll b, ll n, ll c) {
	ll res = 1LL;
	b %= c;
	if (b == 0)return 0LL;
	while (n > 0) {
		if (n & 1) {
			res = mul(res, b, c);
		}
		n >>= 1;
		b = mul(b, b, c);
	}
	return res;
}
int solve(int a, int b) {
	ll x = 4LL;
	return
		fex(x, sc(a), sc(b));
}

int solve2(int a, int b)

{

	long int i, c = 2;

	for (i = 1; i <= a; i++)

	{

		c = (c*c) % b;


	}
	return c;

}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string ab_temp;
	getline(cin, ab_temp);

	vector<string> ab = split_string(ab_temp);

	int a = stoi(ab[0]);

	int b = stoi(ab[1]);

	int result = solve2(a, b);

	fout << result << "\n";

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
