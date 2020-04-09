## 59. [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/)

> Medium

Given a positive integer *n*, generate a square matrix filled with elements from 1 to *n*2 in spiral order.

**Example:**

```
Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
```



**Solutions:**

Similar as Problem No.54.

Here is my solution class:

```c++
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> results(n, vector<int>(n,0));
		int start = 0;
		int num = 1;
		while (start * 2 < n) {
			int end = n - start - 1;
			for (int j = start; j <= end; ++j) {
				results[start][j] = num++;
			}
			if (start < end) {
				for (int i = start + 1; i <= end; ++i) {
					results[i][end] = num++;
				}
				for (int j = end - 1; j >= start; --j) {
					results[end][j] = num++;
				}
			}
			if (start < end - 1) {
				for (int i = end - 1; i >= start + 1; --i) {
					results[i][start] = num++;
				}
			}
			start++;
		}
		return results;
	}
};
```

