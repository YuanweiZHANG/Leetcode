#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-05
* Veronica
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int days = prices.size(), profit = 0;
		for (int i = 1; i < days; ++i) {
			if (prices[i] > prices[i - 1])
				profit += prices[i] - prices[i - 1];
		}
		return profit;
	}
};

int main() {
	Solution solution;

	vector<int> prices = { 7,1,5,3,6,4 };
	cout << solution.maxProfit(prices) << endl;

	return 0;
}