## 120. [Triangle](https://leetcode.com/problems/triangle/)

> Medium

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

```
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
```

The minimum path sum from top to bottom is `11` (i.e., **2** + **3** + **5** + **1** = 11).

**Note:**

Bonus point if you are able to do this using only *O*(*n*) extra space, where *n* is the total number of rows in the triangle.



**Solutions:**

Dynamic Planning:

Define `minimum[col]` as minimum sum from bottom to layer `triangle[row][col]`. I decide to update `minimum[col]` from bottom to top, we need `minimum[col]` and `minimum[col + 1]`. It's okay since I decide traversal from left to right.

Here is my solution class:

```c++
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty() || triangle[0].empty())
			return 0;
		int n = triangle.size();
		vector<int> minimum(n, 0);
		for (int col = 0; col < n; ++col) {
			minimum[col] = triangle[n - 1][col];
		}
		for (int row = n - 2; row >= 0; --row) {
			for (int col = 0; col <= row; ++col) {
				minimum[col] = min(minimum[col], minimum[col + 1]) + triangle[row][col];
			}
		}
		return minimum[0];
	}
};
```

