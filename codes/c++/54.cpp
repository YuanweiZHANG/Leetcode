#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-09
* Veronica
*/

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> results;
		int row = matrix.size();
		if (row == 0)
			return results;
		int col = matrix[0].size();
		if (col == 0)
			return results;

		int layer = 0;
		while (layer * 2 < col && layer * 2 < row) {
			int endX = row - 1 - layer;
			int endY = col - 1 - layer;
			for (int j = layer; j <= endY; ++j) {
				results.push_back(matrix[layer][j]);
			}
			if (layer < endX) {
				for (int i = layer + 1; i <= endX; ++i) {
					results.push_back(matrix[i][col - 1 - layer]);
				}
			}
			if (layer < endX &&layer < endY) {
				for (int j = endY - 1; j >= layer; --j) {
					results.push_back(matrix[row - 1 - layer][j]);
				}
			}
			if (layer < endY&&layer < endX - 1) {
				for (int i = endX - 1; i >= layer + 1; --i) {
					results.push_back(matrix[i][layer]);
				}
			}
			layer++;
		}
		return results;
	}
};

int main() {
	Solution solution;

	//vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };
	vector<vector<int>> matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	//vector<vector<int>> matrix = { {1,2},{3,4},{5,6},{7,8} };
	vector<int> results = solution.spiralOrder(matrix);
	for (auto a : results) {
		cout << a << " ";
	}
	
	return 0;
}