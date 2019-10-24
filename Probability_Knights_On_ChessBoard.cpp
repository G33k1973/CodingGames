class Solution {
public:
	double knightProbability(int N, int K, int r, int c) {

		if (N <= 2) {
			if (K == 0)
				return 1;
			else
				return 0;
		}
		vector<vector<double>>dp(N, vector<double>(N, 1));

		vector<vector<int>>drs{ {-2,-1},{-2,1},{2,-1},{2,1},
							   {-1,-2},{-1,2},{1,-2},{1,2} };
		int x, y;
		for (int k = 0; k < K; ++k)
		{
			vector<vector<double>>aux(N, vector<double>(N, 0));
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					for (int d = 0; d < 8; d++)
					{
						x = i + drs[d][0];
						y = j + drs[d][1];
						if (x < 0 || x >= N || y < 0 || y >= N)
							continue;

						aux[i][j] += dp[x][y];
					}
				}
			}
			dp = aux;
		}
		double res = dp[r][c] / pow(8, K);
		return res;

	}
};