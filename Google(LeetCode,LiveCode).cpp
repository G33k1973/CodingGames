class MovingAverage {
protected:
	int capacity, m, sum;
	std::queue<int> pile;
public:
	/** Initialize your data structure here. */
	MovingAverage(int size) {
		(*this).capacity = size;
		(*this).m = 0;
	}

	double next(int val) {
		++m;
		sum += val;
		pile.push(val);
		if (m <= capacity) {
			return (1.*sum / (1.*m));
		}
		sum -= pile.front();
		pile.pop();
		--m;
		return (1.*sum) / (1.*m);
	}
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
#define pb push_back
using ll = long long int;
class Solution {
private:
	vector<string> arr;
public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		int n = int(nums.size());
		//assert(lower < upper);
		ll lw = static_cast<ll>(lower);
		ll up = static_cast<ll>(upper);
		if (n == 0) {
			if (lower != upper) {
				string temp = to_string(lw) + "->" + to_string(up);
				arr.pb(temp);
			}
			else {
				string temp = to_string(lw);
				arr.pb(temp);
			}
			return arr;
		}
		ll prev = static_cast<ll>(nums.front());
		if (prev > lw) {
			ll diff = prev - lw;
			string t("");
			if (diff == 1) {
				t = to_string(lower);
			}
			else {
				t = to_string(lower) + "->" + to_string(prev - 1);
			}
			arr.pb(t);
		}
		for (int i = 1; i < n; ++i) {
			ll y = static_cast<ll>(nums.operator[](i));
			assert(y >= prev && y <= up);
			if (y == prev) {
				continue;
			}
			if (y != (prev + 1)) {
				ll diff = y - 1 - prev;
				string t("");
				if (diff == 1) {
					t = to_string(y - 1);
				}
				else {
					t = to_string(prev + 1) + "->" + to_string(y - 1);
				}
				arr.pb(t);
			}
			prev = y;
		}
		if (prev != up) {
			int diff = up - prev;
			string t("");
			if (diff == 1) {
				t = to_string(up);
			}
			else {
				t = to_string(prev + 1) + "->" + to_string(up);
			}
			arr.pb(t);
		}
		return arr;
	}
};

class Solution {
public:
	string addBoldTag(string s, vector<string>& dict) {
		string op = "<b>";
		string cl = "</b>";
		int l = int(s.size());
		if (l == 0)return s;
		vector<bool> visited(l, false);
		for (const string& i : dict) {
			if (i.empty())continue;
			int n = int(i.length());
			if (n > l)continue;
			std::string::size_type pos = 0, poso = 0;
			while (1) {
				pos = s.find(i, poso);
				if (pos == string::npos)break;
				for (int j = pos; j < pos + n; ++j) {
					if (!visited[j])visited[j] = true;
				}
				++pos;
				if (pos == l)break;
				poso = pos;
			}
		}
		string result = "";
		for (int i = 0; i < l; ++i) {
			if (!visited[i])result.push_back(s[i]);
			else {
				result += op;
				int j = i;
				while (j < l&&visited[j]) {
					result.push_back(s[j]);
					++j;
				}
				result += cl;
				i = j - 1;
			}
		}
		return result;
	}
};