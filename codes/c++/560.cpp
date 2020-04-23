#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
* 2020-04-22
* Veronica
*/
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int n = nums.size();
		int result = 0, sum = 0;
		map<int/*sum*/, int/*subarray numbers*/> mp;
		mp[0]++;
		for (int i = 0; i < n; ++i) {
			sum += nums[i];
			result += mp[sum - k];
			mp[sum]++;
		}
		return result;
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 1,1,1 };
	int k = 2;
	cout << solution.subarraySum(nums, k) << endl;

	return 0;
}