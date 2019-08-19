class Solution {
public:
	vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
		int nA = (int)A.size();
		int mA = (int)A[0].size();
		int nB = (int)B.size();
		int mB = (int)B[0].size();
		assert(mA == nB);
		vector<vector<int>> C(nA, vector<int>(mB, 0));
		int i, j;
		for (i = 0; i < nA; ++i) {
			for (int j = 0; j < mB; ++j) {
				int sub = 0;
				for (int u = 0; u < mA; ++u) {
					sub += A[i][u] * B[u][j];
				}
				C[i][j] = sub;
			}
		}
		return C;
	}
};