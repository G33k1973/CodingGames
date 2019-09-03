class Solution {
public:
	vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
		vector<int> arr(length + 1, 0);
		for (auto& x : updates) {
			int i = x[0], j = x[1], k = x[2];
			arr[i] += k;
			arr[j + 1] -= k;
		}
		for (int i = 1; i < length; ++i) {
			arr[i] += arr[i - 1];
		}
		arr.pop_back();
		return arr;
	}
};