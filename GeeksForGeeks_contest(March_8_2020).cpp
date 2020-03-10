#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
ll update(ll c) {
	return ((c)*(c - 1)*(c - 2)) / 6;
}
int main() {
	//code
	std::ios_base::sync_with_stdio(false);
	int q;
	int sc = scanf("%d", &q);
	while (q-- > 0) {
		int n;
		sc = scanf("%d", &n);
		vector<string> grid(n, string(n, '.'));
		int i = 0, j = 0;
		while (1) {
			char x;
			sc = scanf("%c", &x);
			if (x == '.' || (x >= 65 && x <= 90)) {
				grid[i][j] = x;
				++j;
				if (j == n) {
					++i, j = 0;
					if (i == n)break;
				}
			}
		}
		ll res = 0ULL;
		vector<vector<bool>> horizontal(n, vector<bool>(n, false));
		vector<vector<bool>> vertical(n, vector<bool>(n, false));
		vector<vector<bool>> diagonal(n, vector<bool>(n, false));
		vector<vector<bool>> antidiagonal(n, vector<bool>(n, false));
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				if (isalpha(grid[i][j])) {
					if (!horizontal[i][j]) {
						horizontal[i][j] = 1;
						ll c = 1;
						int row = i, col = j + 1;
						while (col < n) {
							if (isalpha(grid[row][col])) {
								horizontal[row][col] = true;
								++c;
							}
							++col;
						}
						if (c >= 3)res += update(c);
					}
					if (!vertical[i][j]) {
						vertical[i][j] = 1;
						ll c = 1;
						int row = i + 1, col = j;
						while (row < n) {
							if (isalpha(grid[row][col])) {
								vertical[row][col] = true;
								++c;
							}
							++row;
						}
						if (c >= 3)res += update(c);
					}
					if (!diagonal[i][j]) {
						ll c = 1;
						int row = i - 1, col = j + 1;
						while (row >= 0 && col < n) {
							if (isalpha(grid[row][col])) {
								diagonal[row][col] = true;
								++c;
							}
							--row, ++col;
						}
						row = i + 1, col = j - 1;
						while (row < n&&col >= 0) {
							if (isalpha(grid[row][col])) {
								diagonal[row][col] = true;
								++c;
							}
							++row, --col;
						}
						if (c >= 3)res += update(c);
					}
					if (!antidiagonal[i][j]) {
						ll c = 1;
						int row = i - 1, col = j - 1;
						while (row >= 0 && col >= 0) {
							if (isalpha(grid[row][col])) {
								antidiagonal[row][col] = true;
								++c;
							}
							--row, --col;
						}
						row = i + 1, col = j + 1;
						while (row < n&&col < n) {
							if (isalpha(grid[row][col])) {
								antidiagonal[row][col] = true;
								++c;
							}
							++row, ++col;
						}
						if (c >= 3)res += update(c);
					}
				}
			}
		}
		printf("%llu\n", res);
	}
	return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q-- > 0) {
		int n;
		sc = scanf("%d", &n);
		vector<int> arr(n, 0);
		for (int& x : arr)sc = scanf("%d", &x);
		vector<int> tours(n, 0);
		int res = -1;
		bool found = false;
		for (int i = 0; i < n; ++i) {
			int delta = arr[i] - i;
			if (delta <= 0) {
				res = i + 1;
				break;
			}
			int rem = delta % n;
			int dv = delta / n;
			if (rem == 0) {
				tours[i] = dv;
			}
			else {
				tours[i] = dv + 1;
			}
		}
		if (found) {
			printf("%d\n", res);
			continue;
		}
		pair<int, int> ans(INT_MAX, -1);
		for (int i = 0; i < n; ++i) {
			if (tours[i] < ans.first) {
				ans = make_pair(tours[i], i + 1);
			}
		}
		res = ans.second;
		printf("%d\n", res);
	}
	return 0;
}