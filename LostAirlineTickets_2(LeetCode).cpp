#define pb push_back
class Solution {
private:
	bool out;
	vector<string> res;
	void dfs(unordered_map<string, vector<string>>& g, int n, vector<string>& temp) {
		if (int(temp.size()) == n) {
			res.assign(begin(temp), end(temp));
			out = true;
			return;
		}
		string source = temp.back();
		auto it = g.find(source);
		if (it == end(g))return;
		for (string& x : it->second) {
			if (x == "")continue;
			string oldstring{ x };
			x = "";
			temp.pb(oldstring);
			dfs(g, n, temp);
			if (out)return;
			x = oldstring;
			temp.pop_back();
		}
		return;
	}
public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		int n = int(tickets.size());
		if (n == 0)return res;
		if (n == 1)return tickets.front();
		std::unordered_map<string, vector<string>> graph;
		for (vector<string>& x : tickets) {
			graph[x.front()].pb(x.back());
		}
		for (std::pair<const std::string, vector<string>>& x : graph) {
			sort(x.second.begin(), x.second.end());
		}
		vector<string> List{ "JFK" };
		out = false;
		dfs(graph, n + 1, List);
		return res;
	}
};