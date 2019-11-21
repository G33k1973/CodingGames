#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
#define M 100000007
#define C 243ULL
#define ms(a,b) (((a%M)+(b%M))%M)

int X[] = { +1,-1,0,0 };
int Y[] = { 0,0,+1,-1 };

ll mul(ll a, ll b) {
	ll res = 0;
	a = a % M;
	while (b > 0) {
		if (b & 1) {
			res = ms(res, a);
		}
		b >>= 1;
		a = (a << 1) % M;
	}
	return res % M;
}

unordered_map<char, ll> h{ {'L',76ULL},{'R',82ULL},{'U',85ULL},{'D',68ULL} };

struct State {
	string path;
	string s;
	int I;
	int N;
	State() {
		s = "";
		path = "";
		I = -1;
	}
	State(string& a, int i, int j, int N, string&b, char x) {
		this->N = N;
		this->I = i * N + j;
		s = a;
		path = b;
		if (x != ' ')path += string(1, x);
	}
	ll Get_checksum() {
		ll checksum = 0;
		for (auto& x : path) {
			checksum = mul(checksum, C);
			checksum = ms(checksum, h[x]);
		}
		return checksum;
	}
};

unordered_set<string> seen;

bool isgood(int i, int j, int N) {
	return(i >= 0 && j >= 0 && i < N&&j < N);
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	cin >> n;
	string s0(n*n, '0');
	string s1(n*n, '0');
	int i, j;
	pair<int, int> posblank;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			cin >> s0[i*n + j];
			if (s0[i*n + j] == 'W')posblank = make_pair(i, j);
		}
	}
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			cin >> s1[i*n + j];
		}
	}
	//cout<<s0<<" "<<s1<<endl;
	string path("");
	State temp(s0, posblank.first, posblank.second, n, path, ' ');
	std::queue<State> pile;
	pile.push(temp);
	seen.insert(s0);
	bool stoplevel = false;
	ll res = 0;
	while (!pile.empty()) {
		int sz = int(pile.size());
		i = 0;
		while (i < sz) {
			State latest = pile.front();
			pile.pop();
			string olds = latest.s;
			int oI = latest.I;
			string oldpath = latest.path;
			if (olds == s1) {
				if (!stoplevel)stoplevel = true;
				res = latest.Get_checksum();
				break;
			}
			int oi = oI / n;
			int oj = oI % n;
			for (int u = 0; u < 4; ++u) {
				int ni = oi + X[u];
				int nj = oj + Y[u];
				if (isgood(ni, nj, n)) {
					int nI = ni * n + nj;
					string ts(olds);
					switch (u) {
					case 0:
					{
						//down is good:'U' move
						swap(ts[nI], ts[oI]);
						if (seen.count(ts) == 0) {
							seen.insert(ts);
							State newstate(ts, ni, nj, n, oldpath, 'U');
							pile.push(newstate);
						}
					}
					break;
					case 1:
					{
						//up is good:'D' move
						swap(ts[nI], ts[oI]);
						if (seen.count(ts) == 0) {
							seen.insert(ts);
							State newstate(ts, ni, nj, n, oldpath, 'D');
							pile.push(newstate);
						}
					}
					break;
					case 2:
					{
						//right is good:'L' move
						swap(ts[nI], ts[oI]);
						if (seen.count(ts) == 0) {
							seen.insert(ts);
							State newstate(ts, ni, nj, n, oldpath, 'L');
							pile.push(newstate);
						}
					}
					break;
					case 3:
					{
						//left is good:'R' move
						swap(ts[nI], ts[oI]);
						if (seen.count(ts) == 0) {
							seen.insert(ts);
							State newstate(ts, ni, nj, n, oldpath, 'R');
							pile.push(newstate);
						}
					}
					break;
					default:
						break;
					}
				}
			}
			++i;
		}
		if (stoplevel)break;
	}
	cout << res;
	return 0;
}
