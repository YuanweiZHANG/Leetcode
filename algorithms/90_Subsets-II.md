##90. [Subsets II](https://leetcode.com/problems/subsets-ii/) 

> Medium

Given a collection of integers that might contain duplicates, **nums**, return all possible subsets (the power set).

**Note:** The solution set must not contain duplicate subsets.

**Example:**

```
Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
```



**Solutions:**

Avoid pushing into same numbers in a layer of recursion. Therefore, I has `while` part.

Here is my solution class:

```c++
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
```

