##73. [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/) 

> Medium

Given a *m* x *n* matrix, if an element is 0, set its entire row and column to 0. Do it [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm).

**Example 1:**

```
Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
```

**Example 2:**

```
Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
```

**Follow up:**

- A straight forward solution using O(*m**n*) space is probably a bad idea.
- A simple improvement uses O(*m* + *n*) space, but still not the best solution.
- Could you devise a constant space solution?



**Solutions:**

Separate whole matrix into three parts: First row, first column and others. If first row has `0`, then mark `row0 = true`. If first column has `0`, `col0 = true`. If any `matrix[i][j] == 0` in the third part, then `matrix[i][0] = matrix[0][j] = 0`. In the end, what we need to do is filling `0` according to `row0`, `col0` `matrix[i][0]`, and `matrix[0][j]`.

Here is my solution class:

```c++
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0)
			return;
		int n = matrix[0].size();
		if (n == 0)
			return;
		bool row0 = false, col0 = false;
		for (int i = 0; i < m; ++i)
			if (matrix[i][0] == 0) {
				col0 = true;
				break;
			}
		for (int j = 0; j<n;++j)
			if (matrix[0][j] == 0) {
				row0 = true;
				break;
			}
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = matrix[0][j] = 0;
				}
			}
		}
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			}
		}
		if (row0)
			for (int j = 0; j < n; ++j)
				matrix[0][j] = 0;
		if (col0)
			for (int i = 0; i < m; ++i)
				matrix[i][0] = 0;
		return;
	}
};
```

