#include <iostream>
using namespace std;

/**
* 2020-04-10
* Veronica
*/
class Solution {
public:
	int climbStairs(int n) {
		if (n == 1)
			return 1;
		int num1 = 1, num2 = 1, num3 = 2;
		for (int i = 2; i < n; ++i) {
			num1 = num2;
			num2 = num3;
			num3 = num1 + num2;
		}
		return num3;
	}
};

int main() {
	Solution solution;

	int n = 4;
	cout << solution.climbStairs(n) << endl;

	return 0;
}
