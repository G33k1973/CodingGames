#include <bits/stdc++.h>

using namespace std;
#define INF 0x3f3f3f3f
using ll = long long int;
#define sc static_cast<ll>
vector<string> split_string(string);



int main()
{
	int road_nodes;
	int road_edges;

	cin >> road_nodes >> road_edges;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	vector<vector<ll>> graph(road_nodes, vector<ll>(road_nodes, INF));
	vector<int> road_from(road_edges);
	vector<int> road_to(road_edges);
	vector<int> road_weight(road_edges);

	for (int i = 0; i < road_edges; i++) {
		cin >> road_from[i] >> road_to[i] >> road_weight[i];
		graph[road_from[i] - 1][road_to[i] - 1] = sc(road_weight[i]);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	vector<vector<ll>> dp(graph);

	for (int i = 0; i < road_nodes; ++i)
		for (int j = 0; j < road_nodes; ++j) {
			if (i == j)dp[i][j] = 0LL;
		}

	int i, j, k;
	for (k = 0; k < road_nodes; ++k) {
		for (i = 0; i < road_nodes; ++i) {
			for (j = 0; j < road_nodes; ++j) {
				if (i != j && (dp[i][k] + dp[k][j]) < dp[i][j])
					dp[i][j] = dp[i][k] + dp[k][j];
			}
		}
	}

	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int q_itr = 0; q_itr < q; q_itr++) {
		string xy_temp;
		getline(cin, xy_temp);

		vector<string> xy = split_string(xy_temp);

		int x = stoi(xy[0]);

		int y = stoi(xy[1]);
		--x, --y;
		ll res = dp[x][y];
		if (res == INF)cout << "-1\n";
		else cout << res << endl;
	}

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
