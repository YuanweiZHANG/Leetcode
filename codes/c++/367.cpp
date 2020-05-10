#include <iostream>
using namespace std;

/**
* 2020-05-09
* Veronica
*/
class Solution {
public:
	bool isPerfectSquare(int num) {
		long long left = 1, right = num;
		while (left <= right) {
			long long mid = (left + right) >> 1;
			long long mul = mid * mid;
			if (mul == num)
				return true;
			else if (mul < num)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return false;
	}
};

int main() {
	Solution solution;

	int num = 40000;
	cout << solution.isPerfectSquare(num) << endl;

	return 0;
}