#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

/**
* 2020-04-21
* Veronica
*/
class BinaryMatrix {
public:
	vector<vector<int>> mat;
	int m = 0, n = 0;
	BinaryMatrix(vector<vector<int>>& _mat) : mat(_mat) {
		m = mat.size();
		if (m > 0)
			n = mat[0].size();
	}
	int get(int x, int y) {
		if (0 <= x && x < m && 0 <= y && y < n)
			return mat[x][y];
		else
			assert("\'0 <= x && x < m && 0 <= y && y < n\' failed\n");
	}
	vector<int> dimensions() {
		return { m, n };
	}
};
/**
* // This is the BinaryMatrix's API interface.
* // You should not implement it, or speculate about its implementation
* class BinaryMatrix {
*   public:
*     int get(int x, int y);
*     vector<int> dimensions();
* };
*/

class Solution {
public:
	int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
		vector<int> dimensions = binaryMatrix.dimensions();
		int m = dimensions[0], n = dimensions[1];
		int j = n - 1, i = 0;
		int finalI = 0, finalJ = n - 1;
		while (j >= 0 && i < m) {
			if (binaryMatrix.get(i, j) == 1) {
				finalI = i;
				finalJ = j;
				j--;
			}
			else {
				i++;
			}
		}
		if (binaryMatrix.get(finalI, finalJ) == 0)
			return -1;
		else
			return finalJ;
	}
};

int main() {
	Solution solution;

	vector<vector<int>> mat = { {0,0,0,1}, {0,0,1,1},{0,1,1,1} };
	BinaryMatrix binaryMatrix(mat);

	cout << solution.leftMostColumnWithOne(binaryMatrix) << endl;

	return 0;
}