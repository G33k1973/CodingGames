struct Match {
	int iw, jb, dist;
	Match() {
		this->iw = this->jb = this->dist = -1;
	}
	Match(int i, vector<int>& work, int j, vector<int>& bike) {
		iw = i;
		jb = j;
		dist = abs(work[0] - bike[0]) + abs(work[1] - bike[1]);
	}
};

struct Functor {
	bool operator()(const Match& a, const Match& b) {
		if (a.dist == b.dist&&a.iw == b.iw)return a.jb > b.jb;
		if (a.dist == b.dist)return a.iw > b.iw;
		return a.dist > b.dist;
	}
};

using pq = std::priority_queue<Match, vector<Match>, Functor>;

class Solution {
public:
	vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
		int n = (int)workers.size();
		int m = (int)bikes.size();
		unordered_set<int> iw, ib;
		pq pile;
		int i, j;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				Match current{ i,workers[i],j,bikes[j] };
				pile.push(current);
			}
		}
		std::unordered_map<int, int> h;
		while (!pile.empty() && iw.size() < n) {
			Match current = pile.top();
			pile.pop();
			int windex = current.iw;
			if (iw.count(windex) > 0)continue;
			int bindex = current.jb;
			if (ib.count(bindex) > 0)continue;
			h[windex] = bindex;
			iw.insert(windex);
			ib.insert(bindex);
		}
		vector<int> res;
		for (i = 0; i < n; ++i) {
			res.push_back(h[i]);
		}
		return res;
	}
};