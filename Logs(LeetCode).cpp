#define pb push_back
class Solution {
private:
	vector<string> result;
	struct ll {
		string s, id;
		vector<string> arr;
		ll() {}
		ll(string a, string b, vector<string>& c) :s(a), id(b) {
			this->arr.assign(c.begin(), c.end());
		}
		bool operator<(const struct ll& obj) const {
			int n = static_cast<int>(arr.size());
			int m = static_cast<int>(obj.arr.size());
			int i = 0, j = 0;
			while (i < n&&j < m) {
				if (arr[i] < obj.arr[j])return 1;
				if (arr[i] > obj.arr[j])return 0;
				++i, ++j;
			}
			if (n == m)return (*this).id < obj.id;
			return n < m;
		}
	};
	struct Functor {
		bool operator()(const struct ll& a, const struct ll& b) {
			return a.operator<(b);
		}
	};
	vector<string> dl;
	vector<struct ll> A;
	void parse(string s) {
		string t(begin(s), end(s));
		s += " ";
		int l = int(s.size());
		int c = 0;
		string sub("");
		string id = "";
		vector<string> a;
		for (char& i : s) {
			if (i == ' ') {
				if (!sub.empty()) {
					if (c == 0) {
						++c;
						id = sub;
					}
					else {
						if (isdigit(sub.front())) {
							dl.push_back(t);
							return;
						}
						a.push_back(sub);
					}
					sub.clear();
				}
			}
			else sub += string(1, i);
		}
		struct ll current{t,id,a};
		A.emplace_back(std::move(current));
		return;
	}
public:
	vector<string> reorderLogFiles(vector<string>& logs) {
		int n = int(logs.size());
		if (n < 2)return logs;
		vector<string> result;
		for (string i : logs)parse(i);
		if (A.size() > 0) {
			std::sort(begin(A), end(A), Functor());
			std::vector<struct ll>::const_iterator ptr = begin(A);
			while (ptr != end(A)) {
				result.push_back(ptr->s);
				++ptr;
			}
		}
		if (dl.size() > 0) {
			result.insert(result.end(), dl.begin(), dl.end());
		}
		return result;
	}
};

#define pb push_back
class Solution {
protected:
	string temp;
	vector<string> res;
	void dfs(int n, int no, int nc) {
		if (n == no) {
			string a(temp);
			while (nc++ < n) {
				a += ")";
			}
			res.pb(a);
			return;
		}
		if (no == nc) {
			temp += "(";
			dfs(n, no + 1, nc);
			temp.pop_back();
		}
		else if (no > nc) {
			temp += "(";
			dfs(n, no + 1, nc);
			temp.pop_back();
			temp += ")";
			dfs(n, no, nc+1);
			temp.pop_back();
		}
	}
public:
	vector<string> generateParenthesis(int n) {
		dfs(n, 0, 0);
		return res;
	}
};