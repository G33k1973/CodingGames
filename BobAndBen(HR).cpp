#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the bobAndBen function below.
 */
 /*
 for n =0 and n =2: G(n) = 0

for all other n: Gn(n) = (n-1)%2+1
*/
string bobAndBen(vector<vector<int>> trees) {
	/*
	 * Write your code here.
	 */
	int res = 0;
	for (auto& x : trees) {
		int nodes = x.front();
		if (nodes == 0 || nodes == 2)res ^= 0;
		else {
			int nimber = (nodes - 1) % 2;
			++nimber;
			res ^= nimber;
		}
	}
	return (res == 0) ? ("BEN") : ("BOB");
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int g;
	cin >> g;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int g_itr = 0; g_itr < g; g_itr++) {
		int n;
		cin >> n;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		vector<vector<int>> trees(n);
		for (int trees_row_itr = 0; trees_row_itr < n; trees_row_itr++) {
			trees[trees_row_itr].resize(2);

			for (int trees_column_itr = 0; trees_column_itr < 2; trees_column_itr++) {
				cin >> trees[trees_row_itr][trees_column_itr];
			}

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		string result = bobAndBen(trees);

		fout << result << "\n";
	}

	fout.close();

	return 0;
}
