#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
* 2020-04-07
* Veronica
*/
class Solution {
public:
	int countElements(vector<int>& arr) {
		int len = arr.size();
		if (len == 0)
			return 0;

		int count = 0;
		map<int, int> mp;
		for (auto num : arr)
			mp[num]++;

		for (auto num : mp)
			if (mp.find(num.first + 1) != mp.end())
				count += num.second;

		return count;
	}
};

int main() {
	Solution solution;

	vector<int> arr = { 1,1,2,2 };
	cout << solution.countElements(arr) << endl;

	return 0;
}