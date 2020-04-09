## 52. [N-Queens II](https://leetcode.com/problems/n-queens-ii/)

> Hard

The *n*-queens puzzle is the problem of placing *n* queens on an *n*×*n* chessboard such that no two queens attack each other.

![img](./imgs/52.png)

Given an integer *n*, return the number of distinct solutions to the *n*-queens puzzle.

**Example:**

```
Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
```



**Solutions:**

It's the same as Problem No.51. DFS.

Here is my solution class:

```c++
class Solution {
public:
	int totalNQueens(int n) {
		int results_num = 0;
		vector<int> curr(n);
		vector<bool> col(n, true);
		vector<bool> cross_left_top(2 * n, true);
		vector<bool> cross_left_bottom(2 * n, true);
		for (int j = 0; j < n; ++j) {
			curr[0] = j;
			col[j] = false;
			cross_left_top[j + n - 1] = false;
			cross_left_bottom[j] = false;
			totalNQueensCore(results_num, curr, col, cross_left_top, cross_left_bottom, 1);
			cross_left_bottom[j] = true;
			cross_left_top[j + n - 1] = true;
			col[j] = true;
			curr[0] = 0;
		}
		return results_num;
	}
	void totalNQueensCore(int& results_num, vector<int>& curr,
		vector<bool>& col, vector<bool>& cross_left_top, vector<bool>& cross_left_bottom, int index) {
		int n = col.size();
		if (index == n) { // finish
			results_num++;
			return;
		}
		else {
			for (int j = 0; j < n; ++j) {
				if (col[j] && cross_left_top[j - index + n - 1]
					&& cross_left_bottom[j + index]) {
					curr[index] = j;
					col[j] = false;
					cross_left_top[j - index + n - 1] = false;
					cross_left_bottom[j + index] = false;
					totalNQueensCore(results_num, curr, col, cross_left_top, cross_left_bottom, index + 1);
					cross_left_bottom[j + index] = true;
					cross_left_top[j - index + n - 1] = true;
					col[j] = true;
					curr[index] = 0;
				}
			}
		}
	}
};
```

