#include <stdio.h>

int main() {
	int n, k;


	long long int dp[1001][1001];

	dp[0][0] = 1;
	dp[0][1] = 2;
	dp[0][2] = 3;
	for (n = 3; n <= 1000; n++) {
		dp[0][n] = (dp[0][n - 1] % 1000000007 + dp[0][n - 2] % 1000000007) % 1000000007;
	}

	for (k = 1; k <= 1000; k++) {
		for (n = 0; n <= 1000; n++) {
			if (k >= n)
				dp[k][n] = 0;
			else
				dp[k][n] = (dp[k][n - 1] % 1000000007 + dp[k - 1][n - 1] % 1000000007 + dp[k][n - 2] % 1000000007 - dp[k - 1][n - 2] % 1000000007 + 1000000007) % 1000000007;
		}
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		printf("%lld\n", dp[k][n] % 1000000007);
	}
	return 0;
}