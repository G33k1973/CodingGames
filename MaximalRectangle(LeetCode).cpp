vector<bool> ditch;
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int n = int(matrix.size());
		if (!n)return 0;
		int m = int(matrix.front().size());
		if (!m)return 0;
		int res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (matrix[i][j] == '0')continue;
				int u, v;
				ditch.assign(n - i, false);
				for (v = j; v < m; ++v) {
					int sub = 0;
					for (u = i; u < n; ++u) {
						if (ditch[u])break;
						if (matrix[u][v] != '1') {
							ditch[u] = true;
							break;
						}
						sub = (v - j + 1)*(u - i + 1);
						res = max(res, sub);
						//cout<<res<<endl;
					}
				}
			}
		}
		return res;
	}
};