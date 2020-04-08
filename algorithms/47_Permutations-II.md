## 47. [Permutations II](https://leetcode.com/problems/permutations-ii/)

> Medium

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

**Example:**

```
Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
```



**Solutions:**

Same as Problem No.46, since I've already handle duplicated situation. Cautious: sort `nums` first.

Here is my solution class:

```c++
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
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
```

