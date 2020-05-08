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
		vector<vector<int>> left(row + 1, vector<int>(col + 1, 0)), up(row + 1, vector<int>(col + 1, 0));
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (matrix[i][j] == '0')
					continue;
				else {
					left[i + 1][j + 1] = left[i + 1][j] + 1;
					up[i + 1][j + 1] = up[i][j + 1] + 1;
					int l = left[i + 1][j + 1], u = up[i + 1][j + 1];
					int minEdge = min(l, u);
					for (int delta = 1; delta < minEdge; ++delta) {
						result = max(result, delta * l);
						if (i + 1 - delta == 0 || j + 1 - delta == 0)
							break;
						if (left[i + 1 - delta][j + 1 - delta] + delta < l) {
							l = left[i + 1 - delta][j + 1 - delta] + delta;
							result = max(result, delta * l);
							break;
						}
					}
					minEdge = min(l, u);
					for (int delta = 1; delta < minEdge; ++delta) {
						result
						if (i + 1 - delta == 0 || j + 1 - delta == 0)
							break;
						if (up[i + 1 - delta][j + 1 - delta] + delta < u) {
							u = up[i + 1 - delta][j + 1 - delta] + delta;
							break;
						}
					}
					result = max(result, l * u);
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