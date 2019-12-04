// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<bits/stdc++.h>

#define pb push_back

unordered_map<int, list<int>> graph;

int n;/* size of input array */

int Count(int src, int i, int K) {
	int sub = 0;
	int prev = i;
	bool first = true;
	int m = graph[src].back();
	for (auto& x : graph[src]) {
		int j = x;
		if (j > i&&first) {
			if (j - i > K)return sub;
			sub += j - i + 1;
			K -= j - i;
			first = false;
			prev = j;
			continue;
		}
		else if (j == i && first) {
			++sub;
			prev = j;
			first = false;
			continue;
		}
		else {
			if (prev + 1 == j) {
				++sub;
				prev = j;
				continue;
			}
			int distance = j - prev - 1;
			if (distance <= K) {
				K -= distance;
				sub += distance + 1;
				prev = j;
				continue;
			}
			break;
		}
	}
	int left = min(K, n - m - 1);
	return sub + left;
}

int solution(vector<int> &arr, int K) {
	n = static_cast<int>(arr.size());
	if (n == 0)return 0;
	if (n == 1)return 1;
	K = min(n, K);
	int res(K);
	for (int i = 0; i < n; ++i) {
		graph[arr[i]].pb(i);
	}
	for (int i = 0; i < n; ++i) {
		int maxgain = n - i;
		if (maxgain <= res)break;
		for (auto& x : graph) {
			int subres = Count(x.first, i, K);
			res = max(res, subres);
			if (res == maxgain)break;
		}
		graph[arr[i]].pop_front();
		if (graph[arr[i]].empty())graph.erase(arr[i]);
	}
	return res;
}

int main(int argc, char ** argv) {
	vector<int> arr{ 1, 2, 3, 3, 2, 4, 5, 8, 3, 3, 13, 3, 2, 9, 7, 3, };
	int K;
	while (true) {
		std::cout << "Enter a number:\n";
		cin >> K;
		if (K >= 0)break;
	}
	cout << solution(arr, 5);
	return 0;
}