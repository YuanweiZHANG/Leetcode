#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 2020-03-29
 * Veronica
 */
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int n = nums.size();
		if (n == 0) return 0;
		sort(nums.begin(), nums.end());
		int sum = 0, i2 = 0, i3 = 0;
		int diff = INT_MAX, result = 0, curr_diff = 0;
		
		for (int i1 = 0; i1 < n - 2; ++i1) {
			sum = nums[i1] + nums[i1 + 1] + nums[i1 + 2];
			if (sum > target) {
				curr_diff = sum - target;
				if (curr_diff < diff) {
					diff = curr_diff;
					result = sum;
				}
				continue;
			}
			sum = nums[i1] + nums[n - 1] + nums[n - 2];
			if (sum < target) {
				curr_diff = target - sum;
				if (curr_diff < diff) {
					diff = curr_diff;
					result = sum;
				}
				continue;
			}
			i2 = i1 + 1;
			i3 = n - 1;
			while (i2 < i3) {
				sum = nums[i1] + nums[i2] + nums[i3];
				if (sum == target) return sum;
				else if (sum < target) {
					i2++;
					curr_diff = target - sum;
					if (curr_diff < diff) {
						diff = curr_diff;
						result = sum;
					}
				}
				else {
					i3--;
					curr_diff = sum - target;
					if (curr_diff < diff) {
						diff = curr_diff;
						result = sum;
					}
				}
			}
		}
		return result;
	}
};


int main() {
	Solution solution;

	vector<int> nums = { 1,2,4,8,16,32,64,128 };
	int target = 82;

	cout << solution.threeSumClosest(nums, target) << endl;

	return 0;
}
