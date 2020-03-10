struct rec {
	int i1, j1, i2, j2;
	rec() {}
	rec(int a, int b, int c, int d) :i1(a), j1(b), i2(c), j2(d) {

	}
	bool operator<(const struct rec& ob) const {
		if (i1 == ob.i1)return j1 < ob.j1;
		return i1 < ob.i1;
	}
};
bool comp(const struct rec& a, const struct rec& b) {
	return a < b;
}
int Overlap(const rec& a, const rec& b) {
	if (a.i2 <= b.i1)return 0;
	if (a.j1 >= b.j2)return 0;
	if (a.j2 <= b.j1)return 0;
	int side1 = min(a.i2, b.i2) - max(a.i1, b.i1);
	int side2 = min(a.j2, b.j2) - max(a.j1, b.j1);
	return side1 * side2;
}
int Solution::solve(int A, int B, int C, int D, int E, int F, int G, int H) {
	rec R1(A, B, C, D);
	rec R2(E, F, G, H);
	vector<rec> arr;
	arr.push_back(R1);
	arr.push_back(R2);
	sort(begin(arr), end(arr), comp);
	return Overlap(arr[0], arr[1]);
}
