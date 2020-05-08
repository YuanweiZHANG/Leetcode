##85. [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/) 

> Hard

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

**Example:**

```
Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
```



**Solutions:**

Reading code can clear one's mind. :)

Here is my solution class:

```c++
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return 0;
		int result = 0;
		int row = matrix.size(), col = matrix[0].size();
		vector<vector<int>> left(row + 1, vector<int>(col + 1, 0));
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (matrix[i][j] == '1')
					left[i + 1][j + 1] = left[i + 1][j] + 1;
			}
		}
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				int width = left[i + 1][j + 1];
				for (int k = i; k < row; ++k) {
					width = min(width, left[k + 1][j + 1]);
					result = max(result, width * (k - i + 1));
				}
			}
		}
		return result;
	}
};
```

```c++
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> h(n, 0), left(n, 0), right(n, n);
        int area = 0;
        for (int i = 0; i < m; ++i) {
            int l = 0;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    ++h[j];
                    left[j] = max(left[j], l);
                } else {
                    h[j] = 0;
                    left[j] = 0;
                    l = j + 1;
                }
            }

            int r = n;
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], r);
                    area = max(area, (right[j] - left[j]) * h[j]);
                } else {
                    right[j] = n;
                    r = j;
                }
            }
        }
        return area;
    }
};
```

