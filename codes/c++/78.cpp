#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-11
* Veronica
*/
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> results;
		vector<int> curr;
		subsetsCore(results, curr, nums, 0);
		return results;
	}
	void subsetsCore(vector<vector<int>>& results, vector<int>& curr, vector<int>& nums, int start) {
		results.push_back(curr);
		for (int i = start; i < nums.size(); ++i) {
			curr.push_back(nums[i]);
			subsetsCore(results, curr, nums, i + 1);
			curr.pop_back();
		}
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 1,2,3 };
	vector<vector<int>> results = solution.subsets(nums);
	for (auto a : results) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}

	return 0;
}
