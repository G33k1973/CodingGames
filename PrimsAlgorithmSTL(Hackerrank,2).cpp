#include <bits/stdc++.h>
#include <queue>

using namespace std;

vector<string> split_string(string);
using ll = long long int;
#define sc static_cast<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
// Complete the prims function below.
ll prims(int n, vector<vector<int>> edges, int start) {
	if (n < 2)return 0;
	using ip = pair<int, int>;
	unordered_map<int, unordered_map<int, int>> memo;
	std::list<ip> * adj = new list<ip>[n]();
	ll res = 0LL;
	for (vector<int>& x : edges) {
		int u = x[0] - 1, v = x[1] - 1, w = x.back();
		if (u == v)continue;
		auto it = memo.find(u);
		if (it != end(memo)) {
			auto it2 = it->second.find(v);
			if (it2 != end(it->second)) {
				if (it2->second > w) {
					it2->second = w;
				}
				continue;
			}
		}
		memo[u][v] = w;
		memo[v][u] = w;
	}
	for (std::pair<const int, unordered_map<int, int>>& x : memo) {
		for (std::pair<const int, int>& y : x.second) {
			int u = x.first, v = y.first, w = y.second;
			(*(adj + u)).pb(mp(v, w));
			(*(adj + v)).pb(mp(u, w));
		}
	}
	std::vector<bool> inMST(n, false);
	vector<ll> key(n, INF);
	//pickup node 0 as source
	using pq = std::priority_queue<ip, vector<ip>, greater<ip>>;
	pq pile;
	pile.push(mp(0, 0));
	key.operator[](0) = 0;
	while (!pile.empty()) {
		int node = pile.top().second;
		pile.pop();
		inMST.at(node) = true;
		for (std::list<ip>::const_iterator ptr = adj[node].begin(); ptr != adj[node].end(); ++ptr) {
			if (inMST.at(ptr->first) == false && key[ptr->first] > ptr->second) {
				pile.push(mp(ptr->second, ptr->first));
				key[ptr->first] = ptr->second;
			}
		}
	}
	for (const int& x : key) {
		res += sc(x);
	}
	return res;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string nm_temp;
	getline(cin, nm_temp);

	vector<string> nm = split_string(nm_temp);

	int n = stoi(nm[0]);

	int m = stoi(nm[1]);

	vector<vector<int>> edges(m);
	for (int i = 0; i < m; i++) {
		edges[i].resize(3);

		for (int j = 0; j < 3; j++) {
			cin >> edges[i][j];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int start;
	cin >> start;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	ll result = prims(n, edges, start);

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
