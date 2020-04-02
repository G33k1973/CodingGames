#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
#define N 210
#define INF 999999
// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
	int res{ 0 };
	int n = static_cast<int>(expenditure.size());
	if (d >= n)return 0;
	vector<int> a(N, 0);
	for (int i = 0; i < d; ++i) {
		int x = expenditure.operator[](i);
		assert(x >= 0 && x < N);
		++a[x];
	}
	int median = 0, c = -1;
	int half = d / 2;
	bool updated = false;
	for (int i = 0; i < N; ++i) {
		if (a[i] == 0)continue;
		c += a[i];
		if (c >= (half - 1) && (!(d & 1)) && updated == false) {
			median = i;
			updated = !updated;
		}
		if (c >= half) {
			if (updated)median = (median + i);
			else median = i;
			break;
		}
	}
	//cout<<median<<endl;
	if (updated == false && expenditure[d] >= 2 * median)++res;
	if (updated == true && expenditure[d] >= median)++res;
	for (int i = d + 1; i < n; ++i) {
		--a[expenditure[i - d - 1]];
		++a[expenditure[i - 1]];
		median = 0, c = -1;
		updated = false;
		for (int i = 0; i < N; ++i) {
			if (a[i] == 0)continue;
			c += a[i];
			if (c >= (half - 1) && (!(d & 1)) && updated == false) {
				median = i;
				updated = !updated;
			}
			if (c >= half) {
				if (updated)median = (median + i);
				else median = i;
				break;
			}
		}
		//cout<<median<<endl;
		if (updated == false && expenditure[i] >= 2 * median)++res;
		if (updated == true && expenditure[i] >= median)++res;
	}
	return res;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string nd_temp;
	getline(cin, nd_temp);

	vector<string> nd = split_string(nd_temp);

	int n = stoi(nd[0]);

	int d = stoi(nd[1]);

	string expenditure_temp_temp;
	getline(cin, expenditure_temp_temp);

	vector<string> expenditure_temp = split_string(expenditure_temp_temp);

	vector<int> expenditure(n);

	for (int i = 0; i < n; i++) {
		int expenditure_item = stoi(expenditure_temp[i]);

		expenditure[i] = expenditure_item;
	}

	int result = activityNotifications(expenditure, d);

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
