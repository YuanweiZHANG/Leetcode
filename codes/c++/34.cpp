#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-03
* Veronica
*/
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int len = nums.size();
		if (len == 0)
			return { -1,-1 };
		return { binarySearchL(nums, target, 0,len - 1), binarySearchR(nums,target,0,len - 1) };
	}

	int binarySearchL(vector<int>& nums, int target, int left, int right) {
		if (left > right)
			return -1;
		int mid = (left + right) >> 1;
		if (nums[mid] == target) {
			if (mid == left)
				return mid;
			else {
				if (nums[mid - 1] == target)
					return binarySearchL(nums, target, left, mid - 1);
				else
					return mid;
			}
		}
		else if (nums[mid] < target)
			return binarySearchL(nums, target, mid + 1, right);
		else
			return binarySearchL(nums, target, left, mid - 1);
	}

	int binarySearchR(vector<int>& nums, int target, int left, int right) {
		if (left > right)
			return -1;
		int mid = (left + right) >> 1;
		if (nums[mid] == target) {
			if (mid == right)
				return mid;
			else {
				if (nums[mid + 1] == target)
					return binarySearchR(nums, target, mid + 1, right);
				else
					return mid;
			}
		}
		else if (nums[mid] < target)
			return binarySearchR(nums, target, mid + 1, right);
		else
			return binarySearchR(nums, target, left, mid - 1);
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 5,7,7,8,8,10 };
	int target = 5;
	vector<int> results = solution.searchRange(nums, target);
	for (auto result : results) {
		cout << result << ' ';
	}

	return 0;
}