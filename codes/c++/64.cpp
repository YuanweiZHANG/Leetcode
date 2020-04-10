#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
* 2020-04-10
* Veronica
*/
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		if (m == 0)
			return 0;
		int n = grid[0].size();
		if (n == 0)
			return 0;
		vector<int> pathSum(m);
		for (int j = 0; j < n; ++j) {
			for (int i = 0; i < m; ++i) {
				if (j == 0 && i == 0) {
					pathSum[0] = grid[0][0];
				}
				else if (j == 0) {
					pathSum[i] = grid[i][j] + pathSum[i - 1];
				}
				else if (i == 0) {
					pathSum[i] = grid[i][j] + pathSum[i];
				}
				else {
					pathSum[i] = grid[i][j] + min(pathSum[i], pathSum[i - 1]);
				}
			}
		}
		return pathSum[m - 1];
	}
};

int main() {
	Solution solution;

	vector<vector<int>> grid = { {1,3,1},{1,5,1},{4,2,1} };
	cout << solution.minPathSum(grid) << endl;

	return 0;
}
