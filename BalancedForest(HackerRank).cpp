#include <bits/stdc++.h>
#include <limits>

using namespace std;
typedef long long int ll;
vector<string> split_string(string);
#define sc static_cast<ll>
#define ins insert
// Complete the balancedForest function below.
ll dfs(unordered_map<int, unordered_set<int>>& graph, int src, vector<int>& c, unordered_set<int>& visited) {
	visited.ins(src);
	ll cum = 0LL;
	for (const int& x : graph[src]) {
		if (visited.count(x) == 0)
			cum += dfs(graph, x, c, visited);
	}
	return cum + sc(c[src - 1]);
}
ll balancedForest(vector<int> c, vector<vector<int>> edges) {
	int n = int(c.size());
	if (n < 3)return -1LL;
	int m = int(edges.size());
	if (m < 2)return -1LL;
	ll sum(0LL);
	for (int& x : c)
		sum += sc(x);
	unordered_map<int, unordered_set<int>> graph;
	for (vector<int>& x : edges) {
		int u = x.front(), v = x.back();
		graph[u].ins(v);
		graph[v].ins(u);
	}
	int i, j;
	ll res = std::numeric_limits<ll>::max();
	for (i = 0; i < m - 1; ++i) {
		for (j = i; j < m; ++j) {
			int u1 = edges[i][0], v1 = edges[i][1];
			int u2 = edges[j][0], v2 = edges[j][1];
			graph[u1].erase(v1);
			graph[v1].erase(u1);
			graph[u2].erase(v2);
			graph[v2].erase(u2);
			//root at u1 and root at v1
			unordered_set<int> seen;
			ll cost1 = dfs(graph, u1, c, seen);
			seen.clear();
			ll cost2 = dfs(graph, v1, c, seen);
			ll cost3 = sum - cost1 - cost2;
			if (cost1 == cost2) {
				if (cost3 < cost1)res = min(res, cost1 - cost3);
			}
			else if (cost1 == cost3) {
				if (cost2 < cost1)res = min(res, cost1 - cost2);
			}
			else if (cost2 == cost3) {
				if (cost1 < cost2)res = min(res, cost2 - cost1);
			}
			graph[u1].insert(v1);
			graph[v1].insert(u1);
			graph[u2].insert(v2);
			graph[v2].insert(u2);
		}
	}
	return (res == std::numeric_limits<ll>::max()) ? (-1LL) : (res);
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int q_itr = 0; q_itr < q; q_itr++) {
		int n;
		cin >> n;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		string c_temp_temp;
		getline(cin, c_temp_temp);

		vector<string> c_temp = split_string(c_temp_temp);

		vector<int> c(n);

		for (int i = 0; i < n; i++) {
			int c_item = stoi(c_temp[i]);

			c[i] = c_item;
		}

		vector<vector<int>> edges(n - 1);
		for (int i = 0; i < n - 1; i++) {
			edges[i].resize(2);

			for (int j = 0; j < 2; j++) {
				cin >> edges[i][j];
			}

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		ll result = balancedForest(c, edges);

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
