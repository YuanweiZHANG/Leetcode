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
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int len = intervals.size();
		if (len == 0)
			return { newInterval };
		int index = binarySearch(intervals, newInterval[0]);
		vector<vector<int>> results;
		for (int i = 0; i < index; ++i) {
			results.push_back(intervals[i]);
		}
		if (index == -1) { // newInterval[0] is the smallest
			index = 0;
		}
		else {
			if (intervals[index][1] >= newInterval[0]) {
				newInterval[0] = min(intervals[index][0], newInterval[0]);
				newInterval[1] = max(intervals[index][1], newInterval[1]);
				index++;
			}
			else {
				results.push_back(intervals[index++]);
			}
		}
		while (index < len && newInterval[1] >= intervals[index][0]) {
			newInterval[1] = max(newInterval[1], intervals[index++][1]);
		}
		results.push_back(newInterval);
		for (int i = index; i < len; ++i) {
			results.push_back(intervals[i]);
		}
		return results;
	}
	int binarySearch(vector<vector<int>>& intervals, int key) {
		int left = 0, right = intervals.size() - 1;
		while (left <= right) {
			int mid = (left + right) >> 1;
			if (intervals[mid][0] == key)
				return mid;
			else if (intervals[mid][0] > key) {
				right = mid - 1;
			}
			else {
				if (mid == intervals.size() - 1)
					return mid;
				if (intervals[mid + 1][0] > key)
					return mid;
				else {
					left = mid + 1;
				}
			}
		}
		return -1;
	}
};

int main() {
	Solution solution;

	vector<vector<int>> intervals = { {1,2},{3,5},{6,7},{8,10},{12,16} };
	vector<int> newInterval = { 4,8 };
	vector<vector<int>> results = solution.insert(intervals, newInterval);
	for (auto a : results) {
		for (auto b : a) {
			cout << b << ' ';
		}
		cout << endl;
	}
	
	return 0;
}