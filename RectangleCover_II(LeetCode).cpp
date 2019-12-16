using ll = long long int;
#define pb push_back
class Solution {
protected:
	int n;
	struct Rec {
		int xbl, ybl, xur, yur;
		Rec() {}
		Rec(int a, int b, int c, int d) {
			xbl = a, ybl = b, xur = c, yur = d;
		}
		bool operator<(const struct Rec& obj) const {
			if (xbl == obj.xbl) {
				return ybl < obj.ybl;
			}
			return xbl < obj.xbl;
		}
		bool operator==(const struct Rec& obj) const {
			return (xbl == obj.xbl&&ybl == obj.ybl&&xur == obj.xur&&yur == obj.yur);
		}
	};
	static bool comp(const struct Rec& a, const struct Rec& b) {
		return a < b;
	}
	bool overlap(const struct Rec& a, const struct Rec& b) {
		if (a == b)return true;
		if (a.xur <= b.xbl)return false;
		if (a.yur <= b.ybl)return false;
		if (a.ybl >= b.yur)return false;
		if (a.xbl >= b.xur)return false;
		return true;
	}
	int xblmin, yblmin, xurmax, yurmax;
public:
	bool isRectangleCover(vector<vector<int>>& rectangles) {
		n = int(rectangles.size());
		if (n == 0)return false;
		if (n == 1)return true;
		xblmin = INT_MAX, yblmin = INT_MAX, xurmax = INT_MIN, yurmax = INT_MIN;
		vector<struct Rec> arr{};
		ll subarea = 0;
		for (const auto& x : rectangles) {
			Rec a{ x[0],x[1],x[2],x[3] };
			if (xblmin > a.xbl)xblmin = a.xbl;
			if (yblmin > a.ybl)yblmin = a.ybl;
			if (xurmax < a.xur)xurmax = a.xur;
			if (yurmax < a.yur)yurmax = a.yur;
			if (arr.empty() == false) {
				for (auto& x : arr) {
					if (overlap(x, a)) {
						//cout<<"Rectangle 1 : "<<x.xbl<<" "<<x.ybl<<" "<<x.xur<<" "<<x.yur<<endl;
					//cout<<"Rectangle 2 : "<<a.xbl<<" "<<a.ybl<<" "<<a.xur<<" "<<a.yur<<endl;
						return false;
					}
				}
			}
			arr.pb(a);
			subarea += static_cast<ll>(a.xur - a.xbl)*
				static_cast<ll>(a.yur - a.ybl);
		}
		ll totarea = static_cast<ll>(xurmax - xblmin)*static_cast<ll>(yurmax - yblmin);
		totarea -= subarea;
		return totarea == 0;
	}
};