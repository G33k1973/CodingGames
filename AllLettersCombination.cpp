#define pb push_back
class Solution {
protected:
	vector<string> sol;
	int l;
	unordered_map<char, string> tel{ {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},
								   {'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} };
	void dfs(string& digits, int i, int l, string& temp) {
		if (i == l) {
			sol.pb(temp);
			return;
		}
		for (const auto& x : tel[digits[i]]) {
			temp.pb(x);
			dfs(digits, i + 1, l, temp);
			temp.pop_back();
		}
		return;
	}
public:
	vector<string> letterCombinations(string digits) {
		l = int(digits.size());
		if (l == 0)return sol;
		for (int i = 0; i<int(tel[digits[0]].size()); ++i) {
			string temp(1, tel[digits[0]][i]);
			dfs(digits, 1, l, temp);
		}
		return sol;
	}
};