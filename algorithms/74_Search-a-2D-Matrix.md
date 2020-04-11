## 74. [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)

> Medium

Write an efficient algorithm that searches for a value in an *m* x *n* matrix. This matrix has the following properties:

- Integers in each row are sorted from left to right.
- The first integer of each row is greater than the last integer of the previous row.

**Example 1:**

```
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
```

**Example 2:**

```
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
```



**Solutions:**

Since the `matrix` has been sorted, we can make full use of it. From top-right, judge whether the core number `matrix[i][j] == target`. If so, we find the `target`.

If `matrix[i][j] > target`, and since all numbers smaller than `matrix[i][j]` are on the left, move the core number left, which is `matrix[i][j-1]`.

If `matrix[i][j] < target`, since every numbers in row `i` and on the left of `matrix[i][j]` are smaller than `matrix[i][j]` and we already judge numbers on the right side of `matrix[i][j]`, move the core number down, which is `matrix[i+1][j]`.

This method has $O(m+n)$ time complexity.

Here is my solution class:

```c++
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if (m == 0)
			return false;
		int n = matrix[0].size();
		if (n == 0)
			return false;
		int i = 0, j = n - 1;
		while (i < m && j >= 0) {
			if (matrix[i][j] < target)
				i++;
			else if (matrix[i][j] > target)
				j--;
			else
				return true;
		}
		return false;
	}
};
```

Also, we can find the correct row first. Then binary search `target` at that row. This could cost $O(n+logm)$.