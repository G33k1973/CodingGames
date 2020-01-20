class Solution {
public:
	string removeDuplicateLetters(string s) {
		string res;
		vector<int>cnt(26, 0);   // arr to store cnt of each character
		vector<bool>visited(26, 0);   //To check if char is already added to res string
		for (char &i : s) cnt[i - 'a']++;
		int unique = 0;   // no of unique chars
		for (int i = 0; i < 26; i++) unique += (cnt[i] > 0);
		for (char &c : s)
		{

			cnt[c - 'a']--;
			if (visited[c - 'a']) continue;
			while (!res.empty() && c < res.back() && cnt[res.back() - 'a']>0)       // It means we have added 
			 //bigger char to the res string before the smaller current char where as we can even get the bigger char later also but still added so pop chars until they are bigger than current and we can find them later
			{
				visited[res.back() - 'a'] = 0;
				res.pop_back();
			}
			visited[c - 'a'] = 1;
			res += c;
			if (res.size() == unique) break;      // If we have find all the unique chars already simply break no need to traverse more
		}
		return res;
	}
};