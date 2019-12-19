class Solution {
public:
	int totalFruit(vector<int>& tree) {
		int n = int(tree.size());
		if (n == 0)return 0;
		if (n == 1)return 1;
		pair<int, int> ff(tree[0], 1), sf(-1, 0);
		int c(1), prev(tree[0]);
		int i = 1;
		int res = 0;
		while (i < n) {
			int fruit = tree[i];
			if (fruit == ff.first) {
				++ff.second;
				if (fruit == prev)++c;
				else c = 1;
			}
			else if (sf.first == -1) {
				c = 1;
				sf = make_pair(fruit, c);
			}
			else if (fruit == sf.first) {
				++sf.second;
				if (fruit == prev)++c;
				else c = 1;
			}
			else {
				res = max(res, ff.second + sf.second);
				if (prev == ff.first) {
					ff = make_pair(prev, c);
					sf = make_pair(fruit, 1);
					c = 1;
				}
				else if (prev == sf.first) {
					ff = make_pair(fruit, 1);
					sf = make_pair(prev, c);
					c = 1;
				}
			}
			prev = fruit;
			++i;
		}
		res = max(res, ff.second + sf.second);
		return res;
	}
};