#define pb push_back
#define mp make_pair
using ip = std::pair<int, int>;
int nm, m, n;
class Solution {
protected:
	int X[4] = { 1,-1,0,0 };
	int Y[4] = { 0,0,+1,-1 };
	map<vector<int>, int> seen;
	struct Matrix {
		vector<int> arr;
		int c1;
		int flips;
		vector<ip> points1, points0;
		Matrix() {
			c1 = 0;
			arr = vector<int>{};
			points1 = vector<ip>{};
			points0 = vector<ip>{};
			flips = 0;
		}
		Matrix(vector<int>& temp, int w) {
			flips = ++w;
			arr.assign(begin(temp), end(temp));
			if (points1.size())points1.clear();
			if (points0.size())points0.clear();
			c1 = 0;
			for (int i = 0; i < nm; ++i) {
				if (temp[i] == 1) {
					int I = i / m;
					int J = i % m;
					points1.pb(mp(I, J));
					++c1;
				}
				else {
					int I = i / m;
					int J = i % m;
					points0.pb(mp(I, J));
				}
			}
		}
	};
	bool isgood(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m);
	}
public:
	int minFlips(vector<vector<int>>& mat) {
		n = int(mat.size());
		if (n == 0)return -1;
		m = int(mat.front().size());
		if (m == 0)return -1;
		nm = n * m;
		int ans = INT_MAX;
		if (seen.size())seen.clear();
		std::queue<struct Matrix> pile;
		vector<int> temp;
		for (auto& x : mat) {
			for (auto& y : x) {
				temp.pb(y);
			}
		}
		struct Matrix current(temp, -1);
		pile.push(current);
		++seen[temp];
		while (!pile.empty()) {
			int sz = int(pile.size());
			int i = 0;
			while (i < sz) {
				struct Matrix a = pile.front();
				pile.pop();
				int c1 = a.c1;
				int weight = a.flips;
				//cout<<c1<<" "<<weight<<endl;
				if (c1 == 0) {
					ans = min(ans, weight);
					++i;
					continue;
				}
				vector<int> state = a.arr;
				for (auto& x : a.points1) {
					int oi = x.first, oj = x.second;
					vector<int> b(state);
					b[oi*m + oj] = 0;
					for (int u = 0; u < 4; ++u) {
						int ni = oi + X[u], nj = oj + Y[u];
						if (isgood(ni, nj)) {
							b.at(ni*m + nj) = !b[ni*m + nj];
						}
					}
					auto it = seen.find(b);
					if (it == end(seen)) {
						++seen[b];
						struct Matrix latest(b, weight);
						pile.push(latest);
					}
				}
				for (auto& x : a.points0) {
					int oi = x.first, oj = x.second;
					vector<int> b(state);
					b[oi*m + oj] = 1;
					for (int u = 0; u < 4; ++u) {
						int ni = oi + X[u], nj = oj + Y[u];
						if (isgood(ni, nj)) {
							b.at(ni*m + nj) = !b[ni*m + nj];
						}
					}
					auto it = seen.find(b);
					if (it == end(seen)) {
						++seen[b];
						struct Matrix latest(b, weight);
						pile.push(latest);
					}
				}
				++i;
			}
		}
		return (ans == INT_MAX) ? (-1) : (ans);
	}
};