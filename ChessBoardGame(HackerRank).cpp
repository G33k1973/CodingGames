#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> chess = {
			{0,0,1,1,0,0,1,1,0,0,1,1,0,0,1},
			{0,0,2,1,0,0,1,1,0,0,1,1,0,0,1},
			{1,2,2,2,3,2,2,2,3,2,2,2,3,2,1},
			{1,1,2,1,4,3,2,3,3,3,2,3,3,3,1},
			{0,0,3,4,0,0,1,1,0,0,1,1,0,0,1},
			{0,0,2,3,0,0,2,1,0,0,1,1,0,0,1},
			{1,1,2,2,1,2,2,2,3,2,2,2,3,2,1},
			{1,1,2,3,1,1,2,1,4,3,2,3,3,3,1},
			{0,0,3,3,0,0,3,4,0,0,1,1,0,0,1},
			{0,0,2,3,0,0,2,3,0,0,2,1,0,0,1},
			{1,1,2,2,1,1,2,2,1,2,2,2,3,2,1},
			{1,1,2,3,1,1,2,3,1,1,2,1,4,3,1},
			{0,0,3,3,0,0,3,3,0,0,3,4,0,0,1},
			{0,0,2,3,0,0,2,3,0,0,2,3,0,0,2},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,2,1}

};
/*
static String chessboardGame(int[][] coins) {
	int xor = 0;
	for (int[] Y : coins) {
		int x = Y[0]-1;
		int y = Y[1]-1;

			xor^=chess[x][y];
	}
	if (xor == 0)
		return "Second";
	return "First";
 }
 */
 /*
  * Complete the chessboardGame function below.
  */
string chessboardGame(vector<vector<int>> coins) {
	/*
	 * Write your code here.
	 */
	int xor_ = 0;
	for (auto& x : coins) {
		int X = x[0] - 1, Y = x[1] - 1;
		xor_ ^= chess[X][Y];
	}
	if (xor_ == 0)
		return "Second";
	return "First";
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		int k;
		cin >> k;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		vector<vector<int>> coins(k);
		for (int coins_row_itr = 0; coins_row_itr < k; coins_row_itr++) {
			coins[coins_row_itr].resize(2);

			for (int coins_column_itr = 0; coins_column_itr < 2; coins_column_itr++) {
				cin >> coins[coins_row_itr][coins_column_itr];
			}

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		string result = chessboardGame(coins);

		fout << result << "\n";
	}

	fout.close();

	return 0;
}
