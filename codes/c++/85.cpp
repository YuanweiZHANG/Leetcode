#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
* 2020-05-08
* Veronica
*/
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

int main() {
	Solution solution;

	vector<vector<char>> matrix = { { '0','0','0','1','0','1','1','1' },
									{ '0','1','1','0','0','1','0','1' },
									{ '1','0','1','1','1','1','0','1' },
									{ '0','0','0','1','0','0','0','0' },
									{ '0','0','1','0','0','0','1','0' },
									{ '1','1','1','0','0','1','1','1' },
									{ '1','0','0','1','1','0','0','1' },
									{ '0','1','0','0','1','1','0','0' },
									{ '1','0','0','1','0','0','0','0' } };
	cout << solution.maximalRectangle(matrix) << endl;

	return 0;
}
