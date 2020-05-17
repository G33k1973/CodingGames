#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getCost' function below.
 *
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

 /*
  * For the weighted graph, <name>:
  *
  * 1. The number of nodes is <name>_nodes.
  * 2. The number of edges is <name>_edges.
  * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
  *
  */
using ll = long long int;
using ip = std::pair<int, int>;
using lp = std::pair<ll, int>;
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define sc static_cast<ll>
class Graph {
private:
	int V;
	ll res;
	std::list<ip> * adj;
public:
	Graph() {
		V = 0;
		adj = nullptr;
	}
	Graph(int n) :V(n) {
		this->adj = new std::list<ip>[this->V]();
		this->res = std::numeric_limits<ll>::max();
	}
	void ae(int u, int v, int w) {
		this->adj[u].pb(mp(v, w));
		this->adj[v].pb(mp(u, w));
	}
	ll Dijkstra(void) {
		vector<ll> dist(V, INF);
		if (V == 1)return 0LL;
		dist.at(0) = 0;
		std::set<lp> bst;
		bst.insert(mp(0, 0));
		while (!bst.empty()) {
			lp current = *bst.begin();
			bst.erase(bst.begin());
			int node = current.second;
			ll cum = current.first;
			std::list<ip>::const_iterator it;
			for (it = adj[node].begin(); it != adj[node].end(); ++it) {
				int v = (*it).first;
				int w = (*it).second;
				ll poscost = sc(w);
				ll diff = poscost - cum;
				ll actualweight = (diff < 0) ? (cum) : ((diff == 0) ? (cum) : (poscost));
				if (actualweight < dist[v]) {
					if (dist[v] != INF)bst.erase(bst.find(mp(dist[v], v)));
					dist[v] = actualweight;
					bst.insert(mp(actualweight, v));
				}
			}
		}
		return (dist.back() == INF) ? (-1) : (dist.back());
	}
	void dfs(int src, int dst, ll cum, vector<bool>& visited) {
		visited[src] = true;
		if (src == dst) {
			res = min(res, cum);
		}
		else {
			std::list<ip>::const_iterator it;
			for (it = adj[src].begin(); it != adj[src].end(); ++it) {
				int node = (*it).first;
				if (visited[node])continue;
				ll weight = sc((*it).second);
				if (weight > cum) {
					dfs(node, dst, weight, visited);
				}
				else if (weight <= cum) {
					dfs(node, dst, cum, visited);
				}
			}
		}
		visited[src] = false;
	}
	const ll& GetVal() const {
		return this->res;
	}
};

void getCost(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
	// Print your answer within the function and return nothing
	Graph G(g_nodes);
	int m = int(g_from.size());
	assert(g_from.size() == g_to.size() && g_to.size() == g_weight.size());
	for (int i = 0; i < m; ++i) {
		G.ae(g_from[i] - 1, g_to[i] - 1, g_weight[i]);
	}
	ll res = G.Dijkstra();
	/*
	vector<bool> visited(g_nodes,false);
	G.dfs(0,g_nodes-1,0LL,visited);
	ll res=G.GetVal();
	*/
	if (res == -1)cout << "NO PATH EXISTS\n";
	else cout << res << "\n";
}

int main()
{
	string g_nodes_edges_temp;
	getline(cin, g_nodes_edges_temp);

	vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

	int g_nodes = stoi(g_nodes_edges[0]);
	int g_edges = stoi(g_nodes_edges[1]);

	vector<int> g_from(g_edges);
	vector<int> g_to(g_edges);
	vector<int> g_weight(g_edges);

	for (int i = 0; i < g_edges; i++) {
		string g_from_to_weight_temp;
		getline(cin, g_from_to_weight_temp);

		vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

		int g_from_temp = stoi(g_from_to_weight[0]);
		int g_to_temp = stoi(g_from_to_weight[1]);
		int g_weight_temp = stoi(g_from_to_weight[2]);

		g_from[i] = g_from_temp;
		g_to[i] = g_to_temp;
		g_weight[i] = g_weight_temp;
	}

	getCost(g_nodes, g_from, g_to, g_weight);

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
