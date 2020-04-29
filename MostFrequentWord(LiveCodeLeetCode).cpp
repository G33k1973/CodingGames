class Solution {
protected:
	struct FW {
		string word;
		int freq;
		FW() {}
		FW(string& a) :word(a) {
			this->freq = 1;
		}
		FW& Update() {
			++this->freq;
			return *this;
		}
		bool operator<(const struct FW& obj) const {
			if (this->freq == obj.freq)return this->word > obj.word;
			return this->freq < obj.freq;
		}
	};
	struct Functor {
		bool operator()(const struct FW& a, const struct FW& b) {
			return a.operator<(b);
		}
	};
	unordered_map<string, int> h;
	vector<struct FW> arr;
#define pb push_back
	typedef std::priority_queue<struct FW, vector<struct FW>, Functor> pq;
	pq pile;
	int i = -1;
	vector<string> r;
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		if (words.empty())return r;
		int n = int(words.size());
		if (n == 1)return words;
		for (string& x : words) {
			auto it = h.find(x);
			if (it == h.end()) {
				++i;
				h.insert(make_pair(x, i));
				struct FW current(x);
				arr.pb(current);
			}
			else {
				arr.at(it->second).Update();
			}
		}
		for (const struct FW& x : arr) {
			pile.push(x);
		}
		int m = int(pile.size());
		k = min(k, m);
		while (k-- > 0) {
			r.pb(pile.top().word);
			pile.pop();
		}
		return r;
	}
};