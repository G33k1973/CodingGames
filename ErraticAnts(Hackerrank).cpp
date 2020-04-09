#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
using sp = std::pair<string, int>;
#define mp make_pair
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	std::ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q-- > 0) {
		int steps;
		cin >> steps;
		int res = steps;
		pair<int, int> origin{ 0,0 };
		unordered_map<string, unordered_set<string>> graph;
		string src = to_string(origin.first) + " " + to_string(origin.second);
		string start = src;
		string dest = "";
		while (steps-- > 0) {
			char x;
			cin >> x;
			if (x == 'N')++origin.first;
			else if (x == 'S')--origin.first;
			else if (x == 'W')++origin.second;
			else if (x == 'E')--origin.second;
			dest = to_string(origin.first) + " " + to_string(origin.second);
			graph[src].insert(dest);
			graph[dest].insert(src);
			src = dest;
		}
		unordered_set<string> seen;
		seen.insert(start);
		std::queue<sp> p;
		bool out = false;
		p.push(mp(start, 0));
		while (!p.empty()) {
			int sz = p.size();
			int u = 0;
			while (u < sz) {
				sp current = p.front();
				p.pop();
				string os = current.first;
				int w = current.second;
				if (os == dest) {
					out = true;
					res = w;
					break;
				}
				for (const string& x : graph[os]) {
					if (seen.count(x) == 0) {
						seen.insert(x);
						p.push(mp(x, w + 1));
					}
				}
				++u;
			}
			if (out)break;
		}
		cout << res << endl;
	}
	return 0;
}
