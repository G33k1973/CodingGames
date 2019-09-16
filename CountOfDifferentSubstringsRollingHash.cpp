typedef unsigned long long int ll;
unordered_set<int> result;
#define x 26
#define mod 3001
void CntSubstr(string& s, int l)
{
	// Variable to the hash 
	int hash = 0;

	// Finding hash of substring 
	// (0, l-1) using random number x 
	for (int i = 0; i < l; i++) {
		hash = (hash * x + (s[i] - 97)) % mod;
	}

	// Computing x^(l-1) 
	int pow_l = 1;
	for (int i = 0; i < l - 1; i++)
		pow_l = (pow_l * x) % mod;

	// Unordered set to add hash values 
	result.insert(hash);

	// Generating all possible hash values 
	for (int i = l; i < s.size(); i++) {
		hash = ((hash - pow_l * (s[i - l] - 97)
			+ 2 * mod) * x + (s[i] - 97)) % mod;
		result.insert(hash);
	}
	return;
}
int countDistinctSubstring(string s)
{
	//Your code here
	if (result.size() > 0)result.clear();
	int l = (int)s.size();
	if (l == 0)return 1;
	if (l == 1)return 2;
	for (int i = l; i >= 1; --i) {
		CntSubstr(s, i);
	}
	return (result.size() + 1);
}