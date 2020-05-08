class Solution {
public:
	bool checkStraightLine(vector<vector<int>>& coordinates) {
		int n = int(coordinates.size());
		if (n < 3)return true;
		int x0 = coordinates[0][0], y0 = coordinates[0][1];
		int x1 = coordinates[1][0], y1 = coordinates[1][1];
		if (x0 == x1) {
			/*vertical check*/
			for (int i = 2; i < n; ++i) {
				if (coordinates[i][0] != x0)return false;
			}
			return true;
		}
		else if (y0 == y1) {
			/*horizontal check*/
			for (int i = 2; i < n; ++i) {
				if (coordinates[i][1] != y0)return false;
			}
			return true;
		}
		int DY = y1 - y0, DX = x1 - x0;
		for (int i = 2; i < n; ++i) {
			int DY2 = coordinates[i][1] - y0;
			int DX2 = coordinates[i][0] - x0;
			int term1 = DY * DX2, term2 = DY2 * DX;
			if (term1 != term2)return false;
		}
		return true;
	}
};