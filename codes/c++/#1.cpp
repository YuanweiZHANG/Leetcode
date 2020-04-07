#include <iostream>
#include <vector>
#include <algorithm>
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
		sort(arr.begin(), arr.end());
		for (int i = 0; i < len - 1; ++i) {
			int duplicates = 1;
			while (i < len - 2 && arr[i] == arr[i + 1]) {
				duplicates++;
				i++;
			}
			if (arr[i] + 1 == arr[i + 1])
				count += duplicates;
		}
		return count;
	}
};

int main() {
	Solution solution;

	vector<int> arr = { 1,1,2,2 };
	cout << solution.countElements(arr) << endl;

	return 0;
}