#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

/**
* 2020-05-02
* Veronica
*/
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		int sum = 0, curr = 0;
		int start = 0;
		for (int i = 0; i < n; ++i) {
			gas[i] -= cost[i];
			sum += gas[i];
			curr += gas[i];
			if (curr < 0) {
				curr = 0;
				start = i + 1;
			}
		}
		if (sum < 0)
			return -1;
		else
			return start;
	}
};

int main() {
	Solution solution;

	vector<int> gas = { 1,2,3,4,5 };
	vector<int> cost = { 3,4,5,1,2 };
	cout << solution.canCompleteCircuit(gas, cost) << endl;

	return 0;
}