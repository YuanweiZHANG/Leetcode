## 64. [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)

> Medium

Given a *m* x *n* grid filled with non-negative numbers, find a path from top left to bottom right which *minimizes* the sum of all numbers along its path.

**Note:** You can only move either down or right at any point in time.

**Example:**

```
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
```



**Solutions:**

Define `pathSum[i]` as the minimum path sum when reach `grid[i][j]`.  We have `pathSum[i] = grid[i][j] + min(pathSum[i], pathSum[i-1])` if `i != 0 && j != 0`.

Here is my solution class:

```c++
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		if (m == 0)
			return 0;
		int n = grid[0].size();
		if (n == 0)
			return 0;
		vector<int> pathSum(m);
		for (int j = 0; j < n; ++j) {
			for (int i = 0; i < m; ++i) {
				if (j == 0 && i == 0) {
					pathSum[0] = grid[0][0];
				}
				else if (j == 0) {
					pathSum[i] = grid[i][j] + pathSum[i - 1];
				}
				else if (i == 0) {
					pathSum[i] = grid[i][j] + pathSum[i];
				}
				else {
					pathSum[i] = grid[i][j] + min(pathSum[i], pathSum[i - 1]);
				}
			}
		}
		return pathSum[m - 1];
	}
};
```

