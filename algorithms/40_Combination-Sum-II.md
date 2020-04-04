## 40. [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)

> Medium

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sums to `target`.

Each number in `candidates` may only be used **once** in the combination.

**Note:**

- All numbers (including `target`) will be positive integers.
- The solution set must not contain duplicate combinations.

**Example 1:**

```
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
```

**Example 2:**

```
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
```



**Solutions:**

It's similar to Problem 39, instead that this problem limit using each candidate once.

First, add 1 to `index` every time calling `sumDFS` to ensure not using candidates twice. Second, pass the same candidates after calling `sumDFS` to ensure there are no duplicate combinations in results.

Here is my solution class:

```c++
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
				sumDFS(results, candidates, target, curr, sum + candidates[i], i + 1);
				curr.pop_back();
				while (i < len - 1 && candidates[i] == candidates[i + 1])
					i++;
			}
			else {
				return;
			}
		}
		return;
	}
};
```

