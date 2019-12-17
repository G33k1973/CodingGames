#define pb push_back
class Solution {
private:
	vector<string> rev1, rev2;
public:
	int compareVersion(string version1, string version2) {
		int n = int(version1.length());
		int m = int(version2.length());
		if (n == 0 && m > 0)return -1;
		if (m == 0 && n > 0)return 1;
		if (m == 0 && n == 0)return 0;
		if (rev1.empty() ^ 1)rev1.clear();
		if (rev2.empty() ^ 1)rev2.clear();
		int i = 0;
		version1 += ".";
		version2 += ".";
		++n, ++m;
		string sub = "";
		while (i < n) {
			char x = version1.at(i);
			if (x == '.') {
				if (sub.empty()) {
					sub = string(1, '0');
				}
				rev1.pb(sub);
				sub = "";
			}
			else {
				if (x != '0' || sub.empty() == false) {
					sub.pb(x);
				}
			}
			++i;
		}
		i -= n;
		while (i < m) {
			char x = version2.at(i);
			if (x == '.') {
				if (sub.empty()) {
					sub = string(1, '0');
				}
				rev2.pb(sub);
				sub = "";
			}
			else {
				if (x != '0' || sub.empty() == false) {
					sub.pb(x);
				}
			}
			++i;
		}
		n = int(rev1.size());
		m = int(rev2.size());
		int j = 0;
		i = 0;
		while (i < n&&j < m) {
			string s1 = rev1[i];
			string s2 = rev2[j];
			//cout<<s1<<" "<<s2<<endl;
			if (s1.size() > s2.size())return 1;
			if (s1.size() < s2.size())return -1;
			if (s1.size() == s2.size()) {
				if (s1 > s2)return 1;
				if (s1 < s2)return -1;
			}
			++i, ++j;
		}
		while (i < n) {
			string s1 = rev1[i++];
			if (s1 != "0")return 1;
		}
		while (j < m) {
			string s2 = rev2[j++];
			if (s2 != "0")return -1;
		}
		return 0;
	}
};