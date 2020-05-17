typedef complex<double> Point;
#define MAX_POINTS 101
double dis[MAX_POINTS][MAX_POINTS];
class Solution {
private:
	vector<Point> ARR;
	int getPointsInside(int i, double r, int n)
	{
		// This vector stores alpha and beta and flag 
		// is marked true for alpha and false for beta 
		vector<pair<double, bool> > angles;
		for (int j = 0; j < n; j++)
		{
			if (i != j && dis[i][j] <= 2 * r)
			{
				// acos returns the arc cosine of the complex 
				// used for cosine inverse 
				double B = acos(dis[i][j] / (2 * r));

				// arg returns the phase angle of the complex 
				double A = arg(ARR[j] - ARR[i]);
				double alpha = A - B;
				double beta = A + B;
				angles.push_back(make_pair(alpha, true));
				angles.push_back(make_pair(beta, false));
			}
		}

		// angles vector is sorted and traversed 
		sort(angles.begin(), angles.end(), Solution::CMP);

		// count maintains the number of points inside 
		// the circle at certain value of theta 
		// res maintains the maximum of all count 
		int count = 1, res = 1;
		vector<pair<double, bool> >::iterator it;
		for (it = angles.begin(); it != angles.end(); ++it)
		{
			// entry angle 
			if ((*it).second)
				count++;

			// exit angle 
			else
				count--;

			if (count > res)
				res = count;
		}

		return res;
	}
	static bool CMP(const pair<double, bool>& A, const  pair<double, bool>& B)
	{
		if (A.first < B.first) return true;
		else if (A.first > B.first)return false;
		else return (A.second == 1);
	}
public:
	int numPoints(vector<vector<int>>& arr, int r) {
		const int n = int(arr.size());
		for (int i = 0; i < n; ++i) {
			Point temp(arr[i][0], arr[i][1]);
			ARR.push_back(temp);
		}
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				dis[i][j] = dis[j][i] = abs(ARR[i] - ARR[j]);
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = max(ans, getPointsInside(i, 1.*r, n));

		return ans;
	}
};