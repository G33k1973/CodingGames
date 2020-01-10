#define pb push_back
class Solution {
protected:
	unordered_map<string, vector<string>> graph;
	vector<string> res;
	bool found;
	void dfs(int totlength, int currentlength, vector<string>& temp) {
		//cout<<temp.back()<<" "<<currentlength<<endl;
		if (totlength == currentlength) {
			//if(res.empty())res=temp;
			//else if (temp < res)
			res = temp;
			found = true;
			return;
		}
		auto it = graph.find(temp.back());
		if (it == end(graph))return;
		for (string& y : it->second) {
			if (y == "")continue;
			temp.pb(y);
			y = "";
			dfs(totlength, currentlength + 1, temp);
			if (found == true)return;
			y = temp.back();
			temp.pop_back();
		}
		return;
	}
public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		int n = int(tickets.size());
		if (n == 0)return res;
		if (n == 1)return vector<string>{tickets.front().front(), tickets.front().back()};
		for (int i = 0; i < n; ++i) {
			string src = tickets[i].front();
			string dst = tickets[i].back();
			graph[src].push_back(dst);
		}
		found = false;
		for (auto& x : graph) {
			sort(x.second.begin(), x.second.end());
		}
		vector<string> temp{ "JFK" };
		dfs(n + 1, 1, temp);
		return res;
	}
};