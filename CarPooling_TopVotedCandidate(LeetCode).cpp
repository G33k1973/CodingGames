class TopVotedCandidate {
private:
	struct Candidate {
		int id, lasttime, freq;
		Candidate() {}
		Candidate(int a, int b) {
			id = a, lasttime = b, freq = 1;
		}
		Candidate& update(int t) {
			++this->freq;
			this->lasttime = t;
			return *this;
		}
		bool operator>(const struct Candidate& ob) const {
			if (freq == ob.freq)return lasttime > ob.lasttime;
			return freq > ob.freq;
		}
	};
	unordered_set<int> seen;
	map<int, vector<Candidate>> bst;
public:
	TopVotedCandidate(vector<int>& persons, vector<int>& times) {
		int n = int(persons.size());
		int m = int(times.size());
		assert(n == m);
		vector<struct Candidate> arr;
		for (int i = 0; i < n; ++i) {
			int ID = persons[i];
			if (seen.count(ID) == 0) {
				struct Candidate current(ID, times[i]);
				arr.push_back(current);
				seen.insert(ID);
			}
			else {
				for (Candidate& x : arr) {
					if (x.id == ID) {
						x.update(times[i]);
						break;
					}
				}
			}
			sort(begin(arr), end(arr), [&](const struct Candidate& a, const struct Candidate& b) {return a > b; });
			bst[times[i]] = arr;
		}
	}

	int q(int t) {
		auto it = bst.lower_bound(t);
		if (it == end(bst)) {
			return prev(end(bst), 1)->second.front().id;
		}
		if (it->first == t || it == begin(bst)) {
			return it->second.front().id;
		}
		--it;
		return it->second.front().id;
	}
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
//[num_passengers, start_location, end_location]
class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		int n = static_cast<int>(trips.size());
		if (n == 0)return true;
		if (n == 1) {
			return trips.front().front() <= capacity;
		}
		std::sort(begin(trips), end(trips), [&](const vector<int>& a, const vector<int>& b) {if (a[1] == b[1])return a[2] < b[2]; return a[1] < b[1]; });
		int total(0);
		int i = 0, j;
		vector<bool> visited(n, false);
		while (i < n) {
			j = i - 1;
			while (j >= 0) {
				if (visited[j]) {
					--j;
					continue;
				}
				if (trips[j][2] <= trips[i][1]) {
					total -= trips[j][0];
					visited[j] = true;
				}
				--j;
			}
			total += trips[i][0];
			if (total > capacity)return false;
			++i;
		}
		return true;
	}
};