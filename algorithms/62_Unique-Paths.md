## 62. [Unique Paths](https://leetcode.com/problems/unique-paths/)

> Medium

A robot is located at the top-left corner of a *m* x *n* grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

![img](./imgs/62.png)
Above is a 7 x 3 grid. How many possible unique paths are there?

 

**Example 1:**

```
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
```

**Example 2:**

```
Input: m = 7, n = 3
Output: 28
```

 

**Constraints:**

- `1 <= m, n <= 100`
- It's guaranteed that the answer will be less than or equal to `2 * 10 ^ 9`.



**Solutions:**

There are at least two methods to solve this problem. First one is DFS or BFS. Count the times of reaching the 'Finish'. Second one is dynamic planning. I choose to implement dynamic planning method.

Define `paths[i][j]` as the paths number when reaching the [i, j] grid. The answer of this problem is `paths[m-1][n-1]`. And we have `paths[i][j] = paths[i-1][j] + paths[i][j-1]`. Also, `paths[i][0] = paths[0][j] = 1`. 

However, we only care about the last column of `paths`, so we can redefine `paths[i]` except `paths[i][j]`. Hence, my solution's space complexity is $O(m)$.  

Here is my solution class:

```c++
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<int> paths(m, 1);
		paths[0] = 1;
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < m; ++j) {
				paths[j] = paths[j] + paths[j - 1];
			}
		}
		return paths[m - 1];
	}
};
```

