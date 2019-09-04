#define pb push_back
#define eps 1.e-6
class Solution {
public:
	bool isReflected(vector<vector<int>>& points) {
		int n = static_cast<int>(points.size());
		if (n < 2)return true;
		std::map<double, unordered_set<int>, less<double>> grid;
		for (const auto& x : points) {
			int X = double(x[0]), Y = (x[1]);
			grid[X].insert(Y);
		}
		if (grid.size() == 1)return true;
		int xmin = begin(grid)->first;
		int xmax = prev(end(grid), 1)->first;
		double xmiddle = .5*(xmax + xmin);
		auto ptr1 = begin(grid), ptr2 = prev(end(grid), 1);
		while ((ptr2->first - ptr1->first) > eps) {
			double d1 = xmiddle - ptr1->first;
			double d2 = ptr2->first - xmiddle;
			//cout<<d1<<" "<<d2<<endl;
			if (abs(d1 - d2) > eps)return 0;
			unordered_set<int> h1 = ptr1->second;
			unordered_set<int> h2 = ptr2->second;
			if (h1.size() != h2.size())return 0;
			for (auto& z : h1) {
				if (h2.count(z) == 0)return 0;
			}
			++ptr1, --ptr2;
		}
		return 1;
	}
};