class Solution {
public:
	string simplifyPath(string path) {
		int l = int(path.size());
		path += "^";
		++l;
		stack<string> ms;
		string sub = "";
		int i = 0;
		while (i < l) {
			char x = path[i];
			if (x == '^')break;
			if (x == '.') {
				int c = 0;
				int j = i;
				while (j < l) {
					if (path[j] == '.') {
						++c;
					}
					else if (path[j] == '/' || path[j] == '^')break;
					else {
						sub.push_back(path[j]);
					}
					++j;
				}
				if (c == 2 && sub.empty()) {
					if (!ms.empty())ms.pop();
				}
				else if (c == 1 && sub.empty()) {

				}
				else {
					sub.insert(0, c, '.');
					ms.push(sub);
					sub = "";
				}
				i = j;
			}
			else if (x == '/') {
				++i;
				continue;
			}
			else {
				int j = i;
				while (j < l) {
					if (path[j] == '/' || path[j] == '^')break;
					sub.push_back(path[j]);
					++j;
				}
				ms.push(sub);
				sub.clear();
				i = j;
			}
		}
		if (ms.empty())return "/";
		vector<string> res;
		while (!ms.empty()) {
			res.push_back(ms.top());
			ms.pop();
		}
		reverse(begin(res), end(res));
		string a = "/";
		for (string& x : res) {
			a += x;
			a += "/";
		}
		a.pop_back();
		return a;
	}
};