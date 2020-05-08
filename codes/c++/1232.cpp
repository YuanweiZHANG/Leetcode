#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-05-08
* Veronica
*/
class Solution {
public:
	bool checkStraightLine(vector<vector<int>>& coordinates) {
		double k = (double)(coordinates[1][1] - coordinates[0][1]) / (double)(coordinates[1][0] - coordinates[0][0]);
		int n = coordinates.size();
		for (int i = 1; i < n - 1; ++i) {
			double newK = (double)(coordinates[i + 1][1] - coordinates[i][1]) / (double)(coordinates[i + 1][0] - coordinates[i][0]);
			if (abs(newK - k) > 1e-5)
				return false;
		}
		return true;
	}
};

int main() {
	Solution solution;

	vector<vector<int>> coordinates = { {-4,-3},{1,0},{3,-1},{0,-1},{-5,2} };
	cout << solution.checkStraightLine(coordinates) << endl;

	return 0;
}