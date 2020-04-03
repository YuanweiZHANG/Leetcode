#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-02
* Veronica
*/
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) 
			return;
		for (int i = len - 1; i > 0; --i) {
			if (nums[i] > nums[i - 1]) {
				for (int j = len - 1; j >= i; --j) {
					// Necessary because nums may have some same numbers
					if (nums[j] > nums[i - 1]) {
						swap(nums[j], nums[i - 1]);
						break;
					}
				}
				for (int j = 0; j < (len - i) / 2; ++j) {
					swap(nums[i + j], nums[len - 1 - j]);
				}
				return;
			}
		}
		for (int i = 0; i < len / 2; ++i) {
			swap(nums[i], nums[len - 1 - i]);
		}
		return;
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 6,5,4,3,2,1 };
	solution.nextPermutation(nums);
	for (auto num : nums) {
		cout << num << ' ';
	}

	return 0;
}