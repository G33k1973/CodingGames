#include <iostream>
using namespace std;
long long fact[21];
void func()
{
	fact[0] = 1;
	for (int i = 1; i <= 20; ++i)
	{
		fact[i] = fact[i - 1] * i;
	}
}
int main() {
	int t, n, r, g, b;
	func();
	cin >> t;
	while (t--)
	{
		long long ans = 0;
		cin >> n >> r >> g >> b;
		int left = n - (r + g + b);
		for (int i = 0; i <= left; ++i)
		{
			for (int j = 0; j <= left; ++j)
			{
				int k = left - (i + j);
				if (k >= 0)
				{
					int R = r + i;
					int G = g + j;
					int B = b + k;
					ans += (fact[n] / (fact[R] * fact[G] * fact[B]));
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}