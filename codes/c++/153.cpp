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
	int findMin(vector<int>& nums) {
		int n = nums.size();
		int left = 0, right = n - 1;
		while (left <= right) {
			if (nums[left] < nums[right])
				return nums[left];
			else if (nums[left] == nums[right]) // exists 1 element
				return nums[left];
			int mid = (left + right) >> 1;
			if (nums[mid] >= nums[left])
				left = mid + 1;
			else if (nums[mid] < nums[right]) {
				if (nums[mid] < nums[mid - 1])
					return nums[mid];
				else
					right = mid - 1;
			}
			else
				return nums[right];
		}
		return 0;
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 5,6,4,3,2,1 };
	cout << solution.findMin(nums) << endl;

	return 0;
}