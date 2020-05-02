#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
* 2020-05-01
* Veronica
*/
bool isBadVersion(int version) {
	if (version < 1702766719)
		return false;
	else
		return true;
}
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int left = 1, right = n;
		while (left < right) {
			int mid = (left + right) >> 1;
			if (isBadVersion(mid)) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		if (isBadVersion(left))
			return left;
		else
			return n + 1;
	}
};

int main() {
	Solution solution;

	int n = 2126753390;
	cout << solution.firstBadVersion(n) << endl;

	return 0;
}