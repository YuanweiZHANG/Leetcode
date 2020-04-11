#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-11
* Veronica
*/
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int len = nums.size();
		int index0 = 0, index2 = len - 1;
		int i = 0;
		while (index2 >= 0 && nums[index2] == 2)
			index2--;
		while (i <= index2) {
			if (nums[i] == 0) {
				nums[i] = 1;
				nums[index0++] = 0;
			}
			else if (nums[i] == 2) {
				nums[i] = 1;
				if (nums[index2] == 0)
					nums[index0++] = 0;
				nums[index2--] = 2;
				while (index2 >= 0 && nums[index2] == 2)
					index2--;
			}
			i++;
		}
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 2,0,2,1,1,0 };
	solution.sortColors(nums);
	for (auto num : nums) {
		cout << num << " ";
	}

	return 0;
}
