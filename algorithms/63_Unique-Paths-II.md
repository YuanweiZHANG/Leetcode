## 63. [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/)

> Medium

A robot is located at the top-left corner of a *m* x *n* grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

![img](./imgs/63.png)

An obstacle and empty space is marked as `1` and `0` respectively in the grid.

**Note:** *m* and *n* will be at most 100.

**Example 1:**

```
Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
```



**Solutions:**

Similar as Problem No.62. When `obstacleGrid[i][j] == 1`, `paths[i] = 0`.

*Special Input:*

```
Input: [[0,1]]
Output: 0
```

```
Input: [[1],[0]]
Output: 0
```

```
Input: large scale which can overflow int
```

Here is my solution class:

```c++
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty())
			return 0;
		int m = obstacleGrid.size();
		if (m == 0)
			return 0;
		int n = obstacleGrid[0].size();
		vector<long long> paths(m);
		for (int i = 0; i < m; ++i) {
			if (obstacleGrid[i][0] == 1 || (i > 0 && paths[i - 1] == 0))
				paths[i] = 0;
			else
				paths[i] = 1;
		}
		for (int j = 1; j < n; ++j) {
			for (int i = 0; i < m; ++i) {
				if (obstacleGrid[i][j] == 1) {
					paths[i] = 0;
					continue;
				}
				if (i > 0)
					paths[i] += paths[i - 1];
			}
		}
		return paths[m - 1];
	}
};
```

