#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-10
* Veronica
*/
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<int> paths(m, 1);
		paths[0] = 1;
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < m; ++j) {
				paths[j] = paths[j] + paths[j - 1];
			}
		}
		return paths[m - 1];
	}
};

int main() {
	Solution solution;

	int m = 7, n = 3;
	cout << solution.uniquePaths(m, n) << endl;

	return 0;
}
