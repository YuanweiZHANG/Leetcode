#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
* 2020-04-13
* Veronica
*/
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> results;
		vector<int> curr;
		subsetsWithDupCore(nums, results, curr, 0);
		return results;
	}
	void subsetsWithDupCore(vector<int>& nums, vector<vector<int>>& results, vector<int>& curr, int index) {
		results.push_back(curr);
		for (int i = index; i < nums.size(); ++i) {
			curr.push_back(nums[i]);
			subsetsWithDupCore(nums, results, curr, i + 1);
			curr.pop_back();
			while (i < nums.size() - 1 && nums[i] == nums[i + 1])
				i++;
		}
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 1,2,2 };
	vector<vector<int>> results = solution.subsetsWithDup(nums);
	for (auto a : results) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}

	return 0;
}