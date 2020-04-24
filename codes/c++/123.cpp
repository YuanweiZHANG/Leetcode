#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
* 2020-04-23
* Veronica
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int buyOne = INT_MAX, buyTwo = INT_MAX;
		int sellOne = 0, sellTwo = 0;
		int len = prices.size();
		for (int i = 0; i < len; ++i) {
			buyOne = min(buyOne, prices[i]);
			sellOne = max(sellOne, prices[i] - buyOne);
			buyTwo = min(buyTwo, prices[i] - sellOne);
			sellTwo = max(sellTwo, prices[i] - buyTwo);
		}
		return sellTwo;
	}
};

int main() {
	Solution solution;

	vector<int> prices = { 3,3,5,0,0,3,1,4 };
	cout << solution.maxProfit(prices) << endl;

	return 0;
}