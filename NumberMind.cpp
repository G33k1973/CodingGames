#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <cstring>
#define pb push_back
int A[12];
vector<pair<string, int>> acpy;
bool issafe(vector<pair<string, int>>& a,
	int i, int d, int n, vector<int>& b) {
	int j, k;
	for (j = 0; j < n; ++j) {
		string s = a[j].first;
		int c = a[j].second;
		int x = s[i] - '0';
		if (x == d) {
			if (c == 0)return false;
			--c;
			b.pb(j);
		}
	}
	return 1;
}
bool IsMatch(vector<pair<string, int>>& a, int n) {
	int i = 0;
	while (i < n) {
		string s = acpy[i].first;
		int c = a[i].second;
		if (c > 0)return 0;
		int cc = acpy[i].second;
		int j = 0;
		int temp = 0;
		for (auto& x : s) {
			int y = x - '0';
			if (y == A[j++])++temp;
		}
		if (temp != cc)return false;
		++i;
	}
	return true;
}
bool finished = false;
bool solveUtil(
	vector<pair<string, int>>& a,
	int i, int n) {
	if (finished)return finished;
	if (i == 12) {
		if (IsMatch(a, n)) {
			for (int i = 0; i < 12; ++i)
				cout << A[i];
			finished = !finished;
			return true;
		}
		else
			return false;
	}
	int j;
	bool ans = false;
	for (j = 0; j <= 9; ++j) {
		vector<int> temp;
		if (issafe(a, i, j, n, temp)) {
			for (auto& x : temp)
				a[x].second--;
			A[i] = j;
			ans = ans ||
				solveUtil(a, i + 1, n);
			if (!ans) {
				for (auto& x : temp)
					a[x].second++;
			}
		}
	}
	return ans;
}
void solve(vector<pair<string, int>>& a, int n) {
	int i = 0;
	solveUtil(a, i, n);
}
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	cin >> n;
	vector<pair<string, int>> a;
	int i = 0;
	while (i < n) {
		string s("");
		int c(0);
		cin >> s >> c;
		a.pb({ s,c });
		++i;
	}
	acpy = a;
	memset(A, 0, sizeof(A));
	solve(a, n);
	return 0;
}
