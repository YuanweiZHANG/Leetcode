#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-10
* Veronica
*/
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty())
			return 0;
		int m = obstacleGrid.size();
		if (m == 0)
			return 0;
		int n = obstacleGrid[0].size();
		vector<long long> paths(m);
		for (int i = 0; i < m; ++i) {
			if (obstacleGrid[i][0] == 1 || (i > 0 && paths[i - 1] == 0))
				paths[i] = 0;
			else
				paths[i] = 1;
		}
		for (int j = 1; j < n; ++j) {
			for (int i = 0; i < m; ++i) {
				if (obstacleGrid[i][j] == 1) {
					paths[i] = 0;
					continue;
				}
				if (i > 0)
					paths[i] += paths[i - 1];
			}
		}
		return paths[m - 1];
	}
};

int main() {
	Solution solution;

	vector<vector<int>> obstacleGrid = { {0,0,0},{0,1,0},{0,0,0} };
	cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;

	return 0;
}
