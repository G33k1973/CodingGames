#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char ** argv) {
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n, nq;
		sc = scanf("%d %d", &n, &nq);
		int nn = n * n;
		vector<int> arr(nn + 1, 0);
		for (int i = 0; i < nq; ++i) {
			int iu, ju;
			sc = scanf("%d %d ", &iu, &ju);
			int ib, jb;
			sc = scanf("%d %d", &ib, &jb);
			int dw = jb - ju + 1;
			int dh = ib - iu + 1;
			for (int k = 0; k < dh; ++k) {
				int ni = (iu + k) * n + ju;
				++arr[ni];
				--arr[ni + dw];
				//for (int kk = ni; kk < ni + dw; ++kk)++arr[kk];
			}
		}
		int c = 0;
		for (int i = 0; i < nn; ++i) {
			if (i)arr[i] += arr[i - 1];
			printf("%d ", arr[i]);
			++c;
			if (c == n) {
				c = 0;
				printf("\n");
			}
		}
	}
	return 0;
}