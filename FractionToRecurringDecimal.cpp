class Solution {
public:
	string calculateFraction(int num, int den)
	{
		// If the numerator is zero, answer is 0 
		if (num == 0)
			return "0";

		// If any one (out of numerator and denominator) 
		// is -ve, sign of resultant answer -ve. 
		int sign = (num < 0) ^ (den < 0) ? -1 : 1;

		num = abs(num);
		den = abs(den);

		// Calculate the absolute part (before decimal point). 
		int initial = num / den;

		// Output string to store the answer 
		string res;

		// Append sign 
		if (sign == -1)
			res += "-";

		// Append the initial part 
		res += to_string(initial);

		// If completely divisible, return answer. 
		if (num % den == 0)
			return res;

		res += ".";

		// Initialize Remainder 
		int rem = num % den;
		map<int, int> mp;

		// Position at which fraction starts repeating 
		// if it exists 
		int index;
		bool repeating = false;
		while (rem > 0 && !repeating) {

			// If this remainder is already seen, 
			// then there exists a repeating fraction. 
			if (mp.find(rem) != mp.end()) {

				// Index to insert parentheses 
				index = mp[rem];
				repeating = true;
				break;
			}
			else
				mp[rem] = res.size();

			rem = rem * 10;

			// Calculate quotient, append it to result and 
			// calculate next remainder 
			int temp = rem / den;
			res += to_string(temp);
			rem = rem % den;
		}

		// If repeating fraction exists, insert parentheses. 
		if (repeating) {
			res += ")";
			res.insert(index, "(");
		}

		// Return result. 
		return res;
	}
	string fractionToDecimal(int numerator, int denominator) {
		return calculateFraction(numerator, denominator);
	}
};