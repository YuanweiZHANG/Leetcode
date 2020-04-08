#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/**
* 2020-04-08
* Veronica
*/
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int width = matrix.size();
		for (int i = 0; i < width / 2; ++i) {
			for (int j = 0; j < width - 2 * i - 1; ++j) {
				int temp = matrix[i][i + j];
				matrix[i][i + j] = matrix[width - i - 1 - j][i];
				matrix[width - i - 1 - j][i] = matrix[width - i - 1][width - i - 1 - j];
				matrix[width - i - 1][width - i - 1 - j] = matrix[i + j][width - i - 1];
				matrix[i + j][width - i - 1] = temp;
			}
		}
	}
};

int main() {
	Solution solution;

	vector<vector<int>> matrix = { {5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16} };
	solution.rotate(matrix);
	for (auto a : matrix) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}

	return 0;
}