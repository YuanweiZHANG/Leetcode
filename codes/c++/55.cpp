#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
* 2020-04-09
* Veronica
*/

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int farthest = 0, len = nums.size();
		for (int i = 0; i < len; ++i) {
			farthest = max(farthest, nums[i] + i);
			if (farthest <= i)
				return false;
			if (farthest >= len - 1)
				return true;
		}
		return true;
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 3,2,1,0,4 };
	cout << solution.canJump(nums) << endl;
	
	return 0;
}