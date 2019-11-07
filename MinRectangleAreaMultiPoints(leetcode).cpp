class Solution {
protected:
	struct Rectangle {
		int x;
		set<int> y;
		bool operator<(const struct Rectangle& obj) const {
			return this->x < obj.x;
		}
		Rectangle() {}
		Rectangle(int a) :x(a) {}
		struct Rectangle& push(int y) {
			this->y.insert(y);
			return *this;
		}
	};
	static bool Comp(const struct Rectangle& obj, const struct Rectangle& obj2) {
		return obj < obj2;
	}
public:
	int minAreaRect(vector<vector<int>>& points) {
		int n = static_cast<int>(points.size());
		if (n < 4)return false;
		unordered_map<int, int> memo;
		vector<Rectangle> arr;
		for (auto& x : points) {
			int X = x.front();
			int Y = x.back();
			if (memo.count(X) == 0) {
				memo[X] = int(arr.size());
				struct Rectangle temp { X };
				arr.push_back(X);
				arr.back().push(Y);
			}
			else {
				int index = memo.find(X)->second;
				arr.at(index).push(Y);
			}
		}
		int res = INT_MAX;
		//cout<<int(arr.size())<<endl;
		sort(begin(arr), end(arr), Solution::Comp);
		for (int i = 0; i < (int)arr.size() - 1; ++i) {
			int X = arr[i].x;
			//cout<<X<<endl;
			auto ptr = arr[i].y.begin();
			while (ptr != prev(arr[i].y.end(), 1)) {
				int y1 = *ptr;
				auto ptr2 = std::next(ptr, 1);
				while (ptr2 != arr[i].y.end()) {
					int y2 = *ptr2;
					//cout<<y1<<" "<<y2<<endl;
					for (int j = i + 1; j < (int)arr.size(); ++j) {
						if (arr[j].y.find(y1) != end(arr[j].y) &&
							arr[j].y.find(y2) != end(arr[j].y)) {
							res = min(res, (arr[j].x - X)*(y2 - y1));
						}
					}
					++ptr2;
				}
				++ptr;
			}
		}
		return (res == INT_MAX) ? (0) : (res);
	}
};