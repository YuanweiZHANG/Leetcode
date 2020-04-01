#include <iostream>
using namespace std;

/**
* 2020-04-01
* Veronica
*/
class Solution {
public:
	int divide(int dividend, int divisor) {
		bool negative = false;
		if (dividend < 0) negative = !negative;
		if (divisor < 0) negative = !negative;
		long long dividend_ = abs((long long)dividend);
		long long divisor_ = abs((long long)divisor);
		long long result = 0;
		int index = 0;
		while (dividend_ >= divisor_) {
			divisor_ <<= 1;
			index++;
		}
		divisor_ >>= 1;
		index--;
		while (dividend_ > 0 && index >= 0) {
			if (dividend_ >= divisor_) {
				dividend_ -= divisor_;
				divisor_ >>= 1;
				result += ((long long)1 << index);
				index--;
			}
			else {
				divisor_ >>= 1;
				index--;
			}
		}
		if (negative)
			result = -result;
		if (result > INT_MAX || result < INT_MIN)
			return INT_MAX;
		else return (int)result;
	}
};

int main() {
	Solution solution;

	int dividend = INT_MIN, divisor = -1;
	cout << solution.divide(dividend, divisor) << endl;

	return 0;
}