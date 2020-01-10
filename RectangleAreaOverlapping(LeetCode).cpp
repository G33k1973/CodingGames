using ll = long long int;
class Solution {
protected:
	struct Rectangle {
		int xl, yl, xu, yu;
		ll area;
		Rectangle() {}
		Rectangle(int a, int b, int c, int d) :xl(a), yl(b), xu(c), yu(d) {
			this->area = static_cast<ll>(c - a)*static_cast<ll>(d - b);
		}
		bool operator<(const struct Rectangle& ob)const {
			if (xl == ob.xl)return yl < ob.yl;
			return xl < ob.xl;
		}
	};
	static bool comp(const struct Rectangle& a, const struct Rectangle& b) {
		return a < b;
	}
	ll overlap(Rectangle& a, Rectangle& b) {
		if (a.xu <= b.xl)return 0;
		if (a.yu <= b.yl)return 0;
		if (a.yl >= b.yu)return 0;
		int X1 = max(a.xl, b.xl);
		int X2 = min(a.xu, b.xu);
		int Y1 = max(a.yl, b.yl);
		int Y2 = min(a.yu, b.yu);
		return static_cast<ll>(abs(X1 - X2))*static_cast<ll>(abs(Y1 - Y2));
	}
public:
	ll computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		Rectangle rec1(A, B, C, D);
		Rectangle rec2(E, F, G, H);
		vector<struct Rectangle> arr;
		arr.push_back(rec1);
		arr.push_back(rec2);
		sort(begin(arr), end(arr), Solution::comp);
		return (arr[0].area + arr[1].area - overlap(arr[0], arr[1]));
	}
};