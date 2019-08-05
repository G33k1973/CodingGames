/*This is a function problem.You only need to complete the function given below*/
#define pb push_back
#define mp make_pair
typedef pair<int, int> ip;
bool SubMatrixChecker(int grid[N][N]) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			int r = i * 3, c = j * 3;
			std::unordered_set<int> memo;
			for (int u = r; u < r + 3; ++u) {
				for (int v = c; v < c + 3; ++v) {
					if (memo.count(grid[u][v]) > 0)return 0;
					else {
						memo.insert(grid[u][v]);
					}
				}
			}
		}
	}
	return true;
}
bool SubMatrixChecker2(int grid[N][N], int r, int c, int i, int j, int x) {
	r *= 3, c *= 3;
	for (int u = r; u < r + 3; ++u) {
		for (int v = c; v < c + 3; ++v) {
			if (u == i && v == j)continue;
			if (grid[u][v] == x)return 0;
		}
	}
	return true;
}
bool IsSafe(int grid[N][N], int i, int j, int x) {
	for (int r = 0; r < 9; ++r) {
		if (grid[r][j] == x)return 0;
	}
	for (int c = 0; c < 9; ++c) {
		if (grid[i][c] == x)return 0;
	}
	return SubMatrixChecker2(grid, i / 3, j / 3, i, j, x);
}
bool SolveUtil(int grid[N][N], int c, int i, vector<ip>& arr, bool& res) {
	if (i == c) {
		//if (SubMatrixChecker(grid)) {
		res = 1;
		return true;
		//}
		//return false;
	}
	bool ans = false;
	for (int j = 1; j <= 9; ++j) {
		if (IsSafe(grid, arr[i].first, arr[i].second, j)) {
			grid[arr[i].first][arr[i].second] = j;
			ans = ans || SolveUtil(grid, c, i + 1, arr, res);
			if (res)return 1;
			grid[arr[i].first][arr[i].second] = 0;
		}
	}
	return ans;
}
bool SolveSudoku(int grid[N][N])
{
	// Your code here
	vector<ip> arr;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (grid[i][j] == 0)arr.pb(mp(i, j));
		}
	}
	bool res = false;
	SolveUtil(grid, (int)arr.size(), 0, arr, res);
	return res;
}

void printGrid(int grid[N][N]) {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			printf("%d ", *((*(grid + i)) + j));
		}
	}
}
