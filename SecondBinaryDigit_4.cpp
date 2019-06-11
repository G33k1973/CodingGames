#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int chi(int p, int q) {
	int p0 = p, a = 1, b = 0;
	while (q) {
		int k = p / q;
		swap(p -= k * q, q);
		swap(a -= k * b, b);
	}
	return 1 - a * p0;
}

vector<int> a, c;
int p, b1, b2, ans;

void put(int k, int s) {
	if (k == a.size()) {
		ans += b1;
		s %= p;
		if (s < 0) s += p;
		if (s <= b2) ++ans;
		return;
	}
	put(k + 1, s + c[k]);
	if (a[k] > 2) put(k + 1, s - c[k]);
	if (~a[k] & 1 && a[k] >= 8) {
		int t = c[k] * ((a[k] >> 1) + 1);
		put(k + 1, s + t);
		put(k + 1, s - t);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int b;
		scanf("%d%d", &b, &p);
		if (p == 1) {
			printf("0\n");
			continue;
		}
		int n = p;
		for (int i = 2; i * i <= n; ++i) if (!(n % i)) {
			int k = 1;
			while (!(n % i)) { k *= i; n /= i; }
			a.emplace_back(k);
		}
		if (n > 1) a.emplace_back(n);
		b1 = b / p;
		b2 = b % p;
		ans = 0;
		c.resize(a.size());
		for (int i = 0; i < a.size(); ++i) c[i] = chi(a[i], p / a[i]);
		put(0, 0);
		printf("%d\n", ans);
		a.clear();
	}
	return 0;
}
