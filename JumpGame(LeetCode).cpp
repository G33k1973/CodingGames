class Solution {
public:
	bool canJump(vector<int>& nums) {
		{
			int n = int(nums.size());
			if (n == 0)return false;
			if (n == 1)return true;
			int i = 0, pos = 0, j = 0;
			vector<bool> visited(n, false);
			visited[0] = true;
			while (i < n) {
				if (!visited[i])return false;
				j = min(n - 1, max(pos, i + nums[i]));
				if (j == n - 1)return true;
				int k = j;
				while (k >= 0) {
					if (!visited[k])visited[k] = true;
					else break;
					--k;
				}
				pos = j;
				++i;
			}
			return false;
		}
	}
};