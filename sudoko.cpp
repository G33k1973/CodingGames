#include<bits/stdc++.h>
using namespace std;
unordered_set<int> rows[9], cols[9];
using ip = pair<int, int>;
vector<ip> points;
bool issafe(int i, int j, int x, vector<vector<char>>& A) {
	if (rows[i].count(x) > 0 || cols[j].count(x) > 0)return false;
	int rs = i / 3, cs = j / 3;
	unordered_set<char> h;
	h.insert(x + '0');
	for (int u = rs*3; u < rs*3 + 3; ++u) {
		for (int v = cs*3; v < cs*3 + 3; ++v) {
			if (A[u][v] == '.')continue;
			if (h.count(A[u][v]) > 0)return 0;
			h.insert(A[u][v]);
		}
	}
	return true;
}
bool solve(vector<vector<char>>& A, int n, int c, vector<ip>& points) {
	if (c == n) {
		return true;
	}
	bool ans = false;
	int i = points[c].first, j = points[c].second;
	for (int x = 1; x <= 9; ++x) {
		if (issafe(i, j, x, A)) {
			cout << "trying " << x << endl;
			rows[i].insert(x);
			cols[j].insert(x);
			A[i][j] = x + '0';
			ans = ans || solve(A, n, c + 1, points);
			if (ans == true)return true;
			A[i][j] = '.';
			rows[i].erase(x);
			cols[j].erase(x);
		}
	}
	return ans;
}

void solveSudoku(vector<vector<char> > &A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	for (int i = 0; i < 9; ++i) {
		if (cols[i].size() > 0)cols[i].clear();
		if (rows[i].size() > 0)rows[i].clear();
	}
	if (points.size() > 0)points.clear();
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (A[i][j] == '.') {
				points.push_back(make_pair(i, j));
				continue;
			}
			rows[i].insert(A[i][j] - '0');
			cols[j].insert(A[i][j] - '0');
		}
	}
	solve(A, int(points.size()), 0, points);
}

int main(int argc, char ** argv) {
	vector<vector<char>> A{ {'5','3','.','.','7','.','.','.','.'}, {'6','.','.','1','9','5','.','.','.'}, {'.','9','8','.','.','.','.','6','.'}, 
	{'8','.','.','.','6','.','.','.','3'}, {'4','.','.','8','.','3','.','.','1'}, {'7','.','.','.','2','.','.','.','6'}, {'.','6','.','.','.','.','2','8','.'}, 
	{'.','.','.','4','1','9','.','.','5'}, {'.','.','.','.','8','.','.','7','9'} };
	solveSudoku(A);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j)cout << A[i][j];
		cout << endl;
	}
}
