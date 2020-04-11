#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-11
* Veronica
*/
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if (m == 0)
			return false;
		int n = matrix[0].size();
		if (n == 0)
			return false;
		int i = 0, j = n - 1;
		while (i < m && j >= 0) {
			if (matrix[i][j] < target)
				i++;
			else if (matrix[i][j] > target)
				j--;
			else
				return true;
		}
		return false;
	}
};

int main() {
	Solution solution;

	vector<vector<int>> matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,50} };
	int target = 8;
	cout << solution.searchMatrix(matrix, target) << endl;

	return 0;
}
