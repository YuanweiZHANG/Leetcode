#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/**
* 2020-04-13
* Veronica
*/
class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int sum = 0;
		int maxLength = 0;
		map<int/*sum*/, int/*index*/> mp;
		mp[0] = -1;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == 0)
				sum--;
			else
				sum++;
			if (mp.find(sum) != mp.end()) {
				maxLength = max(maxLength, i - mp[sum]);
			}
			else
				mp[sum] = i;
		}
		return maxLength;
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 0,1,1,0,1,1,1,0 };
	cout << solution.findMaxLength(nums) << endl;

	return 0;
}