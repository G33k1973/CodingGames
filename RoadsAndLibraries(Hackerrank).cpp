#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
#define sc static_cast<ll>
#define pb push_back
vector<string> split_string(string);
void dfs(vector<vector<int>>& graph, int src, vector<bool>& visited, int& cnt) {
	visited[src] = true;
	for (int j = 0; j<int(graph[src].size()); ++j) {
		if (!visited[graph[src][j]])dfs(graph, graph[src][j], visited, cnt);
	}
	++cnt;
	return;
}
// Complete the roadsAndLibraries function below.
ll roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>>& cities) {
	if (c_lib < c_road) {
		ll res = sc(n)*sc(c_lib);
		return res;
	}
	vector<vector<int>> graph(n, vector<int>());
	for (int i = 0; i<int(cities.size()); ++i) {
		int u = cities[i][0] - 1;
		int v = cities[i][1] - 1;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	ll res = 0LL;
	vector<bool> visited(n, false);
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			int cnt = 0;
			dfs(graph, i, visited, cnt);
			ll pos1 = sc(cnt)*sc(c_lib);
			ll pos2 = sc(cnt - 1)*sc(c_road) + sc(c_lib);
			res += min(pos1, pos2);
		}
	}
	return res;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int q_itr = 0; q_itr < q; q_itr++) {
		string nmC_libC_road_temp;
		getline(cin, nmC_libC_road_temp);

		vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

		int n = stoi(nmC_libC_road[0]);

		int m = stoi(nmC_libC_road[1]);

		int c_lib = stoi(nmC_libC_road[2]);

		int c_road = stoi(nmC_libC_road[3]);

		vector<vector<int>> cities(m);
		for (int i = 0; i < m; i++) {
			cities[i].resize(2);

			for (int j = 0; j < 2; j++) {
				cin >> cities[i][j];
			}

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		ll result = roadsAndLibraries(n, c_lib, c_road, cities);

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
