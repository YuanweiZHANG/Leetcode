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
		int once = 0, twice = 0;
		for (auto num : nums) {
			once = ~twice & (once ^ num);
			twice = ~once & (twice ^ num);
		}
		return once;
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 2,2,3,2 };
	cout << solution.singleNumber(nums) << endl;

	return 0;
}