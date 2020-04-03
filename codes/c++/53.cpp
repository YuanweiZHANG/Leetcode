#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
* 2020-04-03
* Veronica
*/
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) return 0;

		int max_sum = nums[0];
		for (int i = 1; i < len; ++i) {
			nums[i] = max(nums[i], nums[i] + nums[i - 1]);
			max_sum = max(max_sum, nums[i]);
		}
		return max_sum;
	}
};

int main() {
	Solution solution;

	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	cout << solution.maxSubArray(nums) << endl;

	return 0;
}