// you can use includes, for example:
// #include <algorithm>
#include<bits/stdc++.h>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

pair<int, int> Extract(int y) {
	int c2 = 0, c5 = 0;
	if (y == 0)return make_pair(c2, c5);
	while (y % 2 == 0) {
		++c2;
		y /= 2;
	}
	while (y % 5 == 0) {
		++c5;
		y /= 5;
	}
	return make_pair(c2, c5);
}

int solution(vector< vector<int> > &A) {
	// write your code in C++14 (g++ 6.2.0)
	int n = int(A.size());
	if (n == 0)return 0;
	int m = int(A.front().size());
	if (m == 0)return 0;
	vector<vector<int>> p2(n, vector<int>(m, 0));
	vector<vector<int>> p5(n, vector<int>(m, 0));
	unordered_map<int, pair<int, int>> seen;
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			int x = A[i][j];
			if (x == 0)return 1;
			auto it = seen.find(x);
			if (it != end(seen)) {
				p2[i][j] = it->second.first;
				p5[i][j] = it->second.second;
			}
			else {
				pair<int, int> sub = Extract(x);
				p2[i][j] = sub.first;
				p5[i][j] = sub.second;
			}
		}
	}
	if (n == 1 && m == 1) {
		return min(p2[0][0], p5[0][0]);
	}
	vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m, make_pair(0, 0)));
	dp[0][0] = make_pair(p2[0][0], p5[0][0]);
	for (j = 1; j < m; ++j) {
		dp[0][j] = make_pair(dp[0][j - 1].first + p2[0][j], dp[0][j - 1].second + p5[0][j]);
	}
	for (i = 1; i < n; ++i) {
		dp[i][0] = make_pair(dp[i - 1][0].first + p2[i][0], dp[i - 1][0].second + p5[i][0]);
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			int fix2 = p2[i][j], fix5 = p5[i][j];
			int n2up = dp[i - 1][j].first + fix2, n5up = dp[i - 1][j].second + fix5;
			int n2left = dp[i][j - 1].first + fix2, n5left = dp[i][j - 1].second + fix5;
			if (min(n2left, n5left) < min(n2up, n5up)) {
				dp[i][j].first = n2left;
				dp[i][j].second = n5left;
			}
			else {
				dp[i][j].first = n2up;
				dp[i][j].second = n5up;
			}
		}
	}
	return min(dp[n - 1][m - 1].first, dp[n - 1][m - 1].second);
}
