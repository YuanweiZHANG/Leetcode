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
		heights.push_back(0);
		int len = heights.size();
		int largestArea = 0;
		stack<int> lefts;
		for (int i = 0; i < len; ++i) {
			while (!lefts.empty() && heights[lefts.top()] > heights[i]) {
				int h = heights[lefts.top()];
				lefts.pop();
				int left = lefts.empty() ? -1 : lefts.top();
				largestArea = max(largestArea, h * (i - left - 1));
			}
			lefts.push(i);
		}
		return largestArea;
	}
};

int main() {
	Solution solution;

	vector<int> heights = { 2,1,2 };
	cout << solution.largestRectangleArea(heights) << endl;

	return 0;
}