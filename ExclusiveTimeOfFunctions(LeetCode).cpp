class Solution {
protected:
	std::unordered_map<int, int> h;
	int t0 = INT_MIN;
	typedef std::pair<int, int> ip;
	std::stack<ip> pile;
#define pb push_back
	vector<int> r;
	struct Info {
		int ID, timeval;
		string state;
		Info() {}
		Info(int a, string b, int c) :ID(a), state(b), timeval(c) {}
	};
	struct Info  extract(string& s) {
		auto pos = s.find(':', 0);
		int ID = std::stoi(s.substr(0, pos));
		++pos;
		auto poso = pos;
		pos = s.find(':', poso);
		string state = s.substr(poso, pos - poso);
		++pos;
		int timeval = std::stoi(s.substr(pos));
		return Info(ID, state, timeval);
	}
public:
	vector<int> exclusiveTime(int n, vector<string>& logs) {
		if (n == 0)return r;
		for (string& x : logs) {
			struct Info temp = extract(x);
			//cout<<temp.ID<<" "<<temp.state<<" "<<temp.timeval<<"\n";
			if (temp.state.compare("end") == 0) {
				assert(!pile.empty());
				ip current = pile.top();
				pile.pop();
				h[temp.ID] += temp.timeval - current.second + 1;
				//cout<<current.first<<endl;
				if (!pile.empty())pile.top().second = temp.timeval + 1;
			}
			else if (temp.state.compare("start") == 0) {
				if (!pile.empty()) {
					ip current = pile.top();
					h[current.first] += temp.timeval - current.second;
				}
				pile.push(make_pair(temp.ID, temp.timeval));
			}
		}
		r.assign(n, 0);
		for (std::pair<const int, int>& x : h) {
			r[x.first] = x.second;
		}
		return r;
	}
};