#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

using ll = unsigned long long int;

#define m 1000000007
#define ms(a,b) (((a%m)+(b%m))%m)

ll _mul_(ll a, ll b);

ll _FastExp_(ll b, ll n) {
	ll res(1ULL);
	b = b % m;
	while (n > 0) {
		if (n & 1) {
			res = _mul_(res, b);
		}
		n >>= 1;
		b = _mul_(b, b);
	}
	return res;
}

ll _mul_(ll a, ll b) {
	ll res = 0;
	a = a % m;
	while (b > 0) {
		if (b & 1) {
			res = ms(res, a);
		}
		b >>= 1;
		a = (a * 2) % m;
	}
	return res % m;
}

/*
 * Given that each element appears 2^n / 2 times (16 combinations with bit set half the time), multiply
the element by the multiplication factor and OR (don't know now the OR works here) them with all the other elements multiplied with
the multiplication factor.

multiplication factor (m) = i*(2^n/2)
	where:
		i is the element in array
		n is the length of array


iterate through each element and multiply by m followed by ORing all values together
SUM(1*m=8 | 2*m=16 | 3*m=24 | 4*m=32) = 56
 */
ll xoringNinja(vector<ll> arr) {
	/*
	 * Write your code here.
	 */
	ll n = static_cast<ll>(arr.size());
	ll res = 0ULL;
	ll sub = _FastExp_(static_cast<ll>(2ULL), n);
	//a^(m-2)==a^(-1)modP 
	//cout<<sub<<endl;
	ll moddiv = _FastExp_(2ULL, m - 2);
	sub = _mul_(sub, moddiv);
	for (int i = 0; i < n; ++i) {
		ll part = _mul_(arr[i], sub);
		res |= part;
	}
	return res % m;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		int arr_count;
		cin >> arr_count;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		string arr_temp_temp;
		getline(cin, arr_temp_temp);

		vector<string> arr_temp = split_string(arr_temp_temp);

		vector<ll> arr(arr_count);

		for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
			ll arr_item = stoull(arr_temp[arr_itr]);

			arr[arr_itr] = arr_item;
		}

		ll result = xoringNinja(arr);

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
