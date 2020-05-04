#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
#define pb push_back
void Print(const vector<int>& a);
/*
 * Complete the roadsInHackerland function below.
 */
using ip = std::pair<int, int>;
vector<int> Sum(vector<int>& a, vector<int>& b) {
	//bool print=((a==vector<int>{0,1,2})&&(b==vector<int>{0}));
	map<int, int> rbt;
	for (int& x : a) {
		++rbt[x];
	}
	for (int& x : b) {
		auto it = rbt.find(x);
		if (it == end(rbt))++rbt[x];
		else {
			vector<int> toerase{ x };
			++it;
			int y = x + 1;
			while (it != rbt.end()) {
				if (it->first == y) {
					++y;
					toerase.pb(it->first);
					++it;
					continue;
				}
				else break;
			}
			++rbt[y];
			for (int& y : toerase)rbt.erase(y);
		}
	}
	vector<int> r;
	auto ptr = rbt.begin();
	while (ptr != rbt.end()) {
		r.pb(ptr->first);
		++ptr;
	}
	/*
	if(print^0){
		Print(r);
	}
	*/
	return r;
}
void Print(const vector<int>& a) {
	for (const int& x : a)cout << x << " ";
	cout << endl;
}
bool IsGood(vector<int>& a, vector<int>& b) {
	//bool print(b==vector<int>{4});
	int n = int(a.size()), m = int(b.size());
	int i = n - 1, j = m - 1;
	while (i >= 0 && j >= 0) {
		if (a[i] < b[j])return true;
		if (a[i] > b[j])return false;
		--i, --j;
	}
	//if(print)cout<<i<<" "<<j<<endl;
	if (j < 0)return false;
	return true;
}
string roadsInHackerland(int n, vector<vector<int>> roads) {
	/*
	 * Write your code here.
	 */
	constexpr int INF = 0x3f3f3f3f;
	if (n == 1)return string(1, '0');
	vector<vector<int>> graph(n, vector<int>(n, INF));
	string res = "";
	for (vector<int>& x : roads) {
		int u = x[0] - 1, v = x[1] - 1, w = x[2];
		if (u == v)continue;
		graph[u][v] = w;
		graph[v][u] = w;
	}
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(1, INF)));
	int i, j, k;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (graph[i][j] != INF) {
				dp[i][j].pop_back();
				dp[i][j].pb(graph[i][j]);
			}
		}
	}
	for (k = 0; k < n; ++k) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				//if(dp[i][k].front()==INF||dp[k][j].front()==INF)continue;
				vector<int> r = Sum(dp[i][k], dp[k][j]);
				if (IsGood(r, dp[i][j])) {
					/*
					if(i==2&&j==3){
						cout<<i<<" "<<j<<" "<<k<<endl;
						Print(dp[i][k]);
						Print(dp[k][j]);
						Print(dp[i][j]);
						Print(r);
					}
					*/
					dp[i][j] = r;
				}
			}
		}
	}
	//cout<<"***********************\n";
	vector<int> r;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			//cout<<i+1<<" "<<j+1<<endl;
			//Print(dp[i][j]);
			r = Sum(dp[i][j], r);
		}
	}
	int valmax = r.back();
	string s(valmax + 1, '0');
	for (int& x : r)s[x] = '1';
	reverse(begin(s), end(s));
	return s;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string nm_temp;
	getline(cin, nm_temp);

	vector<string> nm = split_string(nm_temp);

	int n = stoi(nm[0]);

	int m = stoi(nm[1]);

	vector<vector<int>> roads(m);
	for (int roads_row_itr = 0; roads_row_itr < m; roads_row_itr++) {
		roads[roads_row_itr].resize(3);

		for (int roads_column_itr = 0; roads_column_itr < 3; roads_column_itr++) {
			cin >> roads[roads_row_itr][roads_column_itr];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	string result = roadsInHackerland(n, roads);

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
