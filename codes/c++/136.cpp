#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-01
* Veronica
*/
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (auto num : nums) {
			result ^= num;
		}
		return result;
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 2,2,1 };
	cout << solution.singleNumber(nums);

	return 0;
}