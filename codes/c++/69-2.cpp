#include <iostream>
using namespace std;

/**
* 2020-04-10
* Veronica
*/
class Solution {
public:
	int mySqrt(int x) {
		long long start = 1, end = x;
		while (start <= end) {
			int mid = (start + end) >> 1;
			if (mid < x / mid) {
				start = mid + 1;
			}
			else if (mid > x / mid) {
				if ((mid - 1) < x / (mid - 1)) {
					return mid - 1;
				}
				else {
					end = mid - 1;
				}
			}
			else {
				return mid;
			}
		}
		return 0;
	}
};

int main() {
	Solution solution;

	int x = 8;
	cout << solution.mySqrt(x) << endl;

	return 0;
}
