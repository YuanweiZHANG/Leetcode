#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
* 2020-04-04
* Veronica
*/
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> results;
		vector<int> curr;
		sumDFS(results, candidates, target, curr, 0, 0);
		return results;
	}

	void sumDFS(vector<vector<int>>& results, vector<int>& candidates, const int& target, vector<int>& curr, int sum, int index) {
		int len = candidates.size();
		for (int i = index; i < len; ++i) {
			if (sum + candidates[i] == target) {
				curr.push_back(candidates[i]);
				results.push_back(curr);
				curr.pop_back();
				return;
			}
			else if (sum + candidates[i] < target) {
				curr.push_back(candidates[i]);
				sumDFS(results, candidates, target, curr, sum + candidates[i], i + 1);
				curr.pop_back();
				while (i < len - 1 && candidates[i] == candidates[i + 1])
					i++;
			}
			else {
				return;
			}
		}
		return;
	}
};

int main() {
	Solution solution;

	vector<int> candidates = { 2,5,2,1,2 };
	int target = 5;
	vector<vector<int>> results = solution.combinationSum2(candidates, target);
	for (auto a:results) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}

	return 0;
}