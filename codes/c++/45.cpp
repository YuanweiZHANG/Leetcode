#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
* 2020-04-07
* Veronica
*/
class Solution {
public:
	int jump(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		vector<int> steps(len, 10000);
		steps[0] = 0;
		int farthest = 0;
		for (int i = 0; i < len; ++i) {
			if (nums[i] + i > farthest) {
				int j = 0;
				for (j = farthest + 1; j < len && j <= nums[i] + i; ++j) {
					steps[j] = steps[i] + 1;
					farthest = j;
				}
			}
		}
		return steps[len - 1];
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5 };
	cout << solution.jump(nums) << endl;

	return 0;
}