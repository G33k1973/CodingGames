#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void solve(int n) {
	int m = 2 * n - 1;
	int arr[m];
	for (int i = 0; i < m; ++i)arr[i] = n;
	int c = m;
	int mv = 0;
	int reversed = 0;
	int last;
	while (c-- > 0) {
		for (int i = 0; i < mv; ++i)printf("%d ", arr[i]);
		for (int i = mv; i < m - mv; ++i)printf("%d ", arr[i]);
		for (int i = m - mv; i < m; ++i)printf("%d ", arr[i]);
		printf("\n");
		if (!reversed)last = arr[mv];
		if (!reversed&&mv < n - 1) {
			++mv;
			for (int i = mv; i < m - mv; ++i)arr[i] = last - 1;
		}
		else {
			if (!reversed) {
				reversed = 1;
				last = arr[(m) / 2] + 1;
				mv = 0;
			}
			for (int i = (m) / 2 - mv; i <= (m) / 2 + mv; ++i)arr[i] = last;
			++last;
			++mv;
		}
	}
}

int main()
{

	int n;
	scanf("%d", &n);
	// Complete the code to print the pattern.
	solve(n);
	return 0;
}