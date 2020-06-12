class Solution {
protected:
	struct HEIGHTS {
		vector<int> a;
		int h, num;
		HEIGHTS() {

		}
		HEIGHTS(vector<int>& b) :a(b) {
			h = a.front();
			num = a.back();
		}
		bool operator<(const struct HEIGHTS& obj) const {
			if (this->num == obj.num)return this->h < obj.h;
			return this->num < obj.num;
		}
	};
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		int n = people.size();
		sort(begin(people), end(people), [&](const vector<int>& a, const vector<int>& b)->bool {
			if (a[0] == b[0])return a[1] > b[1];
			return a[0] < b[0];
		});
		vector<int> pos(n, 0);
		for (int i = 0; i < n; i++) pos[i] = i;

		vector<vector<int>> out(n);
		for (vector<int> v : people)
		{
			int i = pos[v[1]];
			out[i] = v;
			pos.erase(pos.begin() + v[1]);
		}
		return out;
		return people;
	}
};