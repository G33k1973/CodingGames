class Solution {
protected:
	struct Rectangle {
		int xbl, ybl, xtr, ytr;
		Rectangle() { xbl = ybl = xtr = ytr = INT_MIN; }
		Rectangle(int a, int b, int c, int d) :xbl(a), ybl(b), xtr(c), ytr(d) {}
		bool operator<(const struct Rectangle& obj) const {
			if (xbl == obj.xbl) {
				return ybl < obj.ybl;
			}
			return xbl < obj.xbl;
		}
	};
	static bool comp(const struct Rectangle& a, const struct Rectangle& b) {
		return a < b;
	}
public:
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		vector<Rectangle> arr;
		arr.push_back(Rectangle(rec1[0], rec1[1], rec1[2], rec1[3]));
		arr.push_back(Rectangle(rec2[0], rec2[1], rec2[2], rec2[3]));
		sort(begin(arr), end(arr), Solution::comp);
		if (arr[0].xtr <= arr[1].xbl)return false;
		if (arr[0].ytr <= arr[1].ybl)return false;
		if (arr[0].ybl >= arr[1].ytr)return false;
		return true;
	}
};