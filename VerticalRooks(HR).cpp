#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the verticalRooks function below.
 */
string verticalRooks(vector<int> r1, vector<int> r2) {
	/*
	 * Write your code here.
	 */
	int res = 0;
	const int l = static_cast<int>(r1.size());
	for (int i = 0; i < l; ++i) {
		int nimber = abs(r1[i] - r2[i]) - 1;
		res ^= nimber;
	}
	return (res != 0) ? ("player-2") : ("player-1");
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		int n;
		cin >> n;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		vector<int> r1(n);

		for (int r1_itr = 0; r1_itr < n; r1_itr++) {
			int r1_item;
			cin >> r1_item;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			r1[r1_itr] = r1_item;
		}

		vector<int> r2(n);

		for (int r2_itr = 0; r2_itr < n; r2_itr++) {
			int r2_item;
			cin >> r2_item;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			r2[r2_itr] = r2_item;
		}

		string result = verticalRooks(r1, r2);

		fout << result << "\n";
	}

	fout.close();

	return 0;
}
