class Solution {
public:
	int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		int n = maze.size();
		int m = maze[0].size();
		vector<vector<int>> steps(n, vector<int>(m, INT_MAX));
		queue<pair<int, int>> q;
		q.push(make_pair(start[0], start[1]));
		steps[start[0]][start[1]] = 0;
		int c = 0;
		while (!q.empty()) {
			auto p = q.front(); q.pop();
			int x = p.first, y = p.second;
			//go up;
			c = x;
			while (c >= 0 && !maze[c][y]) c--;
			if (c + 1 != x && steps[x][y] + x - c - 1 < steps[c + 1][y]) {
				//coords: c + 1, y
				steps[c + 1][y] = steps[x][y] + x - c - 1;
				q.push(make_pair(c + 1, y));
			}
			//go down;
			c = x;
			while (c < n && !maze[c][y]) c++;
			if (c - 1 != x && steps[x][y] + c - 1 - x < steps[c - 1][y]) {
				//coords: c - 1, y
				steps[c - 1][y] = steps[x][y] + c - 1 - x;
				q.push(make_pair(c - 1, y));
			}
			//go left
			c = y;
			while (c >= 0 && !maze[x][c]) c--;
			if (c + 1 != y && steps[x][y] + y - c - 1 < steps[x][c + 1]) {
				//coords: x, c + 1
				steps[x][c + 1] = steps[x][y] + y - c - 1;
				q.push(make_pair(x, c + 1));
			}
			// go right
			c = y;
			while (c < m && !maze[x][c]) c++;
			if (c - 1 != y && steps[x][y] + c - 1 - y < steps[x][c - 1]) {
				steps[x][c - 1] = steps[x][y] + c - 1 - y;
				q.push(make_pair(x, c - 1));
			}
		}
		int res = steps[destination[0]][destination[1]];
		return res == INT_MAX ? -1 : res;
	}
};