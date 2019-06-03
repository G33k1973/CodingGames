#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char ** argv) {
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int m, n, p, q;
		cin >> m >> n >> p >> q;
		int A[m][n];
		int B[p][q];
		int i, j;
		for (i = 0; i < m; ++i) {
			for (j = 0; j < n; ++j) {
				cin >> A[i][j];
			}
		}
		for (i = 0; i < p; ++i) {
			for (j = 0; j < q; ++j) {
				cin >> B[i][j];
			}
		}
		for (i = 0; i < m*p; ++i) {
			for (j = 0; j < q*n; ++j) {
				cout << A[i / p][j / q] * B[i%p][j%q] << "\t";
			}
			cout << endl;
		}
	}
}