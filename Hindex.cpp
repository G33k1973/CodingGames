class Solution {
public:
	int hIndex(vector<int>& citations) {
		int n = (int)citations.size();
		if (n == 0)return 0;
		int ans(0);
		int i = 0;
		sort(begin(citations), end(citations), greater<int>());
		int c = 0;
		while (i < n) {
			++c;
			int minVal = citations.at(i);
			/*
			if(c>=minVal){
				ans = min(c,minVal);
				break;
			}
			*/
			ans = max(ans, min(c, minVal));
			++i;
		}
		return ans;
	}
};