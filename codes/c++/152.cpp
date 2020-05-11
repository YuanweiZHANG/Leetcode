#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
* 2020-05-11
* Veronica
*/
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		else if (n == 1)
			return nums[0];
		int prevMax = nums[0], prevMin = nums[0], currMax = 0, currMin = 0;
		int result = nums[0];
		for (int i = 1; i < n; ++i) {
			currMax = max({ prevMax*nums[i], prevMin*nums[i], nums[i] });
			currMin = min({ prevMax*nums[i], prevMin*nums[i], nums[i] });
			result = max(result, currMax);

			prevMax = currMax;
			prevMin = currMin;
		}
		return result;
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 0 };
	cout << solution.maxProduct(nums) << endl;

	return 0;
}