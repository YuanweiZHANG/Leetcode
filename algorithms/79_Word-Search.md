##79. [Word Search](https://leetcode.com/problems/word-search/) 

> Medium

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

**Example:**

```
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
```

 

**Constraints:**

- `board` and `word` consists only of lowercase and uppercase English letters.
- `1 <= board.length <= 200`
- `1 <= board[i].length <= 200`
- `1 <= word.length <= 10^3`



**Solutions:**

DFS.

Here is my solution class:

```c++
class Solution {
public:
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty())
			return false;
		if (word == "")
			return false;
		int row = board.size(), col = board[0].size();
		vector<vector<bool>> visited(row, vector<bool>(col, false));
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (board[i][j] == word[0]) {
					visited[i][j] = true;
					if (existCore(board, word, 1, make_pair(i, j), visited))
						return true;
					visited[i][j] = false;
				}
			}
		}
		return false;
	}
	bool existCore(vector<vector<char>>& board, string word, int index, pair<int, int> point, vector<vector<bool>>& visited) {
		if (index == word.size())
			return true;
		for (int i = 0; i < 4; ++i) {
			int xx = point.first + dx[i];
			int yy = point.second + dy[i];
			if (xx >= 0 && xx < board.size() && yy >= 0 && yy < board[0].size()
				&& !visited[xx][yy]) {
				if (board[xx][yy] == word[index]) {
					visited[xx][yy] = true;
					if (existCore(board, word, index + 1, make_pair(xx, yy), visited))
						return true;
					visited[xx][yy] = false;
				}
			}
		}
		return false;
	}
};
```

