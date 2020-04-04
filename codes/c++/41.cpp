#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-04
* Veronica
*/
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) 
			return 1;
		for (int i = 0; i < len; ++i) {
			while (nums[i] > 0 && nums[i] <= len && nums[nums[i]-1] != nums[i]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for (int i = 0; i < len; ++i) {
			if (nums[i] != i + 1)
				return i + 1;
		}
		return len + 1;
	}
};

int main() {
	Solution solution;

	vector<int> nums = { -1,4,2,1,9,10 };
	cout << solution.firstMissingPositive(nums) << endl;

	return 0;
}