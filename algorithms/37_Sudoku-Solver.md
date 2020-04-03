## 37. [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/)

> Hard

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy **all of the following rules**:

1. Each of the digits `1-9` must occur exactly once in each row.
2. Each of the digits `1-9` must occur exactly once in each column.
3. Each of the the digits `1-9` must occur exactly once in each of the 9 `3x3` sub-boxes of the grid.

Empty cells are indicated by the character `'.'`.

![img](./imgs/37.png)
A sudoku puzzle...

![img](./imgs/37-1.png)
...and its solution numbers marked in red.

**Note:**

- The given board contain only digits `1-9` and the character `'.'`.
- You may assume that the given Sudoku puzzle will have a single unique solution.
- The given board size is always `9x9`.




**Solutions:**

DFS. 

`valid[27][k]` shows whether `k+1` occurred before. `valid[i]` is row `i`, `valid[9 + j]` is column `j`, `valid[18+3*i+j]` is `(i,j)`$_{th}$ in the `3x3` sub-boxes. 

`loc` is the current filling digit's location. `loc = i*9+j`.

Here is my solution class:

```c++
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		bool valid[27][9] = { false };
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					valid[i][board[i][j] - '0' - 1] = true;
					valid[9 + j][board[i][j] - '0' - 1] = true;
					valid[18 + 3 * (i / 3) + j / 3][board[i][j] - '0' - 1] = true;
				}
			}
		}
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.') {
					for (int k = 0; k < 9; ++k) {
						if (!valid[i][k] && !valid[9 + j][k] && !valid[18 + 3 * (i / 3) + j / 3][k]) {
							valid[i][k] = true;
							valid[9 + j][k] = true;
							valid[18 + 3 * (i / 3) + j / 3][k] = true;
							board[i][j] = '0' + k + 1;
							if (fill(board, valid, i * 9 + j))
								return;
							board[i][j] = '.';
							valid[i][k] = false;
							valid[9 + j][k] = false;
							valid[18 + 3 * (i / 3) + j / 3][k] = false;
						}
					}
					return;
				}
			}
		}
	}
	bool fill(vector<vector<char>>& board, bool valid[27][9], int loc) {
		for (int loc_ = loc + 1; loc_ < 81; ++loc_) {
			int i = loc_ / 9;
			int j = loc_ % 9;
			if (board[i][j] == '.') {
				for (int k = 0; k < 9; ++k) {
					if (!valid[i][k] && !valid[9 + j][k] && !valid[18 + 3 * (i / 3) + j / 3][k]) {
						valid[i][k] = true;
						valid[9 + j][k] = true;
						valid[18 + 3 * (i / 3) + j / 3][k] = true;
						board[i][j] = '0' + k + 1;
						if (fill(board, valid, i * 9 + j))
							return true;
						board[i][j] = '.';
						valid[i][k] = false;
						valid[9 + j][k] = false;
						valid[18 + 3 * (i / 3) + j / 3][k] = false;
					}
				}
				return false;
			}
		}
		return true;
	}
};
```

