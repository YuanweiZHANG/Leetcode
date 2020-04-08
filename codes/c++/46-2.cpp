#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/**
* 2020-04-08
* Veronica
*/
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> results;
		int len = nums.size();
		if (len == 0)
			return results;
		sort(nums.begin(), nums.end());
		vector<int> curr;
		vector<bool> visited(len, false);
		for (int i = 0; i < len; ++i) {
			if (i < len - 1 && nums[i] == nums[i + 1])
				continue;
			curr.push_back(nums[i]);
			visited[i] = true;
			permuteCore(nums, results, curr, visited);
			visited[i] = false;
			curr.pop_back();
		}
		return results;
	}
	void permuteCore(vector<int>& nums, vector<vector<int>>& results, vector<int>& curr, vector<bool>& visited) {
		int len = nums.size();
		if (curr.size() == len) {
			results.push_back(curr);
			return;
		}
		else {
			for (int i = 0; i < len; ++i) {
				if (!visited[i]) {
					if (i < len - 1 && nums[i] == nums[i + 1] && !visited[i + 1])
						continue;
					curr.push_back(nums[i]);
					visited[i] = true;
					permuteCore(nums, results, curr, visited);
					visited[i] = false;
					curr.pop_back();
				}
			}
		}
	}
};

int main() {
	Solution solution;

	vector<int> nums = { 1,2,2,3 };
	vector<vector<int>> results = solution.permute(nums);
	for (auto a : results) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}

	return 0;
}