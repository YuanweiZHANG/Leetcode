#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
* 2020-04-09
* Veronica
*/
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](vector<int>& x, vector<int>& y) {return x[0] < y[0]; });
		int len = intervals.size();
		vector<vector<int>> results;
		int start = 0, end = 0;
		for (int i = 0; i < len; ++i) {
			start = intervals[i][0];
			end = intervals[i][1];
			while (i < len - 1 && end >= intervals[i + 1][0]) {
				end = max(end, intervals[i + 1][1]);
				i++;
			}
			results.push_back({ start, end });
		}
		return results;
	}
};

int main() {
	Solution solution;

	//vector<vector<int>> intervals = { {1,3},{2,6},{8,10},{15,18} };
	//vector<vector<int>> intervals = { {1,4},{4,5} };
	//vector<vector<int>> intervals = { {1,4},{2,3} };
	vector<vector<int>> intervals = { {2,3},{4,5},{6,7},{8,9},{1,10} };
	vector<vector<int>> results = solution.merge(intervals);
	for (auto a : results) {
		for (auto b : a) {
			cout << b << ' ';
		}
		cout << endl;
	}
	
	return 0;
}