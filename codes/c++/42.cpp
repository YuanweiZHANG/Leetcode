#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-04
* Veronica
*/
class Solution {
public:
	int trap(vector<int>& height) {
		int len = height.size();
		if (len == 0)
			return 0;
		int i = 0;
		int water = 0;
		while (i < len - 1) {
			int j = i + 1;
			while (j < len && height[i] > height[j])
				j++;
			if (j != len) {
				water += height[i] * (j - i - 1);
				for (int k = i + 1; k < j; ++k)
					water -= height[k];
				i = j;
			}
			else // height[i] is the highest among height[i]...height[len-1]
				break;
		}
		i = len - 1;
		while (i > 1) {
			int j = i - 1;
			while (j >= 0 && height[i] >= height[j])
				j--;
			if (j != -1) {
				water += height[i] * (i - j - 1);
				for (int k = j + 1; k < i; ++k)
					water -= height[k];
				i = j;
			}
			else
				break;
		}
		return water;
	}
};

int main() {
	Solution solution;

	vector<int> height = { 4,2,3 };
	cout << solution.trap(height) << endl;

	return 0;
}