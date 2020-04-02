#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

struct PT {
	int id;
	double x, y, z;
	PT() {}
	PT(int a, double b, double c, double d) :id(a), x(b), y(c), z(d) {}
	bool operator>(const struct PT& obj) const {
		return this->z > obj.z;
	}
};

struct Functor {
	bool operator()(const struct PT& a, const struct PT& b) {
		return a.operator>(b);
	}
};

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	std::ios::sync_with_stdio(false);
	int n, b;
	cin >> n >> b;
	std::map<double, struct PT, greater<double>> bst;
	unordered_map<int, int> dict;
	for (int i = 0; i < n; ++i) {
		int k;
		double x, y, z;
		cin >> k >> x >> y >> z;
		struct PT temp(k, x, y, z);
		bst[temp.z] = temp;
	}
	if (n > 0 && b > 0) {
		auto ptr = bst.begin();
		int i = 1;
		while (i <= b) {
			dict[ptr->second.id] = i;
			++i, ++ptr;
		}
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	string s("");
	const char * NotFound = "Point doesn't exist in the bucket.\n";
	const char * NoDel = "No more points can be deleted.\n";
	while (std::getline(std::cin, s)) {
		if (s.empty())break;
		auto pos = s.find(' ', 0);
		string op = s.substr(0, pos);
		if (op.front() >= 97)op.front() -= 32;
		int ID = std::stoi(s.substr(pos + 1));
		if (op.front() == 'F') {
			auto it = dict.find(ID);
			if (it == end(dict)) {
				printf("%s", NotFound);
				continue;
			}
			auto ptr = std::next(bst.begin(), it->second - 1);
			printf("%d = (%.3lf,%.3lf,%.3lf)\n", ID, ptr->second.x, ptr->second.y, ptr->second.z);
		}
		if (op.front() == 'R') {
			auto it = dict.find(ID);
			if (it == end(dict)) {
				printf("%s", NotFound);
				continue;
			}
			if (int(bst.size()) == b) {
				printf("%s", NoDel);
				continue;
			}
			int sz = b - it->second + 1;
			auto ptr = std::next(bst.begin(), it->second);
			int i = 0;
			int position = it->second;
			while (i < sz) {
				dict[ptr->second.id] = position;
				++position;
				++ptr;
				++i;
			}
			ptr = next(bst.begin(), it->second - 1);
			ptr = bst.erase(ptr);
			dict.erase(ID);
			printf("Point id %d removed.\n", ID);
		}
	}
	return 0;
}
