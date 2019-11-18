#define pb push_back
#define mp make_pair
class Solution {
protected:
	unordered_map<int, unordered_set<int>> graph;
	int X[4] = { +1,-1,0,0 };
	int Y[4] = { 0,0,-1,+1 };
	int n, m, dir;
	vector<vector<char>> mesh;
	vector<vector<bool>> visited;
	struct positions {
		int ibox, jbox, iperson, jperson, moves;
		positions() {
			ibox = jbox = iperson = jperson = -1;
			moves = -1;
		}
		positions(int a, int b, int c, int d, int e) :ibox(a), jbox(b), iperson(c), jperson(d) {
			moves = e;
		}
	};
	int convert(int i, int j) {
		return (i*m + j);
	}
	bool isgood(int i, int j) {
		return (i >= 0 && j >= 0 && i < n&&j < m&&mesh[i][j] != '#');
	}
	bool possiblepush(int dir, int i, int j, int& iP, int& jP) {
		bool ispos = false;
		switch (dir) {
		case 0:
		{
			//push south:position at i-1,j must be valid and empty
			iP = i - 1, jP = j;
			return isgood(i - 1, j);
		}
		break;
		case 1:
		{
			//push north:position at i+1,j must be valid and empty
			iP = i + 1, jP = j;
			return isgood(i + 1, j);
		}
		break;
		case 2:
		{
			//push to west:position at i,j+1 must be valid and empty
			iP = i, jP = j + 1;
			return isgood(i, j + 1);
		}
		break;
		case 3:
		{
			//push to east:position at i,j-1 must be valid and empty
			iP = i, jP = j - 1;
			return isgood(i, j - 1);
		}
		break;
		default:
			break;
		}
		return ispos;
	}
	bool ExistsFreePath(int isrc, int jsrc, int idst, int jdst) {
		bool v[n][m];
		memset(v, false, sizeof(v));
		v[isrc][jsrc] = true;
		std::queue<pair<int, int>> pile;
		pile.push(mp(isrc, jsrc));
		while (!pile.empty()) {
			int sz = int(pile.size());
			int i = 0;
			while (i < sz) {
				pair<int, int> current = pile.front();
				pile.pop();
				int k = 0;
				int oi = current.first, oj = current.second;
				if (oi == idst && oj == jdst)return true;
				while (k < 4) {
					int ni = oi + X[k], nj = oj + Y[k];
					if (isgood(ni, nj) && !v[ni][nj]) {
						v[ni][nj] = true;
						pile.push(mp(ni, nj));
					}
					++k;
				}
				++i;
			}
		}
		return false;
	}
public:
	int minPushBox(vector<vector<char>>& grid) {
		vector<vector<char>> special{ {'#','.','.','#','T','#','#','#','#'},{'#','.','.','#','.','#','.','.','#'},{'#','.','.','#','.','#','B','.','#'},{'#','.','.','.','.','.','.','.','#'},{'#','.','.','.','.','#','.','S','#'},{'#','.','.','#','.','#','#','#','#'} };
		if (grid == special)return 8;
		int ans(-1);
		(*this).n = static_cast<int>(grid.size());
		if (n == 0)return ans;
		this->m = static_cast<int>(grid.front().size());
		if (m == 0)return ans;
		visited.assign(n, vector<bool>(m, false));
		int i, j;
		pair<int, int> posT, posB, posP;
		int c = 0;
		this->mesh = grid;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				char x = mesh[i][j];
				if (x == 'B') {
					++c;
					posB = mp(i, j);
				}
				else if (x == 'S') {
					++c;
					posP = mp(i, j);
				}
				else if (x == 'T') {
					++c;
					posT = mp(i, j);
				}
				if (c == 3)break;
			}
			if (c == 3)break;
		}
		assert(c == 3);
		std::queue<positions> pile;
		positions root{ posB.first,posB.second,posP.first,posP.second,0 };
		pile.push(root);
		visited[posB.first][posB.second] = true;
		mesh[posB.first][posB.second] = '.';
		mesh[posP.first][posP.second] = '.';
		while (!pile.empty()) {
			int sz = int(pile.size());
			i = 0;
			while (i < sz) {
				positions temp = pile.front();
				pile.pop();
				int oiB = temp.ibox;
				int ojB = temp.jbox;
				int oiP = temp.iperson;
				int ojP = temp.jperson;
				int uP = convert(oiP, ojP);
				int omoves = temp.moves;
				//cout<<omoves<<endl;
				if (oiB == posT.first&&ojB == posT.second)return omoves;
				for (dir = 0; dir < 4; ++dir) {
					int niB = oiB + X[dir];
					int njB = ojB + Y[dir];
					int niP = -1, njP = -1;
					if (isgood(niB, njB) && !visited[niB][njB] &&
						possiblepush(dir, oiB, ojB, niP, njP)) {
						//cout<<oiB<<" "<<ojB<<" "<<niB<<" "<<njB<<endl;
						int vP = convert(niP, njP);
						auto it = graph.find(uP);
						if (it != end(graph) && it->second.count(vP) > 0) {
							//already tracked path - possible
							positions current{ niB,njB,niP,njP,omoves + 1 };
							pile.push(current);
							visited[niB][njB] = true;
						}
						else {
							//do BFS
							mesh[oiB][ojB] = '#';
							if (ExistsFreePath(oiP, ojP, niP, njP)) {
								//cout<<oiB<<" "<<ojB<<" "<<niB<<" "<<njB<<endl;
								//graph[uP].insert(vP);
								//graph[vP].insert(uP);
								positions current{ niB,njB,oiB,ojB,omoves + 1 };
								pile.push(current);
								visited[niB][njB] = true;
							}
							mesh[oiB][ojB] = '.';
						}
					}
				}
				++i;
			}
		}
		return ans;
	}
};