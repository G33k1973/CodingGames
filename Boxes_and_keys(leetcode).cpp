class Solution {
protected:
	struct State {
		unordered_set<int> KEY;
		State() {}
		State(vector<int>& a) {
			for (auto& x : a)KEY.insert(x);
		}
	};
public:
	int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
		int n = int(status.size());
		if (n == 0)return 0;
		vector<bool> visited(n, false);//box with taken candies
		unordered_set<int> b;
		int m = int(initialBoxes.size());
		queue<struct State> pile;
		int res = 0;
		if (m > 0) {
			for (auto& x : initialBoxes) {
				if (status[x] == 1) {
					//cout<<"Box "<<x<<" candies "<<candies[x]<<endl;
					res += candies[x];
					visited[x] = true;
					vector<int> a;
					if (containedBoxes[x].size() > 0) {
						for (auto& y : containedBoxes[x])b.insert(y);
					}
					if (keys[x].size() > 0) {
						a = keys[x];
						State temp(a);
						pile.push(temp);
					}
				}
				else
					b.insert(x);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (status[i] == 1 && b.count(i) > 0 && visited[i] == false) {
				res += candies[i];
				visited[i] = true;
				vector<int> a;
				int x = i;
				//b.insert(i);
				//cout<<"Box "<<x<<" candies "<<candies[x]<<endl;
				if (containedBoxes[x].size() > 0) {
					for (auto& y : containedBoxes[x])b.insert(y);
				}
				if (keys[x].size() > 0) {
					a = keys[x];
					State temp(a);
					pile.push(temp);
				}
			}
		}
		while (!pile.empty()) {
			int sz = int(pile.size());
			int i = 0;
			int c = 0;
			while (i < sz) {
				struct State temp = pile.front();
				pile.pop();
				vector<int> taken;
				for (auto& x : temp.KEY) {
					//cout<<x<<endl;
					if (b.count(x) > 0 && !visited[x]) {
						visited[x] = true;
						++c;
						b.erase(x);
						res += candies[x];
						//cout<<"Box "<<x<<" candies "<<candies[x]<<endl;             
						vector<int> a;
						taken.push_back(x);
						if (containedBoxes[x].size() > 0) {
							for (auto& y : containedBoxes[x])b.insert(y);
						}
						if (keys[x].size() > 0) {
							a = keys[x];
							State temp(a);
							pile.push(temp);
						}
					}
				}
				for (auto& x : taken) {
					temp.KEY.erase(x);
				}
				if (temp.KEY.size() > 0)pile.push(temp);
				++i;
			}
			if (c == 0)break;
		}
		return res;
	}
};