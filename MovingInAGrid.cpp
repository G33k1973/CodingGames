#include <cstdio>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int r, c;
		scanf("%d%d", &c, &r);
		r = (r - 1) & 3;
		c = (c - 1) % 7;
		printf("%s\n", r == c ? "ARYA" : "JON");
	}
	return 0;
}
