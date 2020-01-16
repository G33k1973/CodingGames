class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int n = int(nums.size());
		if (n == 0)return n;
		if (target < nums.front())return 0;
		if (target > nums.back())return n;
		int low = 0, high = n - 1;
		while (low <= high) {
			int middle = low + (high - low) / 2;
			if (nums[middle] == target)return middle;
			if (nums[middle] > target) {
				high = middle - 1;
			}
			else if (nums[middle] < target) {
				low = middle + 1;
			}
		}
		return max(low, high);
	}
};

class Solution {
protected:
	std::vector<int> parent;
	int find(int i) {
		if (parent[i] == -1)return i;
		return find(parent[i]);
	}
	void merge(int i, int j) {
		int a = find(i), b = find(j);
		if (a == b)return;
		parent[a] = b;
	}
	int n;
public:
	int findCircleNum(vector<vector<int>>& M) {
		n = int(M.size());
		if (n == 0)return 0;
		int m = int(M.front().size());
		assert(n == m);
		parent.assign(n, -1);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i != j && M[i][j]) {
					merge(i, j);
				}
			}
		}
		//for(auto& x: parent)cout<<x<<" ";
		return count(begin(parent), end(parent), -1);
	}
};