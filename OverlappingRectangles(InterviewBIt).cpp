#define pb push_back
struct rectangle {
	int ibl, jbl, iur, jur;
	rectangle(){}
	rectangle(int a,int b,int c,int d):ibl(a),jbl(b),iur(c),jur(d){}
	bool operator<(const struct rectangle& ob) const {
		if (ibl == ob.ibl)return jbl < ob.jbl;
		return ibl < ob.ibl;
	}
};
bool cmp(const struct rectangle& a, const struct rectangle& b) {
	return a < b;
}
bool Overlapping(rectangle& a, rectangle& b) {
	if (a.iur <= b.ibl)return false;
	if (a.jbl >= b.jur)return false;
	if (a.jur <= b.jbl)return false;
	return true;
}
int Solution::solve(int A, int B, int C, int D, int E, int F, int G, int H) {
	rectangle ob1(A, B, C, D);
	rectangle ob2(E, F, G, H);
	if (ob1 < ob2)return Overlapping(ob1, ob2);
	return Overlapping(ob2, ob1);
}
