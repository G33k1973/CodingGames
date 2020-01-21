void FillIn(vector<vector<int>>& grid, int n, int i, int j) {
	int row = i, col = j;
	++grid[row][col];
	row = i - 1, col = j;
	while (row >= 0) {
		++grid[row][col];
		--row;
	}
	row = i + 1, col = j;
	while (row < n) {
		++grid[row][col];
		++row;
	}
	row = i, col = j - 1;
	while (col >= 0) {
		++grid[row][col];
		--col;
	}
	row = i, col = j + 1;
	while (col < n) {
		++grid[row][col];
		++col;
	}
	row = i - 1, col = j - 1;
	while (row >= 0 && col >= 0) {
		++grid[row][col];
		--col, --row;
	}
	row = i - 1, col = j + 1;
	while (row >= 0 && col < n) {
		++grid[row][col];
		++col, --row;
	}
	row = i + 1, col = j - 1;
	while (row < n&&col >= 0) {
		++grid[row][col];
		--col, ++row;
	}
	row = i + 1, col = j + 1;
	while (row < n&&col < n) {
		++grid[row][col];
		++col, ++row;
	}
}
void VoidIn(vector<vector<int>>& grid, int n, int i, int j) {
	int row = i, col = j;
	--grid[row][col];
	row = i - 1, col = j;
	while (row >= 0) {
		--grid[row][col];
		--row;
	}
	row = i + 1, col = j;
	while (row < n) {
		--grid[row][col];
		++row;
	}
	row = i, col = j - 1;
	while (col >= 0) {
		--grid[row][col];
		--col;
	}
	row = i, col = j + 1;
	while (col < n) {
		--grid[row][col];
		++col;
	}
	row = i - 1, col = j - 1;
	while (row >= 0 && col >= 0) {
		--grid[row][col];
		--col, --row;
	}
	row = i - 1, col = j + 1;
	while (row >= 0 && col < n) {
		--grid[row][col];
		++col, --row;
	}
	row = i + 1, col = j - 1;
	while (row < n&&col >= 0) {
		--grid[row][col];
		--col, ++row;
	}
	row = i + 1, col = j + 1;
	while (row < n&&col < n) {
		--grid[row][col];
		++col, ++row;
	}
}
int X[8] = { 1,1,1,0,0,-1,-1,-1 };
int Y[8] = { -1,0,+1,-1,+1,-1,0,+1 };
bool IsValid(int i, int j, int n) {
	return (i >= 0 && j >= 0 && i < n&&j < n);
}
vector<int> Solution::solve(int A, vector<vector<int> > &B, vector<vector<int> > &C) {
	vector<int> sol;
	if (A == 0)return sol;
	vector<vector<bool>> lamps(A, vector<bool>(A, false));
	vector<vector<int>> grid(A, vector<int>(A, 0));
	int i, j, totlamps = 0;
	for (const vector<int>& i : B) {
		int x = i.front(), y = i.back();
		assert(x >= 0 && x < A&&y >= 0 && y < A);
		if (lamps[x][y] == false) {
			lamps[x][y] = true;
			FillIn(grid, A, x, y);
			++totlamps;
		}
	}
	for (const vector<int>& i : C) {
		int x = i.front(), y = i.back();
		if (totlamps == 0) {
			sol.push_back(0);
			continue;
		}
		if (grid[x][y] > 0)sol.push_back(1);
		else sol.push_back(0);
		if (lamps[x][y]) {
			lamps[x][y] = false;
			--totlamps;
			VoidIn(grid, A, x, y);
		}
		for (j = 0; j < 8; ++j) {
			int u = x + X[j], v = y + Y[j];
			if (IsValid(u, v, A) && lamps[u][v]) {
				lamps[u][v] = false;
				--totlamps;
				VoidIn(grid, A, u, v);
			}
		}
	}
	return sol;
}
