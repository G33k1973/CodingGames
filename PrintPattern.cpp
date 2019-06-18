#define pb push_back
void printPattern(string s)
{
	//Your code here
	int l = static_cast<int>(s.length());
	int i = l / 2;
	int space = (l - 1) << 1;
	int j = 0;
	string sub("");
	while (j < l) {
		sub.pb(s[i]);
		string s1(space, ' ');
		cout << s1 << sub << '$';
		i = (i + 1) % l;
		space -= 2;
		++j;
	}
	return;
}
