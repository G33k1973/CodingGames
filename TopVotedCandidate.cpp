class TopVotedCandidate {
protected:
	static int c;
	struct order {
		int ID, votes, counter;
		order() {
			ID = votes = -1;
		}
		order(int a) {
			this->ID = a;
			this->votes = 1;
			this->counter = c;
		}
		order& operator++() {
			++this->votes;
			this->counter = c;
			return *this;
		}
		bool operator>(const struct order& obj) const {
			if (obj.votes == this->votes)return this->counter > obj.counter;
			return this->votes > obj.votes;
		}
	};
	static bool cmp(const struct order& a, const struct order& b) {
		return a.operator>(b);
	}
	std::map<int, vector<order>> dp;
public:
	TopVotedCandidate(vector<int>& persons, vector<int>& times) {
		std::set<pair<int, int>> ms;
		for (int i = 0; i < (int)times.size(); ++i) {
			ms.insert(make_pair(times[i], persons[i]));
		}
		std::unordered_set<int> memo;
		for (auto& x : ms) {
			++c;
			int t_ = x.first;
			int id_ = x.second;
			vector<order> cur;
			if (dp.size())cur = std::prev(end(dp))->second;
			if (memo.count(id_) == 0) {
				order temp{ id_ };
				cur.push_back(temp);
				memo.insert(id_);
			}
			else {
				for (auto& y : cur) {
					if (y.ID == id_) {
						++y;
						break;
					}
				}
			}
			std::sort(begin(cur), end(cur), TopVotedCandidate::cmp);
			dp[t_] = cur;
		}
	}

	int q(int t) {
		auto it = dp.lower_bound(t);
		if (it == end(dp)) {
			--it;
		}
		if (it != begin(dp) && it->first > t)--it;
		return it->second.front().ID;
	}
};
int TopVotedCandidate::c = 0;
/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

 /**
  * Your TopVotedCandidate object will be instantiated and called as such:
  * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
  * int param_1 = obj->q(t);
  */