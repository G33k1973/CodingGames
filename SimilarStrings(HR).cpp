#include <bits/stdc++.h>

using namespace std;
#define pb push_back
vector<string> split_string(string);

/*
 * Complete the similarStrings function below.
 */
vector<vector<vector<int>>> graph;
vector<int> similarStrings(int n, vector<vector<int>> queries) {
	/*
	 * Write your code here.
	 */
	vector<int> res;
	for (auto& x : queries) {
		int is = x.front(), ie = x.back();
		int cl = ie - is + 1;
		if (cl == 1)res.pb(n);
		else if (cl == n)res.pb(0);
		else res.pb(graph[cl][is - 1].size() + 1);
	}
	return res;
}

bool AreSimilar(string& s, int is, int ie, int js, int je) {
	int i, j;
	for (i = is; i < ie; ++i) {
		for (j = is + 1; j <= ie; ++j) {
			if (s[i] == s[j] && s[js + i - is] != s[js + j - is])return false;
			if (s[i] != s[j] && s[js + i - is] == s[js + j - is])return false;
		}
	}
	return true;
}

void build_graph(string& s, int n) {
	graph.assign(n, vector<vector<int>>(n, vector<int>()));
	int i, j, cl;
	for (cl = 2; cl < n; ++cl) {
		for (i = 0; i < (n - cl); ++i) {
			int is = i, ie = i + cl - 1;
			for (j = i + 1; j <= n - cl; ++j) {
				int js = j, je = j + cl - 1;
				if (AreSimilar(s, is, ie, js, je)) {
					//cout<<s.substr(is,cl)<<" "<<s.substr(js,cl)<<endl;
					graph[cl][i].pb(j);
					graph[cl][j].pb(i);
				}
			}
		}
	}
	return;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string nq_temp;
	getline(cin, nq_temp);

	vector<string> nq = split_string(nq_temp);

	int n = stoi(nq[0]);

	int q = stoi(nq[1]);

	string s = "";
	cin >> s;

	build_graph(s, n);

	vector<vector<int>> queries(q);
	for (int queries_row_itr = 0; queries_row_itr < q; queries_row_itr++) {
		queries[queries_row_itr].resize(2);

		for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
			cin >> queries[queries_row_itr][queries_column_itr];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	vector<int> result = similarStrings(n, queries);

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
