class Solution {
	vector<string> base1_list = { "Zero", "One", "Two", "Three", "Four", "Five",
							   "Six", "Seven", "Eight", "Nine" };
	vector<string> base2_list = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
								 "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

	vector<string> base3_list = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
	vector<string> base4_list = { "", "Thousand", "Million", "Billion" };
public:
	string to_number(string val) {
		string ret;
		if (val.size() == 3) {
			if (val[0] != '0') {
				ret += (base1_list[val[0] - '0'] + " Hundred");
			}

			if (val[1] == '0') {
				if (val[2] != '0') {
					if (ret.size() != 0) {
						ret += " ";
					}
					ret += base1_list[val[2] - '0'];
				}
			}
			else if (val[1] == '1') {
				if (ret.size() != 0) {
					ret += " ";
				}
				ret += base2_list[val[2] - '0'];
			}
			else {
				if (ret.size() != 0) {
					ret += " ";
				}
				ret += base3_list[val[1] - '0'];
				if (val[2] != '0') {
					ret += " ";
					ret += base1_list[val[2] - '0'];
				}
			}
		}
		else if (val.size() == 2) {
			if (val[0] == '1') {
				ret += base2_list[val[1] - '0'];
			}
			else {
				ret += base3_list[val[0] - '0'];
				if (val[1] != '0') {
					ret += " ";
					ret += base1_list[val[1] - '0'];
				}
			}
		}
		else {
			ret += base1_list[val[0] - '0'];
		}

		return ret;
	}

	string numberToWords(int num) {

		string s_sum = to_string(num);
		stack<string> stk;
		int level = -1;

		while (s_sum.size() >= 3) {
			stk.push(s_sum.substr(s_sum.size() - 3));
			s_sum = s_sum.substr(0, s_sum.size() - 3);
			level += 1;
		}

		if (s_sum != "") {
			stk.push(s_sum);
			level += 1;
		}


		string ret;
		while (stk.empty() == false) {
			string val = stk.top();
			string to_add = to_number(val);
			if (ret == "") {
				ret = to_add;
			}
			else {
				if (to_add != "") {
					ret += " ";
					ret += to_add;
				}
			}
			if (level > 0 && to_add != "") {
				ret += " ";
				ret += base4_list[level];
			}
			stk.pop();
			level--;
		}
		return ret;
	}
};