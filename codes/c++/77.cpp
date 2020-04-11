#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-11
* Veronica
*/
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> results;
		vector<int> curr;
		combineCore(results, curr, n, k, 1);
		return results;
	}
	void combineCore(vector<vector<int>>& results, vector<int>& curr, int n, int k, int start) {
		if (k == 0) {
			results.push_back(curr);
		}
		else {
			for (int i = start; i <= n; ++i) {
				curr.push_back(i);
				combineCore(results, curr, n, k - 1, i + 1);
				curr.pop_back();
			}
		}
	}
};

int main() {
	Solution solution;

	int n = 4, k = 2;
	vector<vector<int>> results = solution.combine(n, k);
	for (auto a : results) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}

	return 0;
}
