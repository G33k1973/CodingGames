#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef pair<int, int> ip;
typedef pair<ip, int> iip;
typedef pair<ip, ip> iiip;
std::unordered_map<int, unordered_map<int, unordered_map<int, set<int>>>> dp;  //ip:edges,weight
std::unordered_map<int, unordered_map<int, set<int>>> graph;
int n;
void build(const std::unordered_set<int>& h) {
	for (const auto& x : h) {
		int src = x;
		std::queue<iiip> pile;
		pile.push({ {src,0},{-1,0} });//first->first->node,first->second->edges,second->cost
		while (!pile.empty()) {
			int sz = (int)pile.size();
			int i = 0;
			while (i < sz) {
				iiip temp = pile.front();
				pile.pop();
				int u = temp.first.first;
				int e = temp.first.second;
				int w = temp.second.first;
				int tcost = temp.second.second;
				auto it = graph.find(u);
				if (it != end(graph)) {
					unordered_map<int, set<int>> htemp = it->second;
					for (auto& y : htemp) {
						int v = y.first;
						//if(visited.at(v)==0){
						auto it2 = htemp[v].upper_bound(w);
						if (it2 != end(htemp[v])) {
							int tw = tcost + (*it2);
							dp[src][v][e + 1].insert(tw);
							pile.push({ {v,e + 1},{*it2,tw} });
							//visited.at(v)=1;
						}
						//}
					}
				}
				++i;
			}
		}
	}
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int q;
	int sc = scanf("%d", &q);
	while (q-- > 0) {
		int e, t;
		sc = scanf("%d %d %d", &n, &e, &t);
		if (dp.size() > 0)dp.clear();
		if (graph.size() > 0)graph.clear();
		for (int i = 0; i < e; ++i) {
			int u, v, w;
			sc = scanf("%d %d %d", &u, &v, &w);
			--u, --v;
			graph[u][v].insert(w);
		}
		vector<iip> tests;
		std::unordered_set<int> h;
		while (t-- > 0) {
			int src, dst, k;
			sc = scanf("%d %d %d", &src, &dst, &k);
			--src, --dst;
			tests.pb({ {src,dst},k });
			if (h.count(src) == 0)h.insert(src);
		}
		build(h);
		for (const auto& x : tests) {
			int src = x.first.first;
			int dst = x.first.second;
			int w = x.second;
			auto it = dp.find(src);
			unordered_map<int, unordered_map<int, set<int>>> temp = it->second;
			auto it2 = temp.find(dst);
			if (it2 == end(temp)) {
				printf("-1\n");
				continue;
			}
			unordered_map<int, set<int>> local = it2->second;
			auto it3 = local.find(w);
			if (it3 == end(local)) {
				printf("-1\n");
				continue;
			}
			int cost = *it3->second.begin();
			printf("%d\n", cost);
		}
	}
	return 0;
}
