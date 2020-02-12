#define pb push_back
class Solution {
private:
	vector<int> sol;
	struct Logs {
	public:
		int id, time;
		string ev;
		Logs() {}
		Logs(string& s) {
			auto pos = s.find(':', 0);
			id = std::stoi(s.substr(0, pos));
			++pos;
			ev = "";
			while (s[pos] != ':') {
				ev.push_back(s[pos++]);
			}
			++pos;
			time = std::stoi(s.substr(pos));
		}
	};
public:
	vector<int> exclusiveTime(int n, vector<string>& logs) {
		int l = static_cast<int>(logs.size());
		if (l == 0)return vector<int>{};
		unordered_map<int, int> hcum, hrun;
		int idprev, timeprev;
		string s = logs.front();
		auto pos = s.find(':', 0);
		idprev = std::stoi(s.substr(0, pos));
		Logs current(logs.front());
		idprev = current.id;
		timeprev = current.time;
		int i = 1;
		while (i < l) {
			cout << idprev << " " << timeprev << endl;
			Logs temp(logs.at(i++));
			int idrunning = temp.id;
			int timerunning = temp.time;
			if (temp.ev == "start") {
				int dtime = timerunning - timeprev;
				hcum[idprev] += dtime;
			}
			else if (temp.ev == "end") {
				if (idrunning == idprev)hcum[idrunning] += timerunning - timeprev + 1;
				else hcum[idrunning] += timerunning - timeprev;
			}
			idprev = idrunning;
			timeprev = timerunning;
		}
		int sz = int(hcum.size());
		vector<int> result(sz, 0);
		for (auto& x : hcum)result[x.first] = x.second;
		return result;
	}
};


#define pb push_back
class Solution {
private:
	vector<string> result;
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		//n words n-1 spaces
		int twchars = 0;
		int nwords = 0;
		int l = static_cast<int>(words.size());
		if (l == 0)return result;
		int i = 0;
		vector<string> current;
		for (auto& x : words) {
			int l = int(x.length());
			int cum{ twchars + l + nwords };
			if (cum == maxWidth) {
				current.pb(x);
				nwords++;
				twchars += l;
				string s = "";
				for (auto& y : current) {
					s += y;
					s += " ";
				}
				s.pop_back();
				result.pb(s);
				nwords = 0;
				current = vector<string>{};
				twchars = 0;
			}
			else if (cum < maxWidth) {
				current.pb(x);
				nwords++;
				twchars += l;
			}
			else if (cum > maxWidth) {
				int avspaces = maxWidth - twchars;
				int tspaces = (avspaces == 0) ? (0) : ((nwords == 1) ? (1) : (nwords - 1));
				int nspaces = (nwords == 1) ? (avspaces) : (avspaces / (nwords - 1));
				int rem = (nwords == 1) ? (0) : (avspaces % (nwords - 1));
				int c = 0;
				string s = "";
				for (auto& y : current) {
					s += y;
					if (tspaces == 0)break;
					s += string(nspaces, ' ');
					if (c==0 && rem > 0)s += string(rem, ' ');
					if (c == 0)++c;
					--tspaces;
				}
				result.pb(s);
				nwords = 1;
				current = vector<string>{ x };
				twchars = l;
			}
		}
		if (current.size()) {
			int avspaces = maxWidth - twchars;
			string s = "";
			int c = 0;
			int m = int(current.size());
			for (auto& y : current) {
				s += y;
				++c;
				if (c == m)s += string(avspaces, ' ');
				else {
					s += " ";
					--avspaces;
				}
			}
			result.pb(s);
		}
		return result;
	}
};