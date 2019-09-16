#define pb push_back
class Solution {
protected:
	std::list<char> pile;
	int res;
public:
	int findMinStep(string board, string hand) {
		if (board.empty())return 0;
		unordered_map<char, int> h{ {'R',0},{'Y',0},{'B',0},{'G',0},{'W',0} };
		int l = (int)hand.length();
		for (int i = 0; i < l; ++i) {
			++h[hand.operator[](i)];
		}

		if (!pile.empty())pile.clear();
		for (auto& x : board)pile.pb(x);

		res = 0;
		int reso = res;

		while (1) {

			//seek 3 and store 2
			if (pile.empty())break;
			auto it = begin(pile);
			char p;
			int c = 0;
			int i = 0;
			while (it != end(pile)) {
				if (c == 0) {
					p = *it;
					c = 1;
					++it;
					continue;
				}
				if (*it == p) {
					++c;
					if (c == 3) {
						it = std::prev(it, 2);
						it = pile.erase(it);
						it = pile.erase(it);
						it = pile.erase(it);
						if (it != begin(pile)) {
							--it;
						}
						c = 0;
						continue;
					}
				}
				else if (*it != p) {
					p = *it;
					c = 1;
				}
				++it, ++i;
			}
			if (pile.empty())break;

			it = begin(pile);
			c = 0;
			i = 0;
			while (it != end(pile)) {
				if (c == 0) {
					p = *it;
					c = 1;
					++it;
					continue;
				}
				if (*it == p) {
					++c;
					if (c == 3) {
						it = std::prev(it, 2);
						it = pile.erase(it);
						it = pile.erase(it);
						it = pile.erase(it);
						if (it != begin(pile)) {
							--it;
						}
						c = 0;
						continue;
					}
				}
				else if (*it != p) {
					if (c == 2) {
						auto it2 = h.find(p);
						if (it2 != end(h)) {
							--it2->second;
							if (it2->second == 0)h.erase(p);
							++res;
							it = std::prev(it, 2);
							it = pile.erase(it);
							it = pile.erase(it);
							if (it != begin(pile)) {
								--it;
							}
							c = 0;
							continue;
						}
					}
					p = *it;
					c = 1;
				}
				++it, ++i;
			}
			if (pile.empty())break;

			it = begin(pile);
			c = 0;
			i = 0;
			while (it != end(pile)) {
				if (c == 0) {
					p = *it;
					c = 1;
					++it;
					continue;
				}
				if (*it == p) {
					++c;
					if (c == 3) {
						it = std::prev(it, 2);
						it = pile.erase(it);
						it = pile.erase(it);
						it = pile.erase(it);
						if (it != begin(pile)) {
							--it;
						}
						c = 0;
						continue;
					}
				}
				else if (*it != p) {
					if (c == 1) {
						auto it2 = h.find(p);
						if (it2 != end(h) && it2->second > 1) {
							it2->second -= 2;
							if (it2->second == 0)h.erase(p);
							res += 2;
							it = std::prev(it, 1);
							it = pile.erase(it);
							if (it != begin(pile)) {
								--it;
							}
							c = 0;
							continue;
						}
					}
					p = *it;
					c = 1;
				}
				++it, ++i;
			}
			if (pile.empty())break;
			if (res == reso)break;
			reso = res;
		}
		if (pile.size() == 1) {
			char p = *begin(pile);
			auto it2 = h.find(p);
			if (it2 != end(h) && it2->second >= 2) {
				res += 2;
				pile.clear();
			}
		}
		else if (pile.size() == 2) {
			char p = *begin(pile);
			if (p == *std::prev(end(pile), 1)) {
				auto it2 = h.find(p);
				if (it2 != end(h) && it2->second >= 1) {
					++res;
					pile.clear();
				}
			}
		}
		return (pile.empty()) ? (res) : (-1);
	}
};