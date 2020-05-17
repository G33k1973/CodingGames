class Solution {
public:
	int maxSubarraySumCircular(vector<int>& A) {
		{
			vector<int>& v = A;
			int max_so_far = v[0];
			int max_end_here = v[0];
			int totalsum = v[0];
			int min_so_far = v[0];
			int min_end_here = v[0];
			for (int i = 1; i < v.size(); i++) {
				totalsum += v[i];
				max_end_here = max(max_end_here + v[i], v[i]);
				max_so_far = max(max_end_here, max_so_far);
				min_end_here = min(min_end_here + v[i], v[i]);
				min_so_far = min(min_so_far, min_end_here);
			}
			if (max_so_far < 0) {//means all element are negative
				return max_so_far;
			}
			return max(max_so_far, (totalsum - min_so_far));
		}
		int n = int(A.size());
		if (n == 0)return 0;
		if (n == 1)return A[0];
		A.insert(A.end(), A.begin(), A.end());
		int res = INT_MIN;
		for (int i = 0; i < n; ++i) {
			int curmax = A[i], current = A[i];
			for (int j = i + 1; j < i + n; ++j) {
				current = max(current + A[j], A[j]);
				curmax = max(curmax, current);
			}
			res = max(res, curmax);
		}
		return res;
	}
};