
/*You are required to complete this method*/
int maxArea(int M[MAX][MAX], int n, int m)
{
	//Your code here
	int i, j, u, v;
	int res = 0;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (M[i][j] == 0)continue;
			int rmax = i, cmax = j;
			for (u = i + 1; u < n; ++u) {
				if (M[u][j] == 1)rmax = u;
				else break;
			}
			for (v = j + 1; v < m; ++v) {
				if (M[i][v] == 1)cmax = v;
				else break;
			}
			int wmin = INT_MAX;
			for (u = i; u <= rmax; ++u) {
				v = j;
				int w = 0;
				while (v <= cmax && M[u][v] == 1) {
					++w, ++v;
				}
				wmin = min(w, wmin);
				res = max(res, wmin*(u - i + 1));
			}
		}
	}
	return res;
}
