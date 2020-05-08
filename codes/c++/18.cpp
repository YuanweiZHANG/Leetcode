#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
* 2020-05-08
* Veronica
*/
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		int n = nums.size();
		if (n < 4)
			return result;
		sort(nums.begin(), nums.end());
		int num1 = 0, num2 = 1, num3 = 2, num4 = n - 1;
		for (num1 = 0; num1 < n - 3; ++num1) {
			for (num2 = num1 + 1; num2 < n - 2; ++num2) {
				int sum = target - nums[num1] - nums[num2];
				num3 = num2 + 1;
				num4 = n - 1;
				while (num3 < num4) {
					if (nums[num3] + nums[num4] == sum) {
						result.push_back({ nums[num1], nums[num2], nums[num3], nums[num4] });
						num3 = next(nums, num3, 1);
						num4 = next(nums, num4, -1);
					}
					else if (nums[num3] + nums[num4] < sum) {
						num3 = next(nums, num3, 1);
					}
					else {
						num4 = next(nums, num4, -1);
					}
				}
				num2 = next(nums, num2, 1);
				num2--;
			}
			num1 = next(nums, num1, 1);
			num1--;
		}
		return result;
	}

	int next(vector<int>& nums, int start, int dir) {
		int n = nums.size();
		while (start >= 0 && start < n && start + dir >= 0 && start + dir<n && nums[start] == nums[start + dir])
			start += dir;
		return start + dir;
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 1,1,1,1,1,1,1,1,1,1 };
	int target = 4;
	vector<vector<int>> results = solution.fourSum(nums, target);
	for (auto a : results) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}

	return 0;
}