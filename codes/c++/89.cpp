#include <iostream>
#include <vector>
using namespace std;

/**
* 2020-04-13
* Veronica
*/
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> grayNumber(1, 0);
		for (int i = 1; i < (1 << n); ++i) {
			int x = i;
			int gray = 0, index = 0;
			while (x) {
				if (x % 4 == 1 || x % 4 == 2) {
					gray |= (1 << index);
				}
				x = x >> 1;
				index++;	
			}
			grayNumber.push_back(gray);
		}
		return grayNumber;
	}
};

int main() {
	Solution solution;

	int n = 4;
	vector<int> results = solution.grayCode(n);
	for (auto result : results)
		cout << result << " ";

	return 0;
}