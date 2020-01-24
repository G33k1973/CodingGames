class Solution {
private:
	struct rectangle {
		int xbl, ybl, xur, yur;
		rectangle(){}
		rectangle(int a,int b,int c,int d):xbl(a),ybl(b),xur(c),yur(d){}
		bool operator<(const struct rectangle& ob) const {
			if (xbl == ob.xbl)return ybl < ob.ybl;
			return xbl < ob.xbl;
		}
	};
	static bool comp(const struct rectangle& rec1, const struct rectangle& rec2) {
		return rec1 < rec2;
	}
	vector<struct rectangle> arr;
public:
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		rectangle REC1{ rec1[0],rec1[1],rec1[2],rec1[3] };
		rectangle REC2{ rec2[0],rec2[1],rec2[2],rec2[3] };
		vector<struct rectangle> arr;
		arr.push_back(REC1);
		arr.push_back(REC2);
		sort(begin(arr), end(arr), Solution::comp);
		if (arr[0].xur <= arr[1].xbl)return false;
		if (arr[0].yur <= arr[1].ybl)return false;
		if (arr[0].ybl >= arr[1].yur)return false;
		return true;
	}
};

class Solution {
public:
	vector<int> partitionLabels(string S) {
		vector<int> index(26, -1);
		int l = int(S.size());
		if (l == 0)return vector<int>{0};
		if (l == 1)return vector<int>{1};
		for (int i = 0; i < l; ++i) {
			index[S[i] - 'a'] = i;
		}
		int jmax = -1, start = 0;
		vector<int> res;
		for (int i = 0; i < l; ++i) {
			if (jmax == -1)jmax = index[S[i] - 'a'];
			if (i == jmax) {
				res.push_back(i - start + 1);
				start = i + 1;
				jmax = -1;
				continue;
			}
			int currentmaxindex = index[S[i] - 'a'];
			if (currentmaxindex > jmax)jmax = currentmaxindex;
		}
		return res;
	}
};