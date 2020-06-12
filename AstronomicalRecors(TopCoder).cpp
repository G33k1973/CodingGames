#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class AstronomicalRecords {
public:
	int minimalPlanets(vector <int>, vector <int>);
};

int f[55][55];

int AstronomicalRecords::minimalPlanets(vector <int> A, vector <int> B) {
	int n = A.size(), m = B.size();
	int ans = n + m;
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++) {
			for (int i = 0; i <= n; i++)
				for (int j = 0; j <= m; j++) f[i][j] = 0;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++) {
					bool ok = (((long long)A[i - 1] * B[y]) == ((long long)B[j - 1] * A[x]));
					if (ok) f[i][j] = f[i - 1][j - 1] + 1; else
						if (f[i - 1][j] > f[i][j - 1]) f[i][j] = f[i - 1][j];
						else f[i][j] = f[i][j - 1];
				}
			int cur = n + m - f[n][m];
			if (cur < ans) ans = cur;
		}
	return ans;
}