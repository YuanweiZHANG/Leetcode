#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/**
* 2020-04-12
* Veronica
*/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		
		int result = 0;
		for (int i = 1; i < len; ++i) {
			if (nums[i] == nums[result]) {
				while (i < len - 1 && nums[i] == nums[i + 1])
					i++;
				nums[++result] = nums[i];
			}
			else
				nums[++result] = nums[i];
		}
		return result + 1;
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 1 };
	int len = solution.removeDuplicates(nums);
	for (int i = 0; i < len; ++i) {
		cout << nums[i] << " ";
	}

	return 0;
}