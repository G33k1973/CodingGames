#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getMinEffort' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY C as parameter.
 */
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
using ll = long long int;
using lp = std::pair<int, ll>;
#define sc static_cast<ll>
#define PRINT
//#undef PRINT
bool isvalid(int i, int j, int n, int m) {
	return (i >= 0 && j >= 0 && i < n&&j < m);
}
struct cell
{
	int x, y;
	ll distance;
	cell(int x, int y, ll distance) :
		x(x), y(y), distance(distance) {
	}
};

// Utility method for comparing two cells 
bool operator<(const cell& a, const cell& b)
{
	if (a.distance == b.distance)
	{
		if (a.x != b.x)
			return (a.x < b.x);
		else
			return (a.y < b.y);
	}
	return (a.distance < b.distance);
}

void solve(vector<vector<int>>& parent, vector<vector<int>>& cost int i, int j, int io, int jo, int& res)
{

	// Base Case : If j is source 
	if (parent[i][j] == -1) {
		res = min(res, abs(cost[io][jo] - cost[i][j]));
		return;
	}
	int ni = parent[i][j].first;
	int nj = parent[i][j].second;
	res = min(res, abs(cost[ni][nj] - cost[io][jo]))
		solve(parent, cost, ni, nj)
}
ll getMinEffort(vector<vector<int>> C) {
	int n = static_cast<int>(C.size());
	if (!n)return 0;
	int m = static_cast<int>(C.front().size());
	if (!m)return 0;
	int& row = n;
	int& col = m;
	ll dis[n][m];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			dis[i][j] = -INF;
	set<cell> st;
	vector<vector<pair<int, int>>> parent(n, vector<int>(m, -1));
	int X[4] = { +1,-1,0,0 };
	int Y[4] = { 0,0,-1,+1 };
	// insert (0, 0) cell with 0 distance 
	st.insert(cell(0, 0, 0));
	// initialize distance of (0, 0) with its grid value 
	dis[0][0] = 0;
	// loop for standard dijkstra's algorithm 
	while (!st.empty())
	{
		// get the cell with minimum distance and delete 
		// it from the set 
		cell k = *st.begin();
		st.erase(st.begin());

		// looping through all neighbours 
		for (int i = 0; i < 4; i++)
		{
			int x = k.x + X[i];
			int y = k.y + Y[i];
			//cout<<x<<" "<<y<<endl;

			// if not inside boundary, ignore them 
			if (!isvalid(x, y, n, m))
				continue;
			ll cost = sc(abs(C[k.x][k.y] - C[x][y]));
			// If distance from current cell is smaller, then 
			// update distance of neighbour cell 
			if (dis[x][y] > max(dis[k.x][k.y],cost))
			{
				// If cell is already there in set, then 
				// remove its previous entry 
				if (dis[x][y] != -INF)
					st.erase(st.find(cell(x, y, dis[x][y])));

				// update the distance and insert new updated 
				// cell in set 
				dis[x][y] = max(dis[k.x][k.y], cost);
				st.insert(cell(x, y, dis[x][y]));
			}
		}
	}
	return dis[n - 1][m - 1];
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string first_multiple_input_temp;
	getline(cin, first_multiple_input_temp);

	vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

	int n = stoi(first_multiple_input[0]);

	int m = stoi(first_multiple_input[1]);

	vector<vector<int>> arr(n);

	for (int i = 0; i < n; i++) {
		arr[i].resize(m);

		string arr_row_temp_temp;
		getline(cin, arr_row_temp_temp);

		vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

		for (int j = 0; j < m; j++) {
			int arr_row_item = stoi(arr_row_temp[j]);

			arr[i][j] = arr_row_item;
		}
	}

	ll answer = getMinEffort(arr);

	fout << answer << "\n";

	fout.close();

	return 0;
}

string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}

vector<string> split(const string &str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}
