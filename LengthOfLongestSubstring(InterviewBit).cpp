#define CHARS 255
int Solution::lengthOfLongestSubstring(string A) {
	int l = static_cast<int>(A.length());
	if (l < 2)return l;
	int h[CHARS + 1] = { 0 };
	int start = 0, end = -1, i = 0;
	int sol = 0;
	while (i < l) {
		char x = A.at(i);
		if (h[x] == 0) {
			end = i;
			int dist = end - start + 1;
			if (dist > sol)sol = dist;
		}
		else {
			while (h[x] == 1) {
				char y = A.at(start++);
				--h[y];
			}
		}
		++h[x];
		++i;
	}
	return sol;
}