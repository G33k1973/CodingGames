#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Order {
	int index, freq;
	Order() {
		this->index = this->freq = -1;
	}
	Order(int a, int b) {
		this->index = a;
		this->freq = b;
	}
	bool operator>(Order& obj) {
		if (this->freq == obj.freq)return this->index < obj.index;
		return (this->freq > obj.freq);
	}
};
bool cmp(Order& a, Order& b) {
	return a.operator>(b);
}
int main() {
	//code
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n, op;
		sc = scanf("%d %d", &n, &op);
		int nu = n, nr = 0, nt = 0;
		vector<int> u(n, 1), r(n, 0), t(n, 0);
		for (int i = 0; i < op; ++i) {
			int a, b;
			sc = scanf("%d %d", &a, &b);
			if (a == 1) {
				u[b - 1] = 0;
				++nr;
				r[b - 1] = nr;
			}
			else if (a == 2) {
				r[b - 1] = 0;
				++nt;
				t[b - 1] = nt;
			}
			else if (a == 3) {
				u[b - 1] = 0;
				++t;
				t[b - 1] = t;
			}
			else if (a == 4) {
				t[b - 1] = 0;
				++nr;
				r[b - 1] = nr;
			}
		}
		vector<Order> Read, Unread, Thrash;
		for (int i = 0; i < n; ++i) {
			if (u[i] > 0) {
				Unread.push_back({ i + 1,u[i] });
			}
			if (r[i] > 0) {
				Read.push_back({ i + 1,r[i] });
			}
			if (t[i] > 0) {
				Thrash.push_back({ i + 1,t[i] });
			}
		}
		if (Unread.empty()) {
			printf("EMPTY\n");
		}
		else {
			sort(begin(Unread), end(Unread), cmp);
			for (auto& x : Unread) {
				printf("%d ", x.index);
			}
			printf("\n");
		}
		if (Read.empty()) {
			printf("EMPTY\n");
		}
		else {
			sort(begin(Read), end(Read), cmp);
			for (auto& x : Read) {
				printf("%d ", x.index);
			}
			printf("\n");
		}
		if (Thrash.empty()) {
			printf("EMPTY\n");
		}
		else {
			sort(begin(Thrash), end(Thrash), cmp);
			for (auto& x : Thrash) {
				printf("%d ", x.index);
			}
			printf("\n");
		}
	}
	return 0;
}