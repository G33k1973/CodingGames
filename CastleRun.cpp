#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void dfs(const std::vector<std::vector<int>>& graph, int src, vector<bool>& visited) {
	visited.at(src) = true;
	int j = 0;
	for (auto ptr = begin(graph[src]); ptr != end(graph[src]); ++ptr) {
		if (*ptr == 1 && !visited.at(j)) {
			dfs(graph, j, visited);
		}
		++j;
	}
	return;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<vector<int>> g(n, vector<int>(n, 0));
		int i, j;
		bool con = true;
		for (i = 0; i < n; ++i) {
			int c = 0;
			for (j = 0; j < n; ++j) {
				cin >> g.at(i).at(j);
				if (g[i][j])++c;
			}
			if (con == true && c == 0)con = !con;
		}
		if (n == 1) {
			cout << "True\n";
			continue;
		}
		if (con ^ 1) {
			cout << "False\n";
			continue;
		}
		vector<bool> visited(n, false);
		dfs(g, 0, visited);
		for (i = 0; i < n; ++i) {
			if (!visited.at(i))break;
		}
		if (i != n) {
			cout << "False\n";
			continue;
		}
		int odd = 0;
		for (i = 0; i < n; ++i) {
			int c = 0;
			for (j = 0; j < n; ++j) {
				if (g[i][j] > 0)++c;
			}
			if (c & 1)++odd;
		}
		//cout<<odd<<endl;
		if (odd > 2) {
			cout << "False\n";
			continue;
		}
		//cout<<"True\n";
		if (odd == 0)cout << "True\n";
		else cout << "False\n";
	}
	return 0;
}