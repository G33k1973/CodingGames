class Solution {
public:

	bool isSimiliar(string& s1, string& s2) {
		int cnt = 0;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != s2[i]) {
				cnt++;
				if (cnt > 2)
					return false;
			}
		}
		return true;
	}

	int root(int i, vector<int>& parent) {
		while (i != parent[i]) {
			parent[i] = parent[parent[i]];
			i = parent[i];
		}
		return i;
	}

	int numSimilarGroups(vector<string>& A) {
		int len = A.size();
		vector<int> parent(len, 0);
		for (int i = 0; i < len; i++)
			parent[i] = i;


		// test case
		//["blw","bwl","wlb"]
		//["kccomwcgcs","socgcmcwkc","sgckwcmcoc","coswcmcgkc","cowkccmsgc","cosgmccwkc","sgmkwcccoc","coswmccgkc","kowcccmsgc","kgcomwcccs"]
		// about the union operation, 
		// parent[root(i)] = parent[root(j)] not parent[i] = j

		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				int pi = root(i, parent), pj = root(j, parent);
				if (pi != pj && isSimiliar(A[i], A[j])) {
					parent[pi] = pj;
				}
			}
		}

		// set<int> res;
		// for(int i = 0; i < len; i++)
		//     res.insert(root(i, parent));
		// return res.size();


		vector<bool> visited(len, false);
		int res = 0;
		for (int i = 0; i < len; i++) {
			if (!visited[root(i, parent)]) {
				visited[root(i, parent)] = true;
				res++;
			}
		}

		return res;
	}
};