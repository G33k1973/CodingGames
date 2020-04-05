class Solution {
public:
	bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
		auto inside = [&](int x, int y) {
			return abs(x - xc) * abs(x - xc) + abs(y - yc) * abs(y - yc) <= r * r; };
		if (x1 <= xc && xc <= x2 && y1 <= yc && yc <= y2)
			return true;
		for (auto x = x1; x <= x2; ++x) {
			if (inside(x, y1) || inside(x, y2))
				return true;
		}
		for (auto y = y1; y <= y2; ++y) {
			if (inside(x1, y) || inside(x2, y))
				return true;
		}
		return false;
	}
};