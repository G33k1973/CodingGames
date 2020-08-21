#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
vector<string> solve(vector<int>& arr, vector<vector<int>>& queries) {
	vector<string> res;
	for (auto& x : queries) {
		int b = x.front(), c = x.back();
		--b, --c;
		if (b != c && arr[b + 1] == 0 && b + 1 <= c)
			res.push_back(move("Odd"));
		else
		{
			if (arr[b] % 2 == 0)
				res.push_back(move("Even"));
			else
				res.push_back(move("Odd"));
		}
	}
	return res;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

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

	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<vector<int>> queries(q);
	for (int queries_row_itr = 0; queries_row_itr < q; queries_row_itr++) {
		queries[queries_row_itr].resize(2);

		for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
			cin >> queries[queries_row_itr][queries_column_itr];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	vector<string> result = solve(arr, queries);

	for (int result_itr = 0; result_itr < result.size(); result_itr++) {
		fout << result[result_itr];

		if (result_itr != result.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";

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
