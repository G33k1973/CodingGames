class Solution {
public:
	string alienOrder(vector<string>& words) {
		unordered_map<char, int> indegree;
		unordered_map<char, unordered_set<char>> g;

		for (string w : words) {
			for (char c : w) {
				indegree[c] = 0;
			}
		}

		for (int i = 0; i < words.size() - 1; i++) {
			string cur = words[i];
			string nex = words[i + 1];
			int len = min(cur.size(), nex.size());
			for (int j = 0; j < len; j++) {
				if (cur[j] != nex[j]) {
					if (g[cur[j]].find(nex[j]) == g[cur[j]].end()) {
						g[cur[j]].insert(nex[j]);
						indegree[nex[j]]++;
					}
					break;
				}
				if (j == len - 1 && cur.size() > nex.size())return "";
			}
		}

		string ans = "";
		queue<char> q;
		for (auto in : indegree) {
			if (in.second == 0)q.push(in.first);
		}

		while (!q.empty()) {
			char c = q.front();
			q.pop();
			ans += c;
			for (char n : g[c]) {
				indegree[n]--;
				if (indegree[n] == 0)q.push(n);
			}
		}
		return ans.size() == indegree.size() ? ans : "";
	}
};