## 54. [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)

> Medium

Given a matrix of *m* x *n* elements (*m* rows, *n* columns), return all elements of the matrix in spiral order.

**Example 1:**

```
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
```

**Example 2:**

```
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```



**Solutions:**

Different `matrix` has different `results`. There are at four kinds of situation to spiral a layer of matrix: 

- Only have to move from left to right. This always happens;
- Move from left to right, then move from top to bottom. This requires `layer < endX` which means matrix has at least "two" rows;
- Move from left to right, then top to bottom, then right to left. This requires `layer < endX && layer < endY` which means matrix has at least "two" rows and "two" columns;
- Move a complete four edges. This requires `layer < endX - 1 && layer < endY` which means matrix has at least "three" rows and "two" columns.

Here is my solution class:

```c++
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> results;
		int row = matrix.size();
		if (row == 0)
			return results;
		int col = matrix[0].size();
		if (col == 0)
			return results;

		int layer = 0;
		while (layer * 2 < col && layer * 2 < row) {
			int endX = row - 1 - layer;
			int endY = col - 1 - layer;
			for (int j = layer; j <= endY; ++j) {
				results.push_back(matrix[layer][j]);
			}
			if (layer < endX) {
				for (int i = layer + 1; i <= endX; ++i) {
					results.push_back(matrix[i][col - 1 - layer]);
				}
			}
			if (layer < endX && layer < endY) {
				for (int j = endY - 1; j >= layer; --j) {
					results.push_back(matrix[row - 1 - layer][j]);
				}
			}
			if (layer < endY && layer < endX - 1) {
				for (int i = endX - 1; i >= layer + 1; --i) {
					results.push_back(matrix[i][layer]);
				}
			}
			layer++;
		}
		return results;
	}
};
```

