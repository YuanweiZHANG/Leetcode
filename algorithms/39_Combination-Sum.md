## 39. [Combination Sum](https://leetcode.com/problems/combination-sum/)

> Medium

Given a **set** of candidate numbers (`candidates`) **(without duplicates)** and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sums to `target`.

The **same** repeated number may be chosen from `candidates` unlimited number of times.

**Note:**

- All numbers (including `target`) will be positive integers.
- The solution set must not contain duplicate combinations.

**Example 1:**

```
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
```

**Example 2:**

```
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
```



**Solutions:**

I use DFS to solve this problem.

Firstly, sort `candidates`, which is good for pruning. Then DFS. `index` means the index number of current top of the stack. If we do not set `i` to `index`, the answer will include many duplicate combinations. For example 1, the results will be `[2,2,3],[2,3,2],[3,2,2][7]` which is not what we need.

Here is my solution class:

```c++
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> results;
		vector<int> curr;
		sumDFS(results, candidates, target, curr, 0, 0);
		return results;
	}

	void sumDFS(vector<vector<int>>& results, vector<int>& candidates, const int& target, vector<int>& curr, int sum, int index) {
		int len = candidates.size();
		for (int i = index; i < len; ++i) {
			if (sum + candidates[i] == target) {
				curr.push_back(candidates[i]);
				results.push_back(curr);
				curr.pop_back();
				return;
			}
			else if (sum + candidates[i] < target) {
				curr.push_back(candidates[i]);
				sumDFS(results, candidates, target, curr, sum + candidates[i], i);
				curr.pop_back();
			}
			else {
				return;
			}
		}
		return;
	}
};
```

