#define pb push_back
#define mp make_pair
#define LB 0
#define UB 1000
typedef pair<int, int> ip;
typedef pair<ip, int> iip;
class Solution {
protected:
	int X[4] = { 1,-1,0,0 };
	int Y[4] = { 0,0,-1,1 };
	bool isvalid(int i, int j) {
		return (i >= LB && j >= LB && i <= UB && j <= UB);
	}
	int w, b;
	vector<int> res;
public:
	vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
		w = static_cast<int>(workers.size());
		b = static_cast<int>(bikes.size());
		if (w == 0 || b == 0)return res;
		vector<bool> vb(b, false), vw(w, false);
		int i, j, tot(w);
		res.assign(w, -1);
		while (tot > 0) {
			iip current{ {-1,-1},INT_MAX };
			for (i = 0; i < w; ++i) {
				if (vw[i])continue;
				for (j = 0; j < b; ++j) {
					if (vb[j])continue;
					int dist = abs(bikes[j][1] - workers[i][1]) + abs(bikes[j][0] - workers[i][0]);
					if (dist < current.second || (dist == current.second&&i < current.first.first) ||
						(dist == current.second&&i == current.first.first&&j < current.first.second)) {
						current = { {i,j},dist };
					}
				}
			}
			vw[current.first.first] = 1;
			vb[current.first.second] = 1;
			res[current.first.first] = current.first.second;
			--tot;
			//cout<<tot<<endl;
		}
		return res;
	}
};

#define pb push_back
class Solution {
	int w, b;
	vector<int> res;
	struct Order {
		int iwork, ibike, distance;
		Order(){}
		Order(int a,int b,int c):iwork(a),ibike(b),distance(c){}
		bool operator<(const struct Order& ob)const {
			if (distance == ob.distance&&iwork == ob.iwork)return ibike < ob.ibike;
			if (distance == ob.distance)return iwork < ob.iwork;
			return distance < ob.distance;
		}
	};
	static bool comp(const struct Order& a, const struct Order& b) {
		return a < b;
	}
public:
	vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
		w = static_cast<int>(workers.size());
		b = static_cast<int>(bikes.size());
		if (w == 0 || b == 0)return res;
		res.assign(w, -1);
		vector<Order> arr;
		int i, j;
		for (i = 0; i < w; ++i) {
			for (j = 0; j < b; ++j) {
				int dist = abs(bikes[j][1] - workers[i][1]) + abs(bikes[j][0] - workers[i][0]);
				Order current(i, j, dist);
				arr.pb(current);
			}
		}
		std::sort(begin(arr), end(arr), Solution::comp);
		vector<bool> vw(w, false), vb(b, false);
		int n = static_cast<int>(arr.size());
		i = 0;
		int tot = w;
		while (i < n) {
			if (!vw[arr[i].iwork] && !vb[arr[i].ibike]) {
				vw[arr[i].iwork] = true;
				vb[arr[i].ibike] = true;
				res[arr[i].iwork] = arr[i].ibike;
				--tot;
				if (tot == 0)break;
			}
			++i;
		}
		return res;
	}
};
#define pb push_back
class Solution {
protected:
	enum Color{white,gray,black};
	vector<Color> color;
	std::unordered_map<int, vector<int>> graph;
	bool pathexists;
	bool dfs(int src, int dst) {
		color[src] = gray;
		bool ans = false;
		if (src == dst) {
			if(!pathexists)pathexists=true;
		}
		else {
			for (auto& x : graph[src]) {
				if (color[x] == white && dfs(x, dst))return true;
				if (color[x] == gray)return true;
			}
		}
		color[src] = white;
		return ans;
	}
public:
	bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
		if (n < 2)return false;
		unordered_set<int> seen;
		for (auto& x : edges) {
			graph[x[0]].pb(x[1]);
			if (x[0] == source && seen.count(source) == 0)seen.insert(source);
			if (x[1] == source && seen.count(source) == 0)seen.insert(source);
			if (x[0] == destination && seen.count(destination) == 0)seen.insert(destination);
			if (x[1] == destination && seen.count(destination) == 0)seen.insert(destination);
		}
		if (seen.size() != static_cast<std::size_t>(2))return false;
		auto it = graph.find(destination);
		if (it != end(graph))return false;
		color.assign(n, white);
		this->pathexists = false;
		bool outcome = this->dfs(source, destination);
		return (!outcome&&pathexists);
	}
};

