#define pb push_back
class Solution {
public:
	vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
		int n1 = int(arr1.size());
		int n2 = int(arr2.size());
		int n3 = int(arr3.size());
		if (n1 == 0 || n2 == 0 || n3 == 0)return vector<int>{};
		int i = 0, j = 0, k = 0;
		vector<int> res;
		while (i < n1&&j < n2&&k < n3) {
			if (arr1[i] < arr2[j]) {
				++i;
			}
			else if (arr1[i] > arr2[j]) {
				++j;
			}
			else if (arr1[i] < arr3[k]) {
				++i;
			}
			else if (arr1[i] > arr3[k]) {
				++k;
			}
			else if (arr2[j] < arr3[k]) {
				++j;
			}
			else if (arr2[j] > arr3[k]) {
				++k;
			}
			else {
				res.pb(arr1[i]);
				++i, ++j, ++k;
			}
		}
		return res;
	}
};

#define pb push_back
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		int n = int(nums1.size());
		if (n == 0)return vector<int>{};
		int m = int(nums2.size());
		if (m == = 0)return vector<int>{};
		unordered_map<int, int> h;
		for (int i = 0; i < m; ++i) {
			h[nums2[i]] = i;
		}
		stack<int> ms;
		vector<int> nxtgreater(m, -1);
		int j = m - 1;
		while (j >= 0) {
			while (!ms.empty() && nums2[j] >= nums2[ms.top()]) {
				ms.pop();
			}
			if (!ms.empty())nxtgreater[j] = ms.top();
			ms.push(j);
			--j;
		}
		vector<int> res;
		int i = 0;
		while (i < n) {
			int pos = nxtgreater[h[nums1[i]]];
			if (pos == -1)res.pb(-1);
			else res.pb(nums2[pos]);
			++i;
		}
		return res;
	}
};