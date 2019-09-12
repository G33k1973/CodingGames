using ip = std::pair<int, int>;
#define pb push_back
auto SortCalendar = [](const ip& a, const ip& b)->bool {
	if (a.first == b.first)return a.second < b.second;
	return (a.first < b.first);
};
class MyCalendarThree
{
	int maxCnt = 0;
	map<int, int> mp; // key: time; val: +1 if start, -1 if end
public:
	int book(int start, int end)
	{
		mp[start]++;
		mp[end]--;
		int cnt = 0;
		for (auto it = mp.begin(); it != mp.end(); it++)
		{
			cnt += it->second;
			maxCnt = max(cnt, maxCnt);
		}
		return maxCnt;
	}
};
/*
class MyCalendarThree {
protected:
	vector<ip> calendar;
	int n;
	int dfs(int n, int i, int& st, int& ed) {
		if (i == n)return 0;
		if (calendar[i].first >= ed)return 0;
		st = calendar[i].first;
		ed = min(ed, calendar[i].second);
		return 1 + dfs(n, i + 1, st, ed);
	}
public:
	MyCalendarThree() {
		(*this).n = 0;
	}

	int book(int start, int end) {
		calendar.pb(make_pair(start, end));
		++n;
		if (n == 1)return 1;
		sort(calendar.begin(), calendar.end(), SortCalendar);
		int res(1);
		for (int i = 0; i < n; ++i) {
			int sub = 1;
			sub += dfs(n, i + 1, calendar[i].first, calendar[i].second);
			res = max(sub, res);
		}
		return res;
	}
};
*/

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */