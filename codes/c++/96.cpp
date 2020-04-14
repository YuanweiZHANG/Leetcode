#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
* 2020-04-14
* Veronica
*/
class Solution {
public:
	int numTrees(int n) {
		if (n == 0)
			return 0;
		else if (n == 1)
			return 1;
		vector<int> nums(n + 1, 0);
		nums[0] = 1, nums[1] = 1;
		for (int i = 2; i <= n; ++i) {
			for (int j = 0; j < i; ++j) {
				nums[i] += nums[j] * nums[i - 1 - j];
			}
		}
		return nums[n];
	}
};

int main() {
	Solution solution;

	int n = 3;
	cout << solution.numTrees(n) << endl;

	return 0;
}