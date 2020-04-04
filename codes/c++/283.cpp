#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-04
* Veronica
*/
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return;
		int zero_index = 0;
		for (int i = 0; i < len; ++i) {
			if (nums[i] != 0) {
				nums[zero_index++] = nums[i];
			}
		}
		for (int i = zero_index; i < len; ++i) {
			nums[i] = 0;
		}
		return;
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 0,1,0,3,12 };
	solution.moveZeroes(nums);
	for (auto num : nums) {
		cout << num << ' ';
	}

	return 0;
}