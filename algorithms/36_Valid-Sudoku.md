## 36. [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/)

> Medium

Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated **according to the following rules**:

1. Each row must contain the digits `1-9` without repetition.
2. Each column must contain the digits `1-9` without repetition.
3. Each of the 9 `3x3` sub-boxes of the grid must contain the digits `1-9` without repetition.

![img](./imgs/36.png)
A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character `'.'`.

**Example 1:**

```
Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
```

**Example 2:**

```
Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
```

**Note:**

- A Sudoku board (partially filled) could be valid but is not necessarily solvable.
- Only the filled cells need to be validated according to the mentioned rules.
- The given board contain only digits `1-9` and the character `'.'`.
- The given board size is always `9x9`.




**Solutions:**

Validate board step by step. `isValidNine` validate square in [`row`, `row`+`row_num`) and [`col`, `col`+`col_num`].

Here is my solution class:

```c++
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool result = true;
		for (int i = 0; i < 9; ++i) {
			result &= isValidNine(board, i, 0, 1, 9);
			if (!result)
				return false;
			result &= isValidNine(board, 0, i, 9, 1);
			if (!result)
				return false;
		}
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				result &= isValidNine(board, i * 3, j * 3, 3, 3);
				if (!result)
					return false;
			}
		}
		return true;
	}

	bool isValidNine(vector<vector<char>>& board, int row, int col, int row_num, int col_num) {
		bool num[10] = { false };
		for (int i = 0; i < row_num; ++i) {
			for (int j = 0; j < col_num; ++j) {
				char ch = board[i + row][j + col];
				if (ch == '.')
					continue;
				else {
					if (!num[ch - '0']) {
						num[ch - '0'] = true;
					}
					else
						return false;
				}
			}
		}
		return true;
	}
};
```

