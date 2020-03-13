class TopVotedCandidate {
private:
	struct Cand {
		int id;
		int votes;
		int latest;
		Cand() {}
		Cand(int a, int b) :id(a) {
			votes = 1;
			latest = b;
		}
		Cand& Update(int b) {
			++votes;
			latest = b;
			return *this;
		}
		bool operator>(const struct Cand& obj)const {
			if (this->votes == obj.votes)
				return this->latest > obj.latest;
			return this->votes > obj.votes;
		}
	};
	struct Functor {
		bool operator()(const struct Cand& a, const struct Cand& b) {
			return a > b;
		}
	};
	typedef std::priority_queue<struct Cand, vector<struct Cand>, Functor> pq;
	map<int, Cand> bst;
public:
	TopVotedCandidate(vector<int>& persons, vector<int>& times) {
		vector<Cand> arr;
		unordered_map<int, int> h;//key<-ID,value<-array index
		int i = -1;
		int n = int(persons.size());
		assert(n > 0);
		int m = int(times.size());
		assert(n == m);
		for (int j = 0; j < n; ++j) {
			int ID = persons[j];
			int latest = times[j];
			auto it = h.find(ID);
			if (it == end(h)) {
				++i;
				struct Cand current(ID, latest);
				arr.push_back(current);
				h[ID] = i;
			}
			else {
				arr[it->second].Update(latest);
			}
			vector<Cand> temp(arr.begin(), arr.end());
			sort(begin(temp), end(temp), Functor());
			bst[latest] = temp.front();
		}
	}

	int q(int t) {
		auto it = bst.lower_bound(t);
		if (it == end(bst))--it;
		else if (it->first > t) {
			--it;
		}
		return it->second.id;
	}
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */