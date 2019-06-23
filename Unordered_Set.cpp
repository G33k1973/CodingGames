/*This is a function problem.You only need to complete the function given below*/
/* You are required to complete below methods */
/*inserts an element x to the unordered set s */
void insert(unordered_set<int> &s, int x)
{
	//Your code here
	if (s.count(x) == 0)s.insert(x);
	return;
}
/*erases an element x from the unordered set s */
void erase(unordered_set<int> &s, int x)
{
	//Your code here
	if (s.count(x))s.erase(x);
}
/*returns the size of the unordered set s */
int size(unordered_set<int> &s)
{
	//Your code here
	return static_cast<int>(s.size());
}
/*returns 1 if the element x is present
in unordered set s else returns -1 */
int find(unordered_set<int> &s, int x)
{
	//Your code here
	return (s.count(x) > 0) ? (1) : (-1);
}
