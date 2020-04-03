#include <iostream>
#include <set>
using namespace std;

/**
* 2020-04-02
* Veronica
*/
class Solution {
public:
	bool isHappy(int n) {
		set<int> nums;
		nums.insert(n);
		while (n != 1) {
			n = sumSquare(n);
			if (nums.find(n) != nums.end()) {
				return false;
			}
			nums.insert(n);
		}
		return true;
	}
	int sumSquare(int n) {
		int sum = 0;
		while (n > 0) {
			int digit = n % 10;
			sum += (digit*digit);
			n /= 10;
		}
		return sum;
	}
};

int main() {
	Solution solution;

	int n = 20;
	cout << solution.isHappy(n) << endl;

	return 0;
}