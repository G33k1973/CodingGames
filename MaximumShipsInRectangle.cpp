/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
protected:
	vector<int> tr, bl;
	int dfs(Sea& sea, int x2, int y2, int x1, int y1) {
		if (x2 < x1 || y2 < y1)return 0;
		tr.front() = x2, tr.back() = y2;
		bl.front() = x1, bl.back() = y1;
		if (x2 == x1 && y2 == y1) {
			bool result = sea.hasShips(tr, bl);
			if (result == true)return 0;
			return 1;
		}
		bool result = sea.hasShips(tr, bl);
		if (result == false) {
			return (x2 - x1 + 1)*(y2 - y1 + 1);
		}
		int ans = 0;
		int anstl = dfs(sea, x1 + (x2 - x1) / 2, y2, x1, y1 + (y2 - y1) / 2 + 1);
		int anstr = dfs(sea, x2, y2, x1 + (x2 - x1) / 2 + 1, y1 + (y2 - y1) / 2 + 1);
		int ansbl = dfs(sea, x1 + (x2 - x1) / 2, y1 + (y2 - y1) / 2, x1, y1);
		int ansbr = dfs(sea, x2, y1 + (y2 - y1) / 2, x1 + (x2 - x1) / 2 + 1, y1);
		return ans = anstr + anstl + ansbl + ansbr;

	}
public:
	int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
		int x2 = topRight.front();
		int y2 = topRight.back();
		int x1 = bottomLeft.front();
		int y1 = bottomLeft.back();
		int maxShips = (x2 - x1 + 1)*(y2 - y1 + 1);
		if (maxShips == 1) {
			bool guess = sea.hasShips(topRight, bottomLeft);
			if (guess == true)return 1;
			return 0;
		}
		int ans(0);
		tr.assign(2, 0);
		bl.assign(2, 0);
		return maxShips - dfs(sea, x2, y2, x1, y1);
	}
};