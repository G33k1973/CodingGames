/*  Convex Hull of Points */
#include<bits/stdc++.h>
using namespace std;

#define pb push_back

struct Point {
	int x, y;
	Point() {
		x = y = INT_MIN;
	}
	Point(int a, int b) :x(a), y(b) {}
	static bool CounterClockWise(const struct Point& a, const struct Point& b, const struct Point& c) {
		int diffSlopes = (b.y - a.y)*(c.x - b.x) - (b.x - a.x)*(c.y - b.y);
		return diffSlopes < 0;
	}
	bool operator<(const struct Point& obj) const {
		if (x == obj.x)return (y < obj.y);
		return x < obj.x;
	}
};

bool cmp(const struct Point& a, const struct Point& b) {
	return a.operator<(b);
}

void Solve(const std::vector<Point>& arr, int n) {
	if (n < 3) {
		printf("-1\n");
		return;
	}
	int leftmostpoint = 0, p, q;
	for (int i = 0; i < n; ++i) {
		if (arr[leftmostpoint].x > arr[i].x)leftmostpoint = i;
	}
	p = leftmostpoint;
	vector<Point> ConvexHull;
	do {
		ConvexHull.pb(arr[p]);
		q = (p + 1) % n;
		for (int i = 0; i < n; ++i) {
			if (Point::CounterClockWise(arr[p], arr[q], arr[i]))
				q = i;
		}
		p = q;
	} while (p != leftmostpoint);
	int m = (int)ConvexHull.size();
	if (m < 3) {
		printf("-1\n");
		return;
	}
	sort(begin(ConvexHull), end(ConvexHull), cmp);
	for (int i = 0; i < m; ++i) {
		printf("%d %d", ConvexHull[i].x, ConvexHull[i].y);
		if (i != (m - 1))printf(", ");
	}
	printf("\n");
	return;
}


int main() {
	int q;
	int sc = scanf("%d", &q);
	while (q--) {
		int n;
		sc = scanf("%d", &n);
		vector<Point> arr;
		map<vector<int>, int> seen;
		for (int i = 0; i < n; ++i) {
			int x, y;
			sc = scanf("%d %d", &x, &y);
			vector<int> current{ x,y };
			auto it = seen.find(current);
			if (it == end(seen)) {
				Point temp{ x,y };
				arr.pb(temp);
				++seen[current];
			}
		}
		Solve(arr, n);
	}
	return 0;
}