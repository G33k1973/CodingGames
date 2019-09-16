#define pb push_back
class AutocompleteSystem {
protected:
	string built;
	struct order {
		string s;
		int freq;
		order(string& s, int a) {
			this->s = s;
			this->freq = a;
		}
		bool operator>(const struct order& obj) const {
			if (this->freq == obj.freq)return this->s < obj.s;
			return this->freq > obj.freq;
		}
	};
	static bool cmp(const struct order& a, const struct order& b) {
		return a > b;
	}
	vector<order> arr;
public:
	AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
		int l = (int)times.size();
		for (int i = 0; i < l; ++i) {
			order current{ sentences[i],times[i] };
			arr.pb(current);
		}
		std::sort(begin(arr), end(arr), AutocompleteSystem::cmp);
		built.clear();
	}

	vector<string> input(char c) {
		vector<string> res;
		if (c != '#') {
			built.pb(c);
			int tot = 0;
			for (auto& x : arr) {
				auto pos = x.s.find(built, 0);
				if (pos == 0) {
					++tot;
					res.pb(x.s);
				}
				if (tot == 3)break;
			}
		}
		else if (c == '#') {
			bool fd = false;
			for (auto& x : arr) {
				if (x.s == built) {
					++x.freq;
					fd = !fd;
					break;
				}
			}
			if (fd ^ 1) {
				order temp{ built,1 };
				arr.pb(temp);
			}
			built.clear();
			std::sort(begin(arr), end(arr), AutocompleteSystem::cmp);
		}
		return res;
	}
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */