#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-09
* Veronica
*/
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> results(n, vector<int>(n,0));
		int start = 0;
		int num = 1;
		while (start * 2 < n) {
			int end = n - start - 1;
			for (int j = start; j <= end; ++j) {
				results[start][j] = num++;
			}
			if (start < end) {
				for (int i = start + 1; i <= end; ++i) {
					results[i][end] = num++;
				}
				for (int j = end - 1; j >= start; --j) {
					results[end][j] = num++;
				}
			}
			if (start < end - 1) {
				for (int i = end - 1; i >= start + 1; --i) {
					results[i][start] = num++;
				}
			}
			start++;
		}
		return results;
	}
};

int main() {
	Solution solution;

	int n = 3;
	vector<vector<int>> results = solution.generateMatrix(n);
	for (auto a : results) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}
	
	return 0;
}