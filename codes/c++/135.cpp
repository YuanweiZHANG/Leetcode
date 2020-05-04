#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
* 2020-05-04
* Veronica
*/
class Solution {
public:
	int candy(vector<int>& ratings) {
		int n = ratings.size();
		if (n == 0)
			return 0;
		vector<int> candies(n, 1);
		int result = 0;
		candies[0] = 1;
		for (int i = 1; i < n; ++i) {
			if (ratings[i] > ratings[i - 1])
				candies[i] = candies[i - 1] + 1;
		}
		result += candies[n - 1];
		for (int i = n - 2; i >= 0; --i) {
			if (ratings[i] > ratings[i + 1])
				candies[i] = max(candies[i], candies[i + 1] + 1);
			result += candies[i];
		}
		return result;
	}
};

int main() {
	Solution solution;

	vector<int> ratings = { 1,3,5,2,4 };
	cout << solution.candy(ratings) << endl;

	return 0;
}