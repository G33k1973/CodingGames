#define pb push_back
#define mp make_pair
class Solution {
private:
	vector<string> result;
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		int n = int(list1.size());
		int m = int(list2.size());
		if (n == 0 || m == 0)return result;
		unordered_map<string, int> h1, h2;
		for (int i = 0; i < n; ++i) {
			if (h1.count(list1[i]) == 0) {
				h1.insert(mp(list1[i], i));
			}
		}
		for (int i = 0; i < m; ++i) {
			if (h2.count(list2[i]) == 0) {
				h2.insert(mp(list2[i], i));
			}
		}
		map<int, vector<string>> bst;
		for (std::pair<const std::string, int>& i : h1) {
			if (h2.count(i.first) == 0)continue;
			int indexsum = h2.find(i.first)->second + i.second;
			bst[indexsum].pb(i.first);
		}
		std::map<int, vector<string>>::const_iterator ptr = bst.begin();
		result.assign(ptr->second.begin(), ptr->second.end());
		return result;
	}
};

class Solution {
public:
	int minScoreTriangulation(vector<int>& A) {
		int n = A.size();
		vector<vector<int>> dp(n, vector<int>(n, -1));

		for (int gap = 0; gap < n; gap++) {
			for (int i = 0, j = i + gap; i < n, j < n; i++, j++) {
				if (gap == 0 || gap == 1) {
					dp[i][j] = 0;
				}
				else
				{
					int ans = 1 << 30;
					for (int k = i + 1; k < j; k++) {
						ans = min(ans, A[i] * A[k] * A[j] + dp[i][k] + dp[k][j]);

						dp[i][j] = ans;
					}
				}

			}
		}

		return dp[0][n - 1];

	}
};