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
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> results;
		vector<int> curr(n);
		vector<bool> col(n, true);
		vector<bool> cross_left_top(2 * n, true);
		vector<bool> cross_left_bottom(2 * n, true);
		for (int j = 0; j < n; ++j) {
			curr[0] = j;
			col[j] = false;
			cross_left_top[j + n - 1] = false;
			cross_left_bottom[j] = false;
			solveNQueensCore(results, curr, col, cross_left_top, cross_left_bottom, 1);
			cross_left_bottom[j] = true;
			cross_left_top[j + n - 1] = true;
			col[j] = true;
			curr[0] = 0;
		}
		return results;
	}
	void solveNQueensCore(vector<vector<string>>& results, vector<int>& curr,
		vector<bool>& col, vector<bool>& cross_left_top, vector<bool>& cross_left_bottom, int index) {
		int n = col.size();
		if (index == n) { // finish
			vector<string> result;
			for (int i = 0; i < n; ++i) {
				string str(n, '.');
				str[curr[i]] = 'Q';
				result.push_back(str);
			}
			results.push_back(result);
			return;
		}
		else {
			for (int j = 0; j < n; ++j) {
				if (col[j] && cross_left_top[j - index + n - 1]
					&& cross_left_bottom[j + index]) {
					curr[index] = j;
					col[j] = false;
					cross_left_top[j - index + n - 1] = false;
					cross_left_bottom[j + index] = false;
					solveNQueensCore(results, curr, col, cross_left_top, cross_left_bottom, index + 1);
					cross_left_bottom[j + index] = true;
					cross_left_top[j - index + n - 1] = true;
					col[j] = true;
					curr[index] = 0;
				}
			}
		}
	}
};

int main() {
	Solution solution;

	int n = 2;
	vector<vector<string>> results = solution.solveNQueens(n);
	for (auto a : results) {
		for (auto b : a) {
			cout << b << endl;
		}
		cout << endl;
	}

	return 0;
}