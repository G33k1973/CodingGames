#define pb push_back
class Solution {
public:
	bool wordPattern(string pattern, string str) {
		int l = int(pattern.size());
		str += " ";
		string sub = "";
		vector<string> arr;
		for (const char& i : str) {
			if (i == ' ') {
				if (sub.empty() ^ 1) {
					arr.pb(sub);
					sub.clear();
				}
			}
			else
				sub.pb(i);
		}
		int n = int(arr.size());
		if (n != l)return false;
		unordered_map<char, string> fun1;
		unordered_map<string, char> fun2;
		for (int i = 0; i < l; ++i) {
			auto it = fun1.find(pattern[i]);
			auto it2 = fun2.find(arr[i]);
			if (it == end(fun1) && it2 == end(fun2)) {
				fun1.insert(make_pair(pattern[i], arr[i]));
				fun2.insert(make_pair(arr[i], pattern[i]));
			}
			else if (it == end(fun1) || it2 == end(fun2))return 0;
			else {
				if (it->second != arr[i] || it2->second != pattern[i])return 0;
			}
		}
		return 1;
	}
};

typedef pair<int, int> ip;
typedef pair<ip, int> iip;
class Solution {
protected:
	int n, m;
	queue<iip> pile;
	int X[4] = { 1,-1,0,0 };
	int Y[4] = { 0,0,-1,+1 };
	bool isvalid(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m);
	}
	vector<vector<int>> distances;
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		n = int(matrix.size());
		if (n == 0)return distances;
		m = int(matrix.front().size());
		if (m == 0)return distances;
		int i, j;
		distances.assign(n, vector<int>(m, 0));
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				if (matrix[i][j] == 0) {
					pile.push(make_pair(make_pair(i, j), 0));
					visited[i][j] = true;
				}
			}
		}
		while (!pile.empty()) {
			int sz = static_cast<int>(pile.size());
			i = 0;
			while (i < sz) {
				iip current = pile.front();
				pile.pop();
				int oi = current.first.first;
				int oj = current.first.second;
				int w = current.second;
				for (j = 0; j < 4; ++j) {
					int ni = oi + X[j];
					int nj = oj + Y[j];
					if (isvalid(ni, nj) && !visited[ni][nj]) {
						distances[ni][nj] = w + 1;
						visited[ni][nj] = true;
						pile.push(make_pair(make_pair(ni, nj), w + 1));
					}
				}
				++i;
			}
		}
		return distances;
	}
};