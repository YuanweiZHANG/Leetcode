## 221. [Maximal Square](https://leetcode.com/problems/maximal-square/)

> Medium

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

**Example:**

```
Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
```



**Solutions:**

Dynamic Planning:

Here is my solution class:

```c++
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return 0;
		int row = matrix.size(), col = matrix[0].size();
		vector<vector<int>> left(row, vector<int>(col, 0));
		vector<vector<int>> up(row, vector<int>(col, 0));
		vector<vector<int>> widths(row, vector<int>(col, 0));
		int maxSquare = 0;
		left[0][0] = up[0][0] = maxSquare = widths[0][0] = matrix[0][0] - '0';
		for (int i = 1; i < row; ++i) {
			if (matrix[i][0] == '0') {
				left[i][0] = up[i][0] = 0;
			}
			else {
				maxSquare = 1;
				widths[i][0] = 1;
				left[i][0] = 1;
				up[i][0] = up[i - 1][0] + 1;
			}
		}
		for (int j = 1; j < col; ++j) {
			if (matrix[0][j] == '0') {
				left[0][j] = up[0][j] = 0;
			}
			else {
				maxSquare = 1;
				widths[0][j] = 1;
				left[0][j] = left[0][j - 1] + 1;
				up[0][j] = 1;
			}
		}
		for (int i = 1; i < row; ++i) {
			for (int j = 1; j < col; ++j) {
				if (matrix[i][j] == '0') {
					left[i][j] = up[i][j] = 0;
				}
				else {
					left[i][j] = left[i][j - 1] + 1;
					up[i][j] = up[i - 1][j] + 1;
					int width = min(left[i][j], up[i][j]);
					int widthOld = widths[i - 1][j - 1];
					widths[i][j] = min(width, widthOld + 1);
					maxSquare = max(maxSquare, widths[i][j] * widths[i][j]);
				}
			}
		}
		return maxSquare;
	}
};
```

