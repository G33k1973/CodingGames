class LRUCache {
private:
	unordered_map<int, pair<int, int>> h;//key,first->value,second->freq
	map<int, int> rbt;//freq,key
	int sz;
	int n = 0;
	int c;
public:
	LRUCache(int capacity) {
		this->sz = capacity;
		this->c = 0;
		this->n = 0;
	}

	int get(int key) {
		//cout<<"****GET****\n";
		auto it = h.find(key);
		if (it == end(h))return -1;
		++c;
		int val = it->second.first;
		int oldfreq = it->second.second;
		rbt.erase(rbt.find(oldfreq));
		it->second.second = c;
		rbt.insert(make_pair(c, key));
		//for(auto& x: rbt)cout<<x.first<<" "<<x.second<<endl;
		return val;

	}

	void put(int key, int value) {
		//cout<<"****PUT****\n";
		++c;
		auto it = h.find(key);
		if (it != end(h)) {
			int oldfreq = it->second.second;
			it->second.second = c;
			it->second.first = value;
			rbt.erase(rbt.find(oldfreq));
			rbt.insert(make_pair(c, key));
		}
		else {
			++n;
			rbt.insert(make_pair(c, key));
			h[key] = make_pair(value, c);
			if (n > sz) {
				auto ptr = rbt.begin();
				int val2erase = ptr->second;
				rbt.erase(rbt.begin());
				h.erase(val2erase);
				cout << val2erase << " erased.\n";
			}
			//for(auto& x: rbt)cout<<x.first<<" "<<x.second<<endl;
			//cout<<"HASHTABLE\n";
			//for(auto& x: h)cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */