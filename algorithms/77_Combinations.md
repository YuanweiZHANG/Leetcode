##77. [Combinations](https://leetcode.com/problems/combinations/) 

> Medium

Given two integers *n* and *k*, return all possible combinations of *k* numbers out of 1 ... *n*.

**Example:**

```
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```



**Solutions:**

Use DFS. When `i` is already push into `curr`, `start = i + 1`. Because combinations don't have orders, we can assume each combination is ascending sequence.

Here is my solution class:

```c++
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> results;
		vector<int> curr;
		combineCore(results, curr, n, k, 1);
		return results;
	}
	void combineCore(vector<vector<int>>& results, vector<int>& curr, int n, int k, int start) {
		if (k == 0) {
			results.push_back(curr);
		}
		else {
			for (int i = start; i <= n; ++i) {
				curr.push_back(i);
				combineCore(results, curr, n, k - 1, i + 1);
				curr.pop_back();
			}
		}
	}
};
```

Additionally, we can also implement DFS using equation $C_n^k = C_{n-1}^{k-1} + C_{n-1}^k$. 