#define pb push_back
class MyCalendarTwo {
protected:
	int n;
	struct event {
		int start, end;
		event(int a, int b) : start(a), end(b) {}
		event() {
			start = INT_MIN, end = INT_MAX;
		}
		bool operator<(const struct event& obj) const {
			if (start == obj.start)return this->end < obj.end;
			return (start < obj.start);
		}
	};
	static bool comp(const struct event& obj, const struct event& obj2) {
		return obj.operator<(obj2);
	}
	std::vector<event> arr;
public:
	MyCalendarTwo() {
		(*this).n = 0;
	}

	bool book(int start, int end) {
		if (n < 2) {
			++n;
			event current {start, end};
			arr.pb(current);
			if (n > 1)sort(arr.begin(), arr.end(), MyCalendarTwo::comp);
			return true;
		}
		if (end <= arr.front().start) {
			++n;
			event current {start, end};
			arr.pb(current);
			sort(arr.begin(), arr.end(), MyCalendarTwo::comp);
			return true;
		}
		if (start >= arr.back().end) {
			++n;
			event current {start, end};
			arr.pb(current);
			return true;
		}
		for (int i = 0; i < n - 1; ++i) {
			if (start >= arr[i].end)continue;
			if (end <= arr[i].start)break;
			event current {max(start, arr[i].start), min(end, arr[i].end)};
			for (int j = i + 1; j < n; ++j) {
				if (current.start >= arr[j].end)continue;
				if (current.end <= arr[j].start)break;
				return false;
			}
		}
		++n;
		event current {start, end};
		arr.pb(current);
		sort(arr.begin(), arr.end(), MyCalendarTwo::comp);
		return true;
	}
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */