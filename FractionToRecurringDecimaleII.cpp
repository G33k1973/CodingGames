class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (numerator == 0) return "0";
		string result = "";
		if (numerator < 0 && denominator>0 || numerator > 0 && denominator < 0) //Check for negative results 
			result = result + '-';
		long long dividend = abs(numerator); long long divisor = abs(denominator);
		result = result + to_string(dividend / divisor);
		long long remainder = dividend % divisor;
		if (remainder > 0) result = result + '.';
		unordered_map<long long, int>repeat;//The value of map ensures index where repeatition began so ( can be inserted at right place
		while (remainder > 0)
		{
			if (repeat.find(remainder) != repeat.end())
			{
				result.insert(repeat[remainder], "(");
				result = result + ')';
				break;
			}
			repeat[remainder] = result.length();
			remainder *= 10;
			result = result + to_string(remainder / divisor);
			remainder %= divisor;
		}
		return result;
	}
};