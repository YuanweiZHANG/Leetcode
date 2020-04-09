#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
* 2020-04-09
* Veronica
*/

class Solution {
public:
	int totalNQueens(int n) {
		int results_num = 0;
		vector<bool> col(n, true);
		vector<bool> cross_left_top(2 * n, true);
		vector<bool> cross_left_bottom(2 * n, true);
		for (int j = 0; j < n; ++j) {
			col[j] = false;
			cross_left_top[j + n - 1] = false;
			cross_left_bottom[j] = false;
			totalNQueensCore(results_num, col, cross_left_top, cross_left_bottom, 1);
			cross_left_bottom[j] = true;
			cross_left_top[j + n - 1] = true;
			col[j] = true;
		}
		return results_num;
	}
	void totalNQueensCore(int& results_num, vector<bool>& col,
		vector<bool>& cross_left_top, vector<bool>& cross_left_bottom, int index) {
		int n = col.size();
		if (index == n) { // finish
			results_num++;
			return;
		}
		else {
			for (int j = 0; j < n; ++j) {
				if (col[j] && cross_left_top[j - index + n - 1]
					&& cross_left_bottom[j + index]) {
					col[j] = false;
					cross_left_top[j - index + n - 1] = false;
					cross_left_bottom[j + index] = false;
					totalNQueensCore(results_num, col, cross_left_top, cross_left_bottom, index + 1);
					cross_left_bottom[j + index] = true;
					cross_left_top[j - index + n - 1] = true;
					col[j] = true;
				}
			}
		}
	}
};

int main() {
	Solution solution;

	int n = 4;
	cout << solution.totalNQueens(n) << endl;
	
	return 0;
}