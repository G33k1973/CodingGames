{
#include <bits/stdc++.h>
using namespace std;
struct Point
{
	int grp;
	double x, y;
	double distance;
};
/*
A utility structure to store the info of points
x and y represents the 2D coordinates of the points
grp represents to which particular point belongs
struct Point
{
	int grp;
	double x, y;
	double distance;
};
*/
// function should return to which grp 
// the test data will belong
int classifyAPoint(Point arr[], int n, int k, Point test);
// Driver code
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n;
		Point arr[n], test;
		for (int i = 0; i < n; i++)
			cin >> arr[i].x >> arr[i].y >> arr[i].grp;
		cin >> test.x >> test.y >> k;
		cout << classifyAPoint(arr, n, k, test) << endl;
	}
	return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
A utility structure to store the info of points
x and y represents the 2D coordinates of the points
grp represents to which particular point belongs
struct Point
{
	int grp;
	double x, y;
	double distance;
};
*/

bool cmp(struct Point& x, struct Point& y) {
	return (x.distance < y.distance);
}
// function should return to which grp 
// the test data will belong
int classifyAPoint(Point arr[], int n, int k, Point test);
{
	// Code here
	int i = 0;
	double X = test.x;
	double Y = test.y;
	while (i < n) {
		Point& curr = *(arr + i++);
		double x = curr.x;
		double y = curr.y;
		double distance = (x - X)*(x - X) + (y - Y)*(y - Y);
		curr.distance = distance;
	}
	sort(begin(arr), end(arr), cmp);
	std::unordered_map<int,int> hs;
	i = 0;
	while (i < k) {
		++hs[arr[i].grp];
		++i;
	}
	std::pair<int, int> res(-1, -1);
	for (const auto& x : hs) {
		if (res.first < x.second)
			res = make_pair(x.second, x.first);
	}
	return res.second;
}