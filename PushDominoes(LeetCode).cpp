class Solution {
public:
	string pushDominoes(string dominoes) {
		const int l = int(dominoes.size());
		vector<int> ix;
		for (int i = 0; i < l; ++i) {
			if (dominoes[i] == '.')continue;
			ix.push_back(i);
		}
		//
		const int n = int(ix.size());
		if (n == 0)return std::move(dominoes);
		int i = 0;
		int j = 0;
		while (i < n) {
			char x = dominoes.at(ix[i]);
			if (x == 'L') {
				int left = j, right = ix[i];
				while (j <= right) {
					dominoes[j] = 'L';
					++j;
				}
				j = right + 1;
			}
			else if (x == 'R') {
				int right = ix[i];
				if (i == n - 1) {
					while (right < l)dominoes[right++] = 'R';
				}
				else {
					char xx = dominoes.at(ix[i + 1]);
					if (xx == 'R') {
						int rright = ix[i + 1] - 1;
						while (right <= rright)dominoes[right++] = 'R';
					}
					else {
						int rright = ix[i + 1];
						j = rright + 1;
						while (right < rright) {
							dominoes[right++] = 'R';
							dominoes[rright--] = 'L';
						}
					}
				}
			}
			++i;
		}
		return dominoes;
	}
};