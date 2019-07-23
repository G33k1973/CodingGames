class Solution {
private:
	struct Interval {
		int start, end, index;
	};
	static bool cmp(const struct Interval& a, const struct Interval& b) {
		return a.end <= b.start;
	}
public:
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		int n = static_cast<int>(intervals.size());
		vector<int> a(n, -1);
		if (n < 2)return a;
		std::vector<Interval> arr;
		for (int i = 0; i < n; ++i) {
			arr.push_back({ intervals[i][0],intervals[i][1],i });
		}
		std::sort(begin(arr), end(arr), Solution::cmp);
		int i = 0;
		while (i < n) {
			int j = i + 1;
			int k = -1;
			int sub = INT_MAX;
			while (j < n) {
				if (arr[j].start >= arr[i].end) {
					int sub2 = arr[j].start - arr[i].end;
					if (sub2 > sub)break;
					if(sub2<sub)k = arr[j].index;
					sub = min(sub, sub2);
					break;
				}
				++j;
			}
			a[arr[i].index] = k;
			++i;
		}
		return a;
	}
};