const array<int, 4> di{ 0, 1, 1, -1 }; // right, down, right-down, right-up
const array<int, 4> dj{ 1, 0, 1, 1 };

class Solution {
public:
	int longestLine(const vector<vector<int>>& mat) {
		if (mat.empty() || mat[0].empty()) return 0;
		const int N = mat.size();
		const int M = mat[0].size();
		int global_max = 0;
		vector<vector<int>> mem(N, vector<int>(M));
		for (int d = 0; d < 4; ++d) {
			for (auto& v : mem) {
				fill(v.begin(), v.end(), -1);
			}
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					int clen = consecutive_len(mat, mem, i, j, d);
					global_max = max(global_max, clen);
				}
			}
		}
		return global_max;
	}

	int consecutive_len(const vector<vector<int>>& mat, vector<vector<int>>& mem, int i, int j, int dir) {
		const int N = mat.size();
		const int M = mat[0].size();
		if (i < 0 || i >= N || j < 0 || j >= M) return 0;
		int& result = mem[i][j];
		if (result != -1) return result;
		if (mat[i][j] == 0) {
			result = 0;
			return result;
		}
		else {
			int ni = i + di[dir];
			int nj = j + dj[dir];
			result = consecutive_len(mat, mem, ni, nj, dir) + 1;
			return result;
		}

	}
};