#include <iostream>
#include <memory>
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int, int> ip;
#define HOUSES 50
template<class T> T MyMin(const T& x, const T& y) {
	return (x > y) ? (y) : (x);
}
namespace std {
	template<class T> struct _Unique_if {
		typedef unique_ptr<T> _Single_object;
	};

	template<class T> struct _Unique_if<T[]> {
		typedef unique_ptr<T[]> _Unknown_bound;
	};

	template<class T, size_t N> struct _Unique_if<T[N]> {
		typedef void _Known_bound;
	};

	template<class T, class... Args>
	typename _Unique_if<T>::_Single_object
		make_unique(Args&&... args) {
		return unique_ptr<T>(new T(std::forward<Args>(args)...));
	}

	template<class T>
	typename _Unique_if<T>::_Unknown_bound
		make_unique(size_t n) {
		typedef typename remove_extent<T>::type U;
		return unique_ptr<T>(new U[n]());
	}

	template<class T, class... Args>
	typename _Unique_if<T>::_Known_bound
		make_unique(Args&&...) = delete;
}
class Graph {
private:
	struct solution {
		int start, end, diameter;
		solution(int a, int b, int c) :start(a), end(b), diameter(c) {}
		bool operator<(const struct solution&obj) const {
			return (this->start < obj.start);
		}
	};
	static bool cmp(const struct solution& a, const struct solution& b) {
		return (a < b);
	}
	vector<solution> res;
	int V;
	std::unique_ptr<list<ip>[]> adj;
	std::unordered_map<int, int> in, out;
public:
	Graph() {
		this->V = -1;
	}
	Graph(int a) :V(a) {
		adj = make_unique<list<ip>[]>(HOUSES);
	}
	void ae(int u, int v, int w) {
		adj[u].pb(mp(v, w));
		++out[u], ++in[v];
	}
	void dfsUtil(int src, std::vector<bool>& visited, int& dest, int& minDiameter) {
		visited.at(src) = true;
		dest = src;
		for (std::list<ip>::const_iterator ptr = this->adj.get()[src].begin(); ptr != this->adj.get()[src].end(); ++ptr) {
			if (!visited.operator[]((*ptr).first)) {
				minDiameter = MyMin<int>(minDiameter, (*ptr).second);
				(*this).dfsUtil(ptr->first, visited, dest, minDiameter);
			}
		}
		return;
	}
	void solve() {
		std::vector<bool> visited(HOUSES, false);
		for (const auto& x : out) {
			if (x.second == 1 && in[x.first] == 0 && !visited.at(x.first)) {
				int dest = -1;
				int diam = INT_MAX;
				this->dfsUtil(x.first, visited, dest, diam);
				res.pb({ x.first,dest,diam });
			}
		}
		int n = (int)res.size();
		cout << n << '\n';
		if (n > 0) {
			std::sort(begin(res), end(res), Graph::cmp);
			for (const auto& x : res) {
				cout << x.start << ' ' << x.end << ' ' << x.diameter << '\n';
			}
		}
		return;
	}

};
int main() {
	//code
	int q;
	cin >> q;
	while (q--) {
		int n, p;
		cin >> n >> p;
		Graph G(n);
		while (p--) {
			int u, v, d;
			cin >> u >> v >> d;
			G.ae(u, v, d);
		}
		G.solve();
	}
	return 0;
}