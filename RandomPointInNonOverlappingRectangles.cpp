#define pb push_back
class Solution {
protected:
	int n;
	int c;
	vector<vector<int>> rec;
public:
	Solution(vector<vector<int>>& rects) {
		this->n = static_cast<int>(rects.size());
		rec = rects;
		std::srand(time(0));
		c = -1;
	}

	vector<int> pick() {
		vector<int> res;
		int index = (++c) % n;
		int randnum = rand();
		vector<int> temp = this->rec.at(index);
		int xmin = temp[0], xmax = temp[2], ymin = temp[1], ymax = temp[3];
		int dx = xmax - xmin + 1, dy = ymax - ymin + 1;
		int xactual = xmin + randnum % dx;
		int yactual = ymin + randnum % dy;
		return res = vector<int>{ xactual,yactual };
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */