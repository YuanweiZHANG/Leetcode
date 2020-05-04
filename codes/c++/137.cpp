#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
* 2020-05-04
* Veronica
*/
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		map<int/*num*/, int/*times*/> mp;
		for (auto num : nums)
			mp[num]++;
		for (auto it : mp)
			if (it.second == 1)
				return it.first;
		return -1;
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 2,2,3,2 };
	cout << solution.singleNumber(nums) << endl;

	return 0;
}