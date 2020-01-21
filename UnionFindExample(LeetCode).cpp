class Solution {
protected:
	int n;
	vector<int> parent;
	int find(int i) {
		if (parent[i] == -1)return i;
		return find(parent[i]);
	}
	void merge(int a, int b) {
		int pa = a;
		int pb = b;
		if (pa != pb) {
			parent[pa] = pb;
		}
		return;
	}
public:
	int findCircleNum(vector<vector<int>>& M) {
		n = int(M.size());
		if (n == 0)return 0;
		if (n == 1)return 1;
		parent.assign(n, -1);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i==j||M[i][j] == 0)continue;
				merge(find(i), find(j));
			}
		}
		return count(begin(parent), end(parent), -1);
	}
};

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int n = int(nums.size());
		if (n == 0)return 0;
		int low = 0, high = n - 1;
		while (low <= high) {
			int middle = low + (high - low) / 2;
			if (nums[middle] == target)return target;
			if (nums[middle] > target) {
				if (middle == 0)return 0;
				else if (nums[middle - 1] < target)return middle;
				high = middle - 1;
			}
			else if (nums[middle] < target) {
				if (middle == (n - 1))return n;
				else if (nums[middle + 1] > target)return middle + 1;
				low = middle + 1;
			}
		}
		return -1;
	}
};