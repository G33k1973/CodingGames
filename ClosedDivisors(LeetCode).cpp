using ll = long long int;
class Solution {
public:
	vector<int> closestDivisors(int num) {
		if (num == 1)return vector<int>{1, 2};
		if (num == 2)return vector<int>{2, 2};
		if (num == 3)return vector<int>{2, 2};
		int sq = sqrt(num);
		++sq;
		int n1 = num + 1, n2 = num + 2;
		pair<int, pair<int, int>> ans{ INT_MAX,{-1,-1} };
		for (int i = 2; i <= sq; ++i) {
			if (n1%i == 0) {
				int j = n1 / i;
				if (abs(i - j) < ans.first)ans = make_pair(abs(i - j), make_pair(i, j));
			}
			if (n2%i == 0) {
				int j = n2 / i;
				if (abs(i - j) < ans.first)ans = make_pair(abs(i - j), make_pair(i, j));
			}
		}
		return vector<int>{ans.second.first, ans.second.second};
	}
};