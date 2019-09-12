#define pb push_back
#define mp make_pair
class Solution {
	int n, m;
	vector<int> sum;
	vector<vector<int>> px, sx;
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		n = (int)matrix.size();
		m = (int)matrix[0].size();
		sum.assign(n, 0);
		px.assign(n, vector<int>(m, 0));
		sx.assign(n, vector<int>(m, 0));
		int i, j, u, v;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				px[i][j] = sum[i];
				sum[i] += matrix[i][j];
			}
		}
		for (i = 0; i < n; ++i) {
			for (j = m - 2; j >= 0; --j) {
				sx[i][j] = sx[i][j + 1] + matrix[i][j + 1];
			}
		}
		int res = INT_MIN;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				vector<vector<int>> memo(n - i + 1, vector<int>(m - j + 1));
				for (u = i; u < n; ++u) {
					for (v = j; v < m; ++v) {
						int sub = sum[u] - px[u][j] - sx[u][v];
						memo[u - i + 1][v - j] += memo[u - i][v - j] + sub;
						if (memo[u - i + 1][v - j] > res&&memo[u - i + 1][v - j] <= k) {
							res = memo[u - i + 1][v - j];
						}
					}
				}
			}
		}
		return res;
	}
};