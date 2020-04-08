#include <iostream>
using namespace std;

/**
* 2020-04-08
* Veronica
*/

class Solution {
public:
	double myPow(double x, int n) {
		bool fraction = false;
		long long absn = n;
		if (n < 0) {
			fraction = true;
			absn = abs(absn);
		}
		else if (absn == 0)
			return 1.0;

		long long temp = absn;
		int highest = 0;
		while (temp) {
			highest++;
			temp >>= 1;
		}

		double result = 1;
		while (highest >= 0) {
			result *= result;
			if (absn & ((long long)1 << highest)) {
				result *= x;
			}
			highest--;
		}
		if (fraction) {
			result = 1.0 / result;
		}
		return result;
	}
};

int main() {
	Solution solution;

	double x = 1.00000;
	int n = INT_MIN;
	cout << solution.myPow(x, n) << endl;

	return 0;
}