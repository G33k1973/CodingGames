typedef pair<int, int> ip;
typedef pair<ip, int> iip;
#define mp make_pair
#define pb push_back
class Solution {
protected:
	int n, m;
public:
	int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		this->n = static_cast<int>(maze.size());
		if (n == 0)return -1;
		this->m = static_cast<int>(maze.front().size());
		if (m == 0)return -1;
		ip target{ destination.front(),destination.back() };
		iip st{ {start.front(),start.back()},0 };
		std::queue<iip> pile;
		pile.push(st);
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		visited[st.first.first][st.first.second] = true;
		while (!pile.empty()) {
			int sz = static_cast<int>(pile.size());
			int i = 0;
			while (i < sz) {
				iip current = pile.front();
				pile.pop();
				int oi = current.first.first;
				int oj = current.first.second;
				int weight = current.second;
				//cout<<weight<<endl;
				if (oi == target.first&&oj == target.second) {
					return weight;
				}
				for (int j = 0; j < 4; ++j) {
					if (j == 0) {
						//roll Left
						int k = oj;
						while (k >= 0 && maze[oi][k] == 0) {
							--k;
						}
						++k;
						//cout<<k<<endl;
						if (k != oj && !visited[oi][k]) {
							int distance = oj - k;
							visited[oi][k] = true;
							pile.push(mp(mp(oi, k), weight + distance));
						}
					}
					else if (j == 1) {
						//roll Right
						int k = oj;
						while (k < m&&maze[oi][k] == 0) {
							++k;
						}
						--k;
						//cout<<k<<endl;
						if (k != oj && !visited[oi][k]) {
							int distance = k - oj;
							visited[oi][k] = true;
							pile.push(mp(mp(oi, k), weight + distance));
						}
					}
					else if (j == 2) {
						//roll Up
						int k = oi;
						while (k >= 0 && maze[k][oj] == 0) {
							--k;
						}
						++k;
						//cout<<k<<endl;
						if (k != oi && !visited[k][oj]) {
							int distance = oi - k;
							visited[k][oj] = true;
							pile.push(mp(mp(k, oj), weight + distance));
						}
					}
					else if (j == 3) {
						//roll Down
						int k = oi;
						while (k < n&&maze[k][oj] == 0) {
							++k;
						}
						--k;
						//cout<<k<<endl;
						if (k != oi && !visited[k][oj]) {
							int distance = k - oi;
							visited[k][oj] = true;
							pile.push(mp(mp(k, oj), weight + distance));
						}
					}
				}
				++i;
			}
		}
		return -1;
	}
};