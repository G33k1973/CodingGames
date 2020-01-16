class Solution {
protected:
	struct WBC {
		int iw, ib;
		int distance;
		WBC() {}
		WBC(int a, int b, int c) :iw(a), ib(b), distance(c) {}
		bool operator<(const struct WBC& ob) const {
			if (distance == ob.distance&&iw == ob.iw)return ib < ob.ib;
			if (distance == ob.distance)return iw < ob.iw;
			return distance < ob.distance;
		}
	};
	static bool comp(const struct WBC& a, const struct WBC& b) {
		return a < b;
	}
public:
	vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
		int n = int(workers.size());
		if (n == 0)return vector<int>{};
		int m = int(bikes.size());
		assert(n <= m);
		vector<struct WBC> arr;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int distance = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
				struct WBC current(i, j, distance);
				arr.push_back(current);
			}
		}
		std::sort(begin(arr), end(arr), Solution::comp);
		vector<int> res(n, -1);
		vector<bool> visited(m, 0);
		int c = 0;
		for (auto& x : arr) {
			int iw = x.iw, ib = x.ib;
			if (res[iw] != -1 || visited[ib] == true)continue;
			res[iw] = ib;
			visited[ib] = true;
			++c;
			if (c == n)break;
		}
		return res;
	}
};