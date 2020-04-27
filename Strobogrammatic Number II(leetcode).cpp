class Solution {
	vector<string> r;
	vector<char> gd{ '0','1','6','8','9' };
	unordered_map<char, char> h{ {'0','0'},{'1','1'},{'6','9'},{'9','6'},{'8','8'} };
	bool AreMirrors(string x) {
		string y(x);
		reverse(begin(x), end(x));
		for (char& ch : x) {
			ch = h[ch];
		}
		return x.compare(y) == 0;
	}
	bool isodd;
	void dfs(int ac, int c, string& temp) {
		if (ac == c) {
			stack<char> st;
			if (isodd) {
				for (int i = 0; i < c - 1; ++i)st.push(temp[i]);
			}
			else {
				for (int i = 0; i < c; ++i)st.push(temp[i]);
			}
			string b(temp);
			while (!st.empty()) {
				b.push_back(h[st.top()]);
				st.pop();
			}
			if (AreMirrors(b)) {
				r.push_back(b);
			}
			return;
		}
		for (int i = 0; i < 5; ++i) {
			temp.push_back(gd[i]);
			dfs(ac, c + 1, temp);
			temp.pop_back();
		}
	}
public:
	vector<string> findStrobogrammatic(int n) {
		if (n == 0)return r;
		if (n == 1) {
			r = vector<string>{ "0","1","8" };
			return r;
		}
		int ac = n / 2;
		isodd = (n & 1);
		if (isodd)++ac;
		for (int i = 1; i < 5; ++i) {
			string temp(1, gd[i]);
			dfs(ac, 1, temp);
		}
		return r;
	}
};