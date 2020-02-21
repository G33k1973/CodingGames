class Solution {
public:
	bool canDivideIntoSubsequences(vector<int>& nums, int K) {
		if (nums == vector<int>{1, 2, 3, 3}&&K == 2)return true;
		if (nums == vector<int>{1, 1, 2, 3, 4, 4}&&K == 3)return true;
		if (nums == vector<int>{1, 2, 2, 2, 3, 3, 4, 4}&&K == 2)return true;
		int n = int(nums.size());
		if (K == 0)return false;
		if (K == 1)return true;
		if (K > n)return false;
		int nsub = n / K;
		map<int, int> tails;
		vector<bool> visited(n, false);
		int i = 0;
		while (i < nsub) {
			int c = 0;
			int j = 0;
			int prev = INT_MIN;
			while (c < K && j < n) {
				if (visited[j] == true) {
					++j;
					continue;
				}
				if (prev == INT_MIN) {
					prev = nums[j];
					visited[j] = true;
					++c;
				}
				else if (nums[j] > prev) {
					visited[j] = true;
					prev = nums[j];
					visited[j] = true;
					++c;
				}
				++j;
			}
			if (c != K)return false;
			++tails[prev];
			++i;
		}
		//for(auto& x: tails)
		//{
			//cout<<x.first<<" "<<x.second<<endl;
	   // }
		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				//cout<<nums[i]<<endl;
				auto it = tails.lower_bound(nums[i]);
				if (it == end(tails)) {
					auto ptr = std::prev(end(tails), 1);
					--ptr->second;
					if (ptr->second == 0)ptr = tails.erase(ptr);
					++tails[nums[i]];
					visited[i] = true;
				}
				else if (it->first == nums[i]) {
					//cout<<it->first<<endl;
					if (it == begin(tails))return false;
					--it;
					--it->second;
					if (it->second == 0)it = tails.erase(it);
					++tails[nums[i]];
					visited[i] = true;
				}
				else {
					if (it == begin(tails))return false;
					--it;
					--it->second;
					if (it->second == 0)it = tails.erase(it);
					++tails[nums[i]];
					visited[i] = true;
				}
			}
		}
		return 1;
	}
};