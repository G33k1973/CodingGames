#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

#define ALPHABET_SIZE 2
using ll = unsigned long long int;

struct TrieNode {
	struct TrieNode * children[ALPHABET_SIZE];
	bool EndOfWord;
};

struct TrieNode * GetNode() {
	struct TrieNode * root = new TrieNode();
	for (int i = 0; i < ALPHABET_SIZE; ++i) {
		root->children[i] = nullptr;
	}
	root->EndOfWord = false;
	return root;
}

void insert(struct TrieNode *root, string key) {
	struct TrieNode * crawl = root;
	for (int i = 0; i<int(key.length()); ++i) {
		int k = key.at(i) - '0';
		if (!crawl->children[k]) {
			crawl->children[k] = GetNode();
		}
		crawl = crawl->children[k];
	}
	crawl->EndOfWord = true;
	return;
}

ll Search(TrieNode * root, string key) {
	ll res{ 0ULL };
	TrieNode * crawl = root;
	int i = 0, l = int(key.length());
	while (i < l) {
		int k = key[i] - '0';
		if (crawl->EndOfWord)break;
		int nk = (!k);
		if (crawl->children[nk] != nullptr) {
			res += (1ULL << (31 - i));
			crawl = crawl->children[nk];
		}
		else {
			crawl = crawl->children[k];
		}
		++i;
	}
	while (i < l) {
		int k = key[i] - '0';
		if (k)res += (1ULL << (31 - i));
		++i;
	}
	return res;
}

string Extract(int x) {
	assert(x >= 0);
	constexpr int bits = 8;
	int SIZE = sizeof(int)*bits;
	string s(SIZE, '0');
	int i = 0, j = SIZE - 1;
	int m = 1;
	while (i < SIZE) {
		if (x&m)s[j] = '1';
		++i;
		--j;
		m <<= 1;
	}
	return s;
}

// Complete the maxXor function below.
vector<ll> maxXor(vector<int> arr, vector<int> queries) {
	// solve here
	TrieNode * root = GetNode();
	for (int& x : arr) {
		string s = Extract(x);
		insert(root, s);
	}
	int q = static_cast<int>(queries.size());
	vector<ll> r;
	for (int i = 0; i < q; ++i) {
		r.push_back(Search(root, Extract(queries[i])));
	}
	return r;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string arr_temp_temp;
	getline(cin, arr_temp_temp);

	vector<string> arr_temp = split_string(arr_temp_temp);

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		int arr_item = stoi(arr_temp[i]);

		arr[i] = arr_item;
	}

	int m;
	cin >> m;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> queries(m);

	for (int i = 0; i < m; i++) {
		int queries_item;
		cin >> queries_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		queries[i] = queries_item;
	}

	vector<ll> result = maxXor(arr, queries);

	for (int i = 0; i < result.size(); i++) {
		fout << result[i];

		if (i != result.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";

	fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
