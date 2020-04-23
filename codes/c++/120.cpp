#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
* 2020-04-22
* Veronica
*/
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty() || triangle[0].empty())
			return 0;
		int n = triangle.size();
		vector<int> minimum(n, 0);
		for (int col = 0; col < n; ++col) {
			minimum[col] = triangle[n - 1][col];
		}
		for (int row = n - 2; row >= 0; --row) {
			for (int col = 0; col <= row; ++col) {
				minimum[col] = min(minimum[col], minimum[col + 1]) + triangle[row][col];
			}
		}
		return minimum[0];
	}
};

int main() {
	Solution solution;

	vector<vector<int>> triangle = { {2},{3,4},{6,5,7},{4,1,8,3} };
	cout << solution.minimumTotal(triangle) << endl;

	return 0;
}