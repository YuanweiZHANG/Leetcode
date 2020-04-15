#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-15
* Veronica
*/
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> results(nums.size(), 1);
		int len = nums.size();
		int mul = 1;
		for (int i = 1; i < len; ++i) {
			mul *= nums[i - 1];
			results[i] *= mul;
		}
		mul = 1;
		for (int i = len - 2; i >= 0; --i) {
			mul *= nums[i + 1];
			results[i] *= mul;
		}
		return results;
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 4 };
	vector<int> results = solution.productExceptSelf(nums);
	for (auto result : results)
		cout << result << " ";

	return 0;
}