class Solution {
public:
	string simplifyPath(string path) {
		path += "^";
		int l = int(path.size());
		stack<string> st;
		string sub = "";
		for (int i = 0; i < l; ++i) {
			if (path[i] == '/' || path[i] == '^') {
				continue;
			}
			if (path[i] == '.') {
				int c = 0;
				int j = i;
				while (j < l) {
					if (path[j] == '/' || path[j] == '^') {
						break;
					}
					if (path[j] == '.')++c;
					else {
						sub += string(1, path[j]);
					}
					++j;
				}
				if (c == 2 && sub.empty()) {
					if (!st.empty())st.pop();
					i = j;
					continue;
				}
				if (c == 1 && sub.empty()) {
					i = j;
					continue;
				}
				sub.insert(0, c, '.');
				st.push(sub);
				sub = "";
				i = j;
				continue;
			}
			int j = i;
			while (j < l) {
				if (path[j] == '/' || path[j] == '^')break;
				sub += string(1, path[j]);
				++j;
			}
			i = j;
			st.push(sub);
			sub = "";
			continue;
		}
		if (st.empty())return "/";
		vector<string> arr;
		while (!st.empty()) {
			arr.push_back(st.top());
			st.pop();
		}
		reverse(begin(arr), end(arr));
		string z = "/";
		for (auto& x : arr) {
			z += x;
			z += "/";
		}
		z.pop_back();
		return z;
	}
};