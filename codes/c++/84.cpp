#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/**
* 2020-04-13
* Veronica
*/
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		return largetRectangleAreaCore(heights, 0, heights.size() - 1);
	}
	int largetRectangleAreaCore(vector<int>& heights, int left, int right) {
		if (left == right)
			return heights[left];
		else if (left > right) {
			return 0;
		}
		int lowest = left;
		for (int i = left + 1; i <= right; ++i) {
			if (heights[i] < heights[lowest]) {
				lowest = i;
			}
		}
		int area = heights[lowest] * (right - left + 1);
		return max(max(area, largetRectangleAreaCore(heights, left, lowest - 1)), largetRectangleAreaCore(heights, lowest + 1, right));
	}
};

int main() {
	Solution solution;

	vector<int> heights = { 2,1,2 };
	cout << solution.largestRectangleArea(heights) << endl;

	return 0;
}