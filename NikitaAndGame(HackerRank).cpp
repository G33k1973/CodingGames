#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
#define sc static_cast<ll>
vector<string> split_string(string);

/*
 * Complete the arraySplitting function below.
 */
int arraySplitting(vector<int> arr) {
	/*
	 * Write your code here.
	 */
	int n = static_cast<int>(arr.size());
	if (n == 0)return 0;
	ll sum = 0LL;
	int cnt0 = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] == 0)++cnt0;
		else sum += sc(arr[i]);
	}
	if (cnt0 == n)return n - 1;
	vector<ll> tobefound;
	while (1) {
		bool isodd = ((abs(sum)) & 1);
		if (isodd)break;
		sum = sum / 2;
		tobefound.push_back(sum);
	}
	if (tobefound.empty())return 0;
	unordered_map<ll, int> h;
	vector<bool> visited(int(tobefound.size()), false);
	ll cum = 0LL;
	for (int i = 0; i < n; ++i) {
		cum += sc(arr[i]);
		for (int j = 0; j<int(tobefound.size()); ++j) {
			if (visited[j])continue;
			if (cum == tobefound.at(j) || h.find(cum - tobefound[j]) != end(h)) {
				visited[j] = true;
			}
		}
		++h[cum];
	}
	int res = 0;
	for (int i = 0; i<int(tobefound.size()); ++i) {
		if (!visited[i])break;
		++res;
	}
	return res;
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

		vector<int> arr(arr_count);

		for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
			int arr_item = stoi(arr_temp[arr_itr]);

			arr[arr_itr] = arr_item;
		}

		int result = arraySplitting(arr);

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
