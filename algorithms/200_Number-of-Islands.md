## 200. [Number of Islands](https://leetcode.com/problems/number-of-islands/)

> Medium

Given a 2d grid map of `'1'`s (land) and `'0'`s (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

**Example 1:**

```
Input:
11110
11010
11000
00000

Output: 1
```

**Example 2:**

```
Input:
11000
11000
00100
00011

Output: 3
```



**Solutions:**



Here is my solution class:

```c++
class Solution {
public:
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty())
			return 0;
		int row = grid.size();
		int col = grid[0].size();
		vector<vector<bool>> visited(row, vector<bool>(col, false));
		queue<pair<int, int>> que;
		int result = 0;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (grid[i][j] == '1' && !visited[i][j]) {
					result++;
					que.push(make_pair(i, j));
					visited[i][j] = true;
					while (!que.empty()) {
						int x = que.front().first;
						int y = que.front().second;
						for (int k = 0; k < 4; ++k) {
							int xx = x + dx[k];
							int yy = y + dy[k];
							if(xx >= 0 && xx < row && yy >= 0 && yy < col && grid[xx][yy] == '1' && !visited[xx][yy]){
								visited[xx][yy] = true;
								que.push(make_pair(xx, yy));
							}
						}
						que.pop();
					}
				}
			}
		}
		return result;
	}
};
```

