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
		stack<Status> stk;
		
		for (int i = 0; i < len; ++i) {
			if (i < len - 1 && nums[i] == nums[i + 1] && !visited[i + 1])
				continue;
			curr.push_back(nums[i]);
			visited[i] = true;
			stk.push(Status(curr, visited));
			visited[i] = false;
			curr.pop_back();
		}
		
		while (!stk.empty()) {
			Status p = stk.top();
			stk.pop();
			if (p.curr.size() == len) {
				results.push_back(p.curr);
			}
			else {
				for (int i = 0; i < len; ++i) {
					if (!p.visited[i]) {
						if (i < len - 1 && nums[i] == nums[i + 1] && !p.visited[i + 1])
							continue;
						p.curr.push_back(nums[i]);
						p.visited[i] = true;
						stk.push(Status(p.curr, p.visited));
						p.visited[i] = false;
						p.curr.pop_back();
					}
				}
			}
		}
		return results;
	}
	
	struct Status {
		vector<int> curr;
		vector<bool> visited;
		Status(vector<int>& curr_, vector<bool>& visited_) :
			curr(curr_), visited(visited_) {}
	};
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