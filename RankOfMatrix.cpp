#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const double EPS = 1E-9;

int compute_rank(vector<vector<int>>& A) {
	int n = A.size();
	int m = A[0].size();

	int rank = max(n, m);
	vector<bool> row_selected(n, false);
	for (int i = 0; i < m; ++i) {
		int j;
		for (j = 0; j < n; ++j) {
			if (!row_selected[j] && abs(A[j][i]) > EPS)
				break;
		}

		if (j == n) {
			--rank;
		}
		else {
			row_selected[j] = true;
			for (int p = i + 1; p < m; ++p)
				A[j][p] /= A[j][i];
			for (int k = 0; k < n; ++k) {
				if (k != j && abs(A[k][i]) > EPS) {
					for (int p = i + 1; p < m; ++p)
						A[k][p] -= A[j][p] * A[k][i];
				}
			}
		}
	}
	return rank;
}
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		vector<vector<int>> mx(3, vector<int>(3, 0));
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				cin >> mx[i][j];
			}
		}
		cout << compute_rank(mx) << endl;
	}
	return 0;
}