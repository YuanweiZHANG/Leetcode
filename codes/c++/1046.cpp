#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/**
* 2020-04-12
* Veronica
*/
class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		multiset<int, greater<int>> sets;
		sets.insert(stones.begin(), stones.end());
		while (sets.size() > 1) {
			int heaviest1 = *sets.begin();
			int heaviest2 = *(++sets.begin());
			if (heaviest1 > heaviest2) {
				sets.insert(heaviest1 - heaviest2);
			}
			sets.erase(sets.find(heaviest1));
			sets.erase(sets.find(heaviest2));
		}
		if (sets.empty())
			return 0;
		else
			return *sets.begin();
	}
};

int main() {
	Solution solution;

	vector<int> stones = { 2,7,4,1,8,1 };
	cout << solution.lastStoneWeight(stones) << endl;

	return 0;
}