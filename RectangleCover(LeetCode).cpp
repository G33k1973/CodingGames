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
		for (const auto& x : rectangles) {
			Rec a{ x[0],x[1],x[2],x[3] };
			if (xblmin > a.xbl)xblmin = a.xbl;
			if (yblmin > a.ybl)yblmin = a.ybl;
			if (xurmax < a.xur)xurmax = a.xur;
			if (yurmax < a.yur)yurmax = a.yur;
			arr.pb(a);
		}
		sort(begin(arr), end(arr), Solution::comp);
		for (int i = 0; i < (int)arr.size(); ++i) {
			for (int j = i + 1; j < (int)arr.size(); ++j) {
				if (overlap(arr[i], arr[j])) {
					//cout<<"Rectangle 1 : "<<arr[i].xbl<<" "<<arr[i].ybl<<" "<<arr[i].xur<<" "<<arr[i].yur<<endl;
					//cout<<"Rectangle 2 : "<<arr[j].xbl<<" "<<arr[j].ybl<<" "<<arr[j].xur<<" "<<arr[j].yur<<endl;
					return false;
				}
			}
		}
		ll totarea = static_cast<ll>(xurmax - xblmin)*static_cast<ll>(yurmax - yblmin);
		//cout<<totarea<<endl;
		for (const auto& x : arr) {
			ll subarea = static_cast<ll>(x.xur - x.xbl)*
				static_cast<ll>(x.yur - x.ybl);
			totarea -= subarea;
		}
		//cout<<totarea<<endl;
		return totarea == 0;
	}
};