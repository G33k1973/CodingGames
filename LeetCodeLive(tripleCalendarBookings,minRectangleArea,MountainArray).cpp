class Solution {
public:
	bool validMountainArray(vector<int>& A) {
		int n = int(A.size());
		if (n < 3)return false;
		bool decreasing = false;
		int mx = A[1];
		int i = 1;
		while (i < n) {
			if (A[i] == A[i - 1])return false;
			if (i == 1 && mx < A.front())return false;
			else if (i > 1) {
				if (decreasing&&A[i] > A[i - 1])return false;
				if (A[i] > mx)mx = A[i];
				else {
					if (mx == A[i - 1]) {
						decreasing = true;
					}
				}
			}
			++i;
		}
		return decreasing == true;
	}
};

#define pb push_back
using ll = long long int;
class Solution {
public:
	ll minAreaRect(vector<vector<int>>& points) {
		int n = int(points.size());
		if (n < 4)return 0;
		std::map<int, set<int>> P;
		for (auto& x : points) {
			P[x.front()].insert(x.back());
		}
		auto ptr = begin(P);
		ll res = std::numeric_limits<ll>::max();
		while (ptr != std::prev(end(P), 1)) {
			int x1 = ptr->first;
			auto ptr2 = std::next(ptr);
			while (ptr2 != end(P)) {
				int x2 = ptr2->first;
				auto ity1 = ptr->second.begin();
				while (ity1 != std::prev(ptr->second.end(), 1)) {
					int y1 = *ity1;
					if (ptr2->second.find(y1) != end(ptr2->second)) {
						auto ity2 = next(ity1, 1);
						while (ity2 != end(ptr->second)) {
							if (ptr2->second.find(*ity2) != end(ptr2->second)) {
								int y2 = *ity2;
								ll area = static_cast<ll>(x2 - x1)*static_cast<ll>(y2 - y1);
								res = min(res, area);
							}
							++ity2;
						}
					}
					++ity1;
				}
				++ptr2;
			}
			++ptr;
		}
		return (res == numeric_limits<ll>::max()) ? (0) : (res);
	}
};

#define pb push_back
class MyCalendarTwo {
private:
	std::vector<pair<int, int>> intervals;
	std::vector<pair<int, int>> intersections;
	pair<int, int> overlapping(const pair<int, int>& a, const pair<int, int>& b) {
		if (a.first <= b.first&&a.second >= b.second)return make_pair(b.first, b.second);
		if (a.first >= b.first&&a.second <= b.second)return make_pair(a.first, a.second);
		if (a.first<b.first&&a.second>b.first&&a.second < b.second)return make_pair(b.first, a.second);
		if (a.first > b.first&&a.first<b.second&&a.second>b.second)return make_pair(a.first, b.second);
		return make_pair(INT_MIN, INT_MIN);
	}
public:
	MyCalendarTwo() {

	}

	bool book(int start, int end) {
		if (intervals.empty()) {
			intervals.push_back(make_pair(start, end));
			return true;
		}
		pair<int, int> latest{ start,end };
		if (intersections.size() == 0) {
			for (auto& x : intervals) {
				pair<int, int> temp = overlapping(latest, x);
				if (temp.first == INT_MIN) {
					continue;
				}
				intersections.push_back(temp);
			}
			intervals.push_back(latest);
			return true;
		}
		for (auto& x : intersections) {
			pair<int, int> temp = overlapping(latest, x);
			if (temp.first != INT_MIN)return false;
		}
		for (auto& x : intervals) {
			pair<int, int> temp = overlapping(latest, x);
			if (temp.first == INT_MIN) {
				continue;
			}
			intersections.push_back(temp);
		}
		intervals.push_back(latest);
		return true;
	}
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */