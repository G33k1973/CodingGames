// you can use includes, for example:
#include <bits/stdc++.h>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &X, vector<int> &Y) {
	// write your code in C++14 (g++ 6.2.0)
	int n = static_cast<int>(X.size());
	int m = static_cast<int>(Y.size());
	assert(n == m);
	int res(0);
	if (n < 4)return 0;
	unordered_map<int, set<int>> hx, hy;
	int i(0);
	while (i < n) {
		int x = X.at(i);
		int y = Y.at(i);
		hx[x].insert(y);
		hy[y].insert(x);
		++i;
	}
	for (auto& x : hx) {
		int xval = x.first;
		if (x.second.size() < static_cast<std::size_t>(2))continue;
		auto it = x.second.begin();
		while (it != prev(x.second.end(), 1)) {
			int y1 = *it;
			auto it2 = std::next(it, 1);
			while (it2 != end(x.second)) {
				int y2 = *it2;
				int dist = y2 - y1;
				if (!(dist & 1)) {
					int ycentre = y1 + (y2 - y1) / 2;
					auto it3 = hy.find(ycentre);
					if (it3 == end(hy) || it3->second.size() < static_cast<std::size_t>(2)) {
						++it2;
						continue;
					}
					auto it4 = it3->second.begin();
					while (it4 != std::prev(it3->second.end(), 1) && *it4 < xval) {
						int distx = xval - *it4;
						int targetx = xval + distx;
						if (it3->second.find(targetx) != end(it3->second))++res;
						++it4;
					}
				}
				++it2;
			}
			++it;
		}
	}
	return res;
}