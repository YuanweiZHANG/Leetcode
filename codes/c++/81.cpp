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
	bool search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = (left + right) >> 1;
			if (nums[mid] == target)
				return true;
			else if (nums[mid] > nums[left]) { // left part
				if (nums[mid] > target && target >= nums[left]) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
			else if (nums[mid] < nums[left]) { // right part
				if (nums[mid] < target && target < nums[left]) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
			else { // nums[mid] == nums[left]: target can appear in both sides
				left++;
				while (left < nums.size() - 1 && nums[left - 1] == nums[left])
					left++;
			}
		}
		return false;
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 4,5,6,7,0,1,2 };
	int target = 0;
	cout << solution.search(nums, target) << endl;

	return 0;
}