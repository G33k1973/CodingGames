#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the manipulativeNumbers function below.
 */
string get(int x) {
	string res(32, '0');
	int j = 0;
	for (unsigned int i = 1 << 31; i > 0; i >>= 1) {
		if (x&i)res[j] = '1';
		++j;
	}
	return res;
}
int manipulativeNumbers(vector<int> a) {
	/*
	 * Write your code here.
	 */
	const int l = int(a.size());
	vector<string> arr(l, string(""));
	for (int i = 0; i < l; ++i)arr[i] = get(a[i]);
	int c = 0;
	int i, j;
	vector<int> ison(l, 0);
	cout << "here!\n";
	for (j = 0; j < 32; ++j) {
		for (i = 0; i < l; ++i) {
			if (arr[i][j] == '1' && !ison[i]) {
				ison[i] = 1;
				++c;
				if (c >= l / 2)return 31 - j;
			}
		}
	}
	return 0;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int a_count;
	cin >> a_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string a_temp_temp;
	getline(cin, a_temp_temp);

	vector<string> a_temp = split_string(a_temp_temp);

	vector<int> a(a_count);

	for (int a_itr = 0; a_itr < a_count; a_itr++) {
		int a_item = stoi(a_temp[a_itr]);

		a[a_itr] = a_item;
	}

	int result = manipulativeNumbers(a);

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
