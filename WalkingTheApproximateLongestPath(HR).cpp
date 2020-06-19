#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

unordered_map<int, unordered_set<int>> graph;
vector<int> path;

void dfs(int src, int n, vector<bool>& visited) {
	visited[src] = true;
	path.pb(src + 1);
	pair<int, int> next{ INT_MAX,-1 };
	for (int i = 0; i < n; ++i) {
		if (visited[i])continue;
		if (graph[i].count(src) && graph[i].size() < next.first)next = mp(graph[i].size(), i);
	}
	if (next.second != -1) {
		graph[src].erase(next.second);
		graph[next.second].erase(src);
		dfs(next.second, n, visited);
	}
	return;
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	std::ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].insert(v);
		graph[v].insert(u);
	}
	vector<bool> visited(n, false);
	//choose root
	pair<int, int> root{ INT_MAX,-1 };//first<-connecting road,second<-node index;
	for (int i = 0; i < n; ++i) {
		if (graph[i].size() < root.first)root = mp(graph[i].size(), i);
	}
	dfs(root.second, n, visited);
	cout << int(path.size()) << endl;
	for (int i = 0; i<int(path.size()); ++i) {
		cout << path[i];
		if (i != (int(path.size()) - 1))cout << " ";
	}
	return 0;
}
