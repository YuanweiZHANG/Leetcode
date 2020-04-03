#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-03
* Veronica
*/
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int len = nums.size();
		if (len == 0) return -1;
		return binarySearch(nums, target, 0, len - 1);
	}
	int binarySearch(vector<int> & nums, int target, int left, int right) {
		if (left > right) return -1;
		
		int mid = (left + right) >> 1;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < nums[right]) {
			if (nums[mid] < target && target <= nums[right])
				return binarySearch(nums, target, mid + 1, right);
			else
				return binarySearch(nums, target, left, mid - 1);
		}
		else {
			if (nums[left] <= target && target < nums[mid]) {
				return binarySearch(nums, target, left, mid - 1);
			}
			else 
				return binarySearch(nums, target, mid + 1, right);
		}
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 4,5,6,7,0,1,2 };
	int target = 7;
	cout << solution.search(nums, target);

	return 0;
}