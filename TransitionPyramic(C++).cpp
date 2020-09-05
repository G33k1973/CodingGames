class Solution {
protected:
	bool win = false;
	bool isgoodbrick(string& brick, string& bottom, int pos) {
		if (brick[0] == bottom[pos] && brick[1] == bottom[pos + 1])return true;
		return false;
	}
	bool dfs(string bottom, string top, unordered_set<string>& seen, vector<string>& allowed, int l, int pos) {
		if (l == 1) {
			win = !win;
			return true;
		}
		bool ans = false;
		for (auto& x : allowed) {
			//if (seen.count(x) > 0)continue;
			if (isgoodbrick(x, bottom, pos)) {
				top += x[2];
				//seen.insert(x);
				if (pos + 1 == l - 1) {
					ans = ans || dfs(top, "", seen, allowed, l - 1, 0);
					if (win)return win;
				}
				else {
					ans = ans || dfs(bottom, top, seen, allowed, l, pos + 1);
					if (win)return win;
				}
				top.pop_back();
				//seen.erase(x);
			}
		}
		return ans;
	}
public:
	bool pyramidTransition(string bottom, vector<string>& allowed) {
		const int l = int(bottom.size());
		/*
			S
		   SS
		  SSS
		 SSSS
		AAAAA
		*/
		unordered_set<string> seen;
		return dfs(bottom, "", seen, allowed, l, 0);
	}
};