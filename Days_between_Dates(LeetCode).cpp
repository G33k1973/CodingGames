int mt[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
class Solution {
private:
	bool isleap(int y) {
		if (y % 400 == 0)return 1;
		if (y % 100 == 0)return 0;
		return (y % 4) == 0;
	}
	struct Date_ {
		int d, m, y;
		Date_() {}
		Date_(int a, int b, int c) :d(a), m(b), y(c) {}
		bool operator<(const struct Date_ ob) const {
			if (y == ob.y&&m == ob.m)return d < ob.d;
			if (y == ob.y)return m < ob.m;
			return y < ob.y;
		}
		int days() {
			int res = y * 365;
			for (int i = 0; i < m - 1; ++i)res += mt[i];
			res += d;
			if (m <= 2)--y;
			res += (y / 4 - y / 100 + y / 400);
			return res;
		}
	};
	static bool cmp(const Date_& a, const Date_& b) {
		return a < b;
	}
public:
	int daysBetweenDates(string date1, string date2) {
		int y1 = stoi(date1.substr(0, 4));
		int m1 = stoi(date1.substr(5, 2));
		int d1 = stoi(date1.substr(8, 2));
		int y2 = stoi(date2.substr(0, 4));
		int m2 = stoi(date2.substr(5, 2));
		int d2 = stoi(date2.substr(8, 2));
		Date_ a{ d1,m1,y1 }, b{ d2,m2,y2 };
		vector<Date_> arr{ a,b };
		sort(begin(arr), end(arr), Solution::cmp);
		return arr.back().days() - arr.front().days();
	}
};