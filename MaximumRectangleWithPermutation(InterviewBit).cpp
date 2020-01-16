int Solution::solve(vector<vector<int> > &A) {
	//Traverse along with row and within for loop in column
	int n = A.size(), m = A[0].size();//n: height, m :width
	int count[n][m];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 0) count[j][i] = A[j][i];
			else if (A[j][i] == 1) count[j][i] = count[j - 1][i] + 1;
			else count[j][i] = 0;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {// //count[i] pointer to ith row
		sort(count[i], count[i] + m);
		int maxrow = count[i][0] * m;
		for (int j = 1; j < m; j++) {
			maxrow = max(maxrow, count[i][j] * (m - j));
		}
		ans = max(ans, maxrow);
	}
	return ans;
}
#define pb push_back
vector<int> Solution::solve(int A, int B) {
	long long a1, a2;
	a1 = 0;
	long long sz = A;
	for (int i = 0; i <= B; i++) {
		long long add = (1ll << i);
		if (i == B) {
			a1 = min(sz, (1ll << i));
		}
		sz = max((long long)0, sz - add);
		if (sz == 0)break;
	}
	vector<long long>ctr;
	sz = A;
	int idx = 0;
	while (sz) {
		// cout<<idx<<" "<<v<<endl;
		if ((1 << idx) < sz) {
			ctr.push_back((1ll << idx));
			sz -= (1ll << idx);
		}
		else {
			ctr.push_back(sz);
			sz = 0;
		}
		idx++;
	}
	// for(int i=0;i<ctr.size();i++)
	//     cout<<i<<" "<<ctr[i]<<"\n";
	a2 = ctr.back();
	idx = 1;
	int ridx = ctr.size() - 2;
	while (idx <= B) {
		a2 = ceil(a2 / 2.0);
		idx++;
		ridx--;
	}

	// cout<<ridx<<" "<<a2<<endl;
	if (ridx >= 0)
		a2 += (ctr[ridx] - ceil(a2 / 2.0));
	else if (ridx != -1)
		a2 = 0;
	vector<int>ret;
	ret.push_back(a1);
	ret.push_back(a2);
	return ret;
}

int Solution::solve(vector<vector<int> > &A) {
	int n = static_cast<int>(A.size());
	if (n == 0)return 0;
	int m = static_cast<int>(A.front().size());
	if (m == 0)return 0;
	int i, j, u, v, res = 0;
	for (i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (A[i][j] == 0)continue;
			int rows = n - i, cols = m - j;
			int maxgain{ rows*cols };
			if (maxgain <= res)break;
			vector<int> temp(rows, 0);
			for (v = j; v < m; ++v) {
				int sub = 0;
				for (u = i; u < n; ++u) {
					temp[u - i] += A[u][v];
					if (temp[u - i] != (v - j + 1))break;
					sub += temp[u - i];
				}
				res = max(res, sub);
			}
		}
	}
	return res;
}