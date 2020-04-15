int threeSumClosest(vector<int> arr, int target) {
	// Your code goes here
	int n = int(arr.size());
	if (n < 3)return 0;
	pair<int, int> ans(INT_MAX, INT_MIN);
	int i, j;
	sort(begin(arr), end(arr));
	for (i = 0; i < n - 2; ++i) {
		int x = arr[i];
		for (j = i + 1; j < n - 1; ++j) {
			int y = arr[j];
			int z = target - x - y;
			auto it = std::lower_bound(begin(arr) + j + 1, end(arr), z);
			if (it == end(arr)) {
				int sum = x + y + arr.back();
				if (abs(sum - target) < ans.first)ans = make_pair(abs(sum - target), sum);
				else if (abs(sum - target) == ans.first) {
					if (sum > ans.second)ans.second = sum;
				}
			}
			else {
				if (*it == z)return target;
				int sum = x + y + *it;
				if (abs(sum - target) < ans.first)ans = make_pair(abs(sum - target), sum);
				else if (abs(sum - target) == ans.first) {
					if (sum > ans.second)ans.second = sum;
				}
				--it;
				if (int(it - begin(arr)) > j) {
					sum = x + y + *it;
					if (abs(sum - target) < ans.first)ans = make_pair(abs(sum - target), sum);
					else if (abs(sum - target) == ans.first) {
						if (sum > ans.second)ans.second = sum;
					}
				}
				//cout<<ans.first<<" "<<ans.second<<endl;
			}
		}
	}
	return ans.second;
}
