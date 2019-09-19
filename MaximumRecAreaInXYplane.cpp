#define pb push_back
#define eps 1.e-5
#define INF 0x3f3f3f3f
class Solution {
protected:
	struct line {
		int xl, yl, xh, yh;
		double dist2;
		line(int a, int b, int c, int d) {
			if (a <= c) {
				xl = a, yl = b, xh = c, yh = d;
			}
			else {
				xl = c, yl = d, xh = a, yh = b;
			}
			this->dist2 = hypot((xl - xh), (yl - yh));
		}
	};
	bool ComputeSlope(line& a, line& b, double slope, double& area) {
		if (a.dist2 != b.dist2)return false;
		int x1 = a.xl, y1 = a.yl, x2 = a.xh, y2 = a.yh;
		int X1 = b.xl, Y1 = b.yl, X2 = b.xh, Y2 = b.yh;
		double slopePerpendicular = (1.*(Y1 - y1) / (1.*(X1 - x1)));
		double val = slope * slopePerpendicular;
		if (abs(val + 1.) < eps) {
			double dist3 = hypot((x1 - X1), (y1 - Y1));
			//cout<<a.dist2<<" "<<dist3<<endl;
			area = (dist3*a.dist2);
			//cout<<area<<endl;
			return true;
		}
		return false;
	}
public:
	double minAreaFreeRect(vector<vector<int>>& points) {
		std::map<double, vector<line>> slopes;
		int n = static_cast<int>(points.size());
		double res = std::numeric_limits<double>::max();
		if (n < 4)return 0;
		for (int i = 0; i < n; ++i) {
			int x1 = points[i].front();
			int y1 = points[i].back();
			for (int j = i + 1; j < n; ++j) {
				int x2 = points[j].front();
				int y2 = points[j].back();
				line current{ x1,y1,x2,y2 };
				if (x1 == x2)slopes[INF].pb(current);
				else if (y1 == y2)slopes[0].pb(current);
				else {
					double sl = (1.*(y2 - y1)) / (1.*(x2 - x1));
					//cout<<sl<<endl;
					slopes[sl].pb(current);
				}
			}
		}
		std::map<double, vector<line>>::iterator it = begin(slopes);
		while (it != end(slopes)) {
			//cout<<it->first<<endl;
			int m = (int)it->second.size();
			if (m > 1) {
				for (int i = 0; i < m; ++i) {
					int x1 = it->second[i].xl;
					int y1 = it->second[i].yl;
					int x2 = it->second[i].xh;
					int y2 = it->second[i].yh;
					for (int j = i + 1; j < m; ++j) {
						int X1 = it->second[j].xl;
						int Y1 = it->second[j].yl;
						int X2 = it->second[j].xh;
						int Y2 = it->second[j].yh;
						if (it->first == INF) {
							int min1 = min(y1, y2);
							int MIN1 = min(Y1, Y2);
							int max1 = max(y1, y2);
							int MAX1 = max(Y1, Y2);
							if (min1 == MIN1 && max1 == MAX1) {
								res = min(res, 1.*abs(X1 - x1)*(MAX1 - MIN1));
							}
						}
						else if (it->first == 0) {
							if (x1 == X1 && x2 == X2) {
								res = min(res, 1.*(X2 - X1)*abs(Y2 - y2));
							}
						}
						else {
							double area = 0.0;
							if (ComputeSlope(it->second[i], it->second[j], it->first, area)) {
								res = min(res, area);
							}
						}
					}
				}
			}
			++it;
		}
		return (res == std::numeric_limits<double>::max()) ? (0) : (res);
	}
};