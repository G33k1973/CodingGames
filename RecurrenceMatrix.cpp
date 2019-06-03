#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
unsigned int dp[maxn];
int mat[1005][1005], cmat[1005][1005];

void init() {
	dp[0] = 1, dp[1] = 0, dp[2] = 1, dp[3] = 0, dp[4] = 0, dp[5] = 1, dp[6] = 1;
	/*
	   for(int i=4;i<maxn;i++){
		   dp[i]=(3*dp[i-1]+4*dp[i-2]+5*dp[i-3]+6*dp[i-4])%2;
	   }

	   for(int i=0;i<50;i++){
		   cout<<dp[i]<<" ";
	   }
	   */

	for (int i = 1; i < 1001; i++) {
		for (int j = 1; j < 1001; j++) {
			long long num = 1ll * i*i*i*j*j*j;
			num %= 7;
			mat[i][j] = dp[num];
		}
	}



	for (int i = 1; i < 1001; i++) {
		for (int j = 1; j < 1001; j++) {
			cmat[i][j] = cmat[i - 1][j] + cmat[i][j - 1] - cmat[i - 1][j - 1] + mat[i][j];
		}
	}

}


int main()
{
	int nt;
	cin >> nt;
	init();
	while (nt--) {
		int n;
		cin >> n;
		cout << cmat[n][n] << endl;
	}
	return 0;
}