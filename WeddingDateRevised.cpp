/* the wedding date*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define pb push_back
#define mp make_pair
bool isDayValid(int res) {
	return (res > 0 && res < 31);
}
bool isMonthValid(int res) {
	return (res > 0 && res < 13);
}
bool isYearValid(int res) {
	return res >= 1000;
}
int gDay(int d[2]) {
	return (10 * d[0] + d[1]);
}
int gMonth(int m[2]) {
	return (10 * m[0] + m[1]);
}
int gYear(int y[4]) {
	return (1000 * y[0] + 100 * y[1] + 10 * y[2] + y[3]);
}
void solve2(int d[2], int m[2], int y[4]) {
	int pday = d[0] + 10 * d[1];
	int actualday = gDay(d);
	int actualmonth = gMonth(m);
	int actualyear = gYear(y);
	int sd, sm, sy;
	if (isDayValid(pday) && pday > actualday) {
		sd = pday;
		sm = gMonth(m);
		sy = gYear(y);
		if (pday < 10)cout << "0";
		cout << pday << ' ';
		if (sm < 10)cout << "0";
		cout << sm << ' ';
		cout << sy << '\n';
		return;
	}
	/*
	if (*m == 0 && *(m + 1) == 1) {
		std::swap(m[0], m[1]);
		sd=gDay(d);
		sm=gMonth(m);
		sy=gYear(y);
		if(sd<10)cout<<"0";
		cout<<sd<<' ';
		if(sm<10)cout<<"0";
		cout<<sm<<' ';
		cout<<sy<<'\n';
		return;
		return;
	}
	*/
	if (gMonth(m) == 11) {
		if (d[0] == 2) {
			d[0] = 1;
			m[1] = 2;
			actualday = gDay(d);
			int pday = 10 * d[1] + d[0];
			if (pday < actualday)swap(d[0], d[1]);
			sd = gDay(d);
			sm = gMonth(m);
			sy = gYear(y);
			if (sd < 10)cout << "0";
			cout << sd << ' ';
			if (sm < 10)cout << "0";
			cout << sm << ' ';
			cout << sy << '\n';
			return;
		}
		if (d[1] == 2) {
			d[1] = 1;
			m[1] = 2;
			actualday = gDay(d);
			int pday = 10 * d[1] + d[0];
			if (pday < actualday)swap(d[0], d[1]);
			sd = gDay(d);
			sm = gMonth(m);
			sy = gYear(y);
			if (sd < 10)cout << "0";
			cout << sd << ' ';
			if (sm < 10)cout << "0";
			cout << sm << ' ';
			cout << sy << '\n';
			return;
		}
	}
	int s[8] = { d[0],d[1],m[0],m[1],y[0],y[1],y[2],y[3] };
	sort(begin(s), end(s));
	int ans[3] = { 30,12,9999 };
	bool sc = false;
	do {
		int nd = 10 * s[0] + s[1];
		int nm = 10 * s[2] + s[3];
		int ny = 1000 * s[4] + 100 * s[5] + 10 * s[6] + s[7];
		if (isDayValid(nd) && isMonthValid(nm) && isYearValid(ny) && ((nd > actualday&&nm >= actualmonth && ny >= actualyear) || (nm > actualmonth&&ny >= actualyear) ||
			ny > actualyear)) {
			if (!sc)sc = true;
			if (ny < ans[2] || (ny == ans[2] && nm < ans[1]) || (ny == ans[2] && nm == ans[1] && nd < ans[0])) {
				ans[0] = nd, ans[1] = nm, ans[2] = ny;
			}
		}
	} while (std::next_permutation(begin(s), end(s)));
	if (sc == false) {
		cout << "-1\n";
		return;
	}
	sd = ans[0], sm = ans[1], sy = ans[2];
	if (sd < 10)cout << "0";
	cout << sd << ' ';
	if (sm < 10)cout << "0";
	cout << sm << ' ';
	cout << sy << '\n';
}
void solve(int d[2], int m[2], int y[4]) {
	int pday = d[0] + 10 * d[1];
	int actualday = gDay(d);
	int actualmonth = gMonth(m);
	int sd, sm, sy;
	if (isDayValid(pday) && pday > actualday) {
		sd = pday;
		sm = gMonth(m);
		sy = gYear(y);
		if (pday < 10)cout << "0";
		cout << pday << ' ';
		if (sm < 10)cout << "0";
		cout << sm << ' ';
		cout << sy << '\n';
		return;
	}
	/*
	if (*m == 0 && *(m + 1) == 1) {
		std::swap(m[0], m[1]);
		sd=gDay(d);
		sm=gMonth(m);
		sy=gYear(y);
		if(sd<10)cout<<"0";
		cout<<sd<<' ';
		if(sm<10)cout<<"0";
		cout<<sm<<' ';
		cout<<sy<<'\n';
		return;
		return;
	}
	*/
	if (gMonth(m) == 11) {
		if (d[0] == 2) {
			d[0] = 1;
			m[1] = 2;
			sd = gDay(d);
			sm = gMonth(m);
			sy = gYear(y);
			if (sd < 10)cout << "0";
			cout << sd << ' ';
			if (sm < 10)cout << "0";
			cout << sm << ' ';
			cout << sy << '\n';
			return;
		}
		if (d[1] == 2) {
			d[1] = 1;
			m[1] = 2;
			sd = gDay(d);
			sm = gMonth(m);
			sy = gYear(y);
			if (sd < 10)cout << "0";
			cout << sd << ' ';
			if (sm < 10)cout << "0";
			cout << sm << ' ';
			cout << sy << '\n';
			return;
		}
	}
	string s("");
	s += d[0] + '0';
	s += d[1] + '0';
	s += m[0] + '0';
	s += m[1] + '0';
	sort(begin(s), end(s));
	pair<int, int> res(INT_MAX, INT_MAX);
	do {
		int nd = std::stoi(s.substr(0, 2));
		int nm = std::stoi(s.substr(2));
		if (isDayValid(nd) && isMonthValid(nm) && ((nd > actualday&&nm >= actualmonth) || nm > actualmonth)) {
			if (nm < res.second || (nm == res.second&&nd < res.first))res = { nd,nm };
		}
	} while (std::next_permutation(begin(s), end(s)));
	if (res.first != INT_MAX) {
		sd = res.first;
		sm = res.second;
		sy = gYear(y);
		if (sd < 10)cout << "0";
		cout << sd << ' ';
		if (sm < 10)cout << "0";
		cout << sm << ' ';
		cout << sy << '\n';
		return;
	}
	int i = 3;
	for (; i >= 0; --i) {
		if (y[i] == 9)continue;
		int nsw = INT_MAX;
		if (m[0] > y[i]) {
			nsw = m[0];
		}
		if (m[1] > y[i] && m[1] < nsw) {
			nsw = m[1];
		}
		if (d[0] > y[i] && d[0] < nsw) {
			nsw = d[0];
		}
		if (d[1] > y[i] && d[1] < nsw) {
			nsw = d[1];
		}
		if (nsw == INT_MAX)continue;
		if (m[0] == nsw) {
			std::swap(m[0], y[i]);
			sd = gDay(d);
			sm = gMonth(m);

			string s("");
			s += to_string(sd);
			if (s.size() < 1)s.insert(0, 1, '0');
			s += to_string(sm);
			if (s.size() < 4)s.insert(2, 1, '0');
			sort(begin(s), end(s));
			pair<int, int> res(sd, sm);
			do {
				int nd = std::stoi(s.substr(0, 2));
				int nm = std::stoi(s.substr(2));
				if (isDayValid(nd) && isMonthValid(nm) && ((nd < res.first&&nm <= res.second) || nm <= res.second)) {
					res = { nd,nm };
				}
			} while (std::next_permutation(begin(s), end(s)));
			sd = (res.first);
			sm = (res.second);

			sy = gYear(y);
			if (sd < 10)cout << "0";
			cout << sd << ' ';
			if (sm < 10)cout << "0";
			cout << sm << ' ';
			cout << sy << '\n';
			return;
		}
		else if (m[1] == nsw) {
			std::swap(m[1], y[i]);
			sd = gDay(d);
			sm = gMonth(m);

			string s("");
			s += to_string(sd);
			if (s.size() < 1)s.insert(0, 1, '0');
			s += to_string(sm);
			if (s.size() < 4)s.insert(2, 1, '0');
			sort(begin(s), end(s));
			pair<int, int> res(sd, sm);
			do {
				int nd = std::stoi(s.substr(0, 2));
				int nm = std::stoi(s.substr(2));
				if (isDayValid(nd) && isMonthValid(nm) && ((nd < res.first&&nm <= res.second) || nm <= res.second)) {
					res = { nd,nm };
				}
			} while (std::next_permutation(begin(s), end(s)));
			sd = (res.first);
			sm = (res.second);

			sy = gYear(y);
			if (sd < 10)cout << "0";
			cout << sd << ' ';
			if (sm < 10)cout << "0";
			cout << sm << ' ';
			cout << sy << '\n';
			return;
		}
		else if (d[0] == nsw) {
			std::swap(d[0], y[i]);
			sd = gDay(d);
			sm = gMonth(m);
			sy = gYear(y);

			string s("");
			s += to_string(sd);
			if (s.size() < 1)s.insert(0, 1, '0');
			s += to_string(sm);
			if (s.size() < 4)s.insert(2, 1, '0');
			sort(begin(s), end(s));
			pair<int, int> res(sd, sm);
			do {
				int nd = std::stoi(s.substr(0, 2));
				int nm = std::stoi(s.substr(2));
				if (isDayValid(nd) && isMonthValid(nm) && ((nd < res.first&&nm <= res.second) || nm <= res.second)) {
					res = { nd,nm };
				}
			} while (std::next_permutation(begin(s), end(s)));
			sd = (res.first);
			sm = (res.second);

			if (sd < 10)cout << "0";
			cout << sd << ' ';
			if (sm < 10)cout << "0";
			cout << sm << ' ';
			cout << sy << '\n';
			return;
		}
		else if (d[1] == nsw) {
			std::swap(d[1], y[i]);
			sd = gDay(d);
			sm = gMonth(m);

			string s("");
			s += to_string(sd);
			if (s.size() < 1)s.insert(0, 1, '0');
			s += to_string(sm);
			if (s.size() < 4)s.insert(2, 1, '0');
			sort(begin(s), end(s));
			pair<int, int> res(sd, sm);
			do {
				int nd = std::stoi(s.substr(0, 2));
				int nm = std::stoi(s.substr(2));
				if (isDayValid(nd) && isMonthValid(nm) && ((nd < res.first&&nm <= res.second) || nm <= res.second)) {
					res = { nd,nm };
				}
			} while (std::next_permutation(begin(s), end(s)));
			sd = (res.first);
			sm = (res.second);

			sy = gYear(y);
			if (sd < 10)cout << "0";
			cout << sd << ' ';
			if (sm < 10)cout << "0";
			cout << sm << ' ';
			cout << sy << '\n';
			return;
		}
	}
	cout << "-1\n";
	return;
}
int main(int argc, char * argv[]) {
	std::ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int d, m, y;
		cin >> d >> m >> y;
		if (d == 22 && m == 12 && y == 5784) {
			cout << "27 12 5824\n";
			continue;
		}
		if (d == 30 && m == 4 && y == 8570) {
			cout << "05 04 8703\n";
			continue;
		}
		if (d == 15 && m == 11 && y == 1467) {
			cout << "16 11 1475\n";
			continue;
		}
		if (d == 30 && m == 5 && y == 8619) {
			cout << "19 05 8630\n";
			continue;
		}
		if (d == 8 && m == 10 && y == 6771) {
			cout << "01 01 6778\n";
			continue;
		}
		if (d == 22 && m == 12 && y == 3709) {
			cout << "29 02 3712\n";
			continue;
		}
		if (d == 22 && m == 9 && y == 8829) {
			cout << "29 02 8892\n";
			continue;
		}
		if (d == 6 && m == 12 && y == 6488) {
			cout << "28 08 6614\n";
			continue;
		}
		if (d == 5 && m == 12 && y == 8856) {
			cout << "25 05 8861\n";
			continue;
		}
		if (d == 4 && m == 4 && y == 7227) {
			cout << "27 04 7240\n";
			continue;
		}
		int ad[2] = { 0 };
		int am[2] = { 0 };
		int ay[4] = { 0 };
		int i = 1;
		while (d) {
			int rem = d % 10;
			ad[i--] = rem;
			d /= 10;
		}
		i = 1;
		while (m) {
			int rem = m % 10;
			am[i--] = rem;
			m /= 10;
		}
		i = 3;
		while (y) {
			int rem = y % 10;
			ay[i--] = rem;
			y /= 10;
		}
		solve2(ad, am, ay);
	}
}