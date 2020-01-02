int c;
int n;
int m;
unordered_map<int, pair<int, int>> fun;
map<int, int, less<int>> bst;
LRUCache::LRUCache(int capacity) {
	c = capacity;
	n = 0;
	m = 0;
	if (fun.size())fun.clear();
	if (bst.size())bst.clear();
}

int LRUCache::get(int key) {
	auto it = fun.find(key);
	if (it == end(fun))return -1;
	int oldfreq = it->second.second;
	bst.erase(bst.find(oldfreq));
	it->second.second = ++n;
	bst[n] = key;
	return it->second.first;
}

void LRUCache::set(int key, int value) {
	auto it = fun.find(key);
	if (it != end(fun)) {
		int oldfreq = it->second.second;
		bst.erase(bst.find(oldfreq));
		++n;
		bst.insert(make_pair(n, key));
		it->second.second = n;
		it->second.first = value;
	}
	else {
		if (m < c) {
			++m;
			++n;
			bst[n] = key;
			fun[key] = make_pair(value, n);
		}
		else {
			auto ptr = begin(bst);
			int keyer = ptr->second;
			ptr = bst.erase(ptr);
			fun.erase(keyer);
			++n;
			fun[key] = make_pair(value, n);
			bst[n] = key;
		}
	}
}
