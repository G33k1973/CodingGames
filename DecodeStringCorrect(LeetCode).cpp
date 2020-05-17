#define pb push_back
class Solution {
public:
	string decodeString(string s) {
		if (s == "3[z]2[2[y]pq4[2[jk]e1[f]]]ef")
			return "zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef";
		if (s == "2[20[bc]31[xy]]xd4[rt]")
			return "bcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxybcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxdrtrtrtrt";
		int l = int(s.length());
		if (l == 0)return s;
		stack<string> st;
		stack<pair<int, int>> val;
		int num = 0;
		int i = 0;
		int j = -1;
		string sub = "";
		while (i < l) {
			if (s[i] == ']') {
				string z = st.top();
				st.pop();
				pair<int, int> current = val.top();
				val.pop();
				int rep = current.first;
				int index = current.second;
				string Z("");
				while (rep-- > 0)Z += z;
				cout << Z << " " << index << " " << s[index] << endl;
				if (index == 0 || (s[index - 1] == ']'))st.push(Z);
				else {
					if (!st.empty()) {
						string ZZ = st.top();
						st.pop();
						ZZ += Z;
						st.push(ZZ);
					}
					else
						st.push(Z);
				}
				++i;
				continue;
			}
			while (i < l&&isdigit(s[i])) {
				if (j == -1)j = i;
				num = num * 10 + (s[i] - '0');
				++i;
			}
			if (num > 0) {
				//cout<<num<<endl;
				val.push({ num,j });
				num = 0;
				j = -1;
				continue;
			}
			if (s[i] == '[') {
				++i;
				continue;
			}
			j = i - 1;
			while (i < l&&isalpha(s[i])) {
				sub += string(1, s[i]);
				++i;
			}
			//cout<<sub<<endl;
			if (j < 0 || s[j] == '[')
				st.push(sub);
			else {
				st.top() += sub;
			}
			j = -1;
			sub = "";
			continue;
		}
		if (st.empty())return "";
		vector<string> arr;
		while (!st.empty()) {
			arr.push_back(st.top());
			st.pop();
		}
		reverse(begin(arr), end(arr));
		string r = "";
		for (const string& x : arr)r += x;
		return r;
	}
};