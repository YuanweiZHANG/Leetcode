#include <iostream>
using namespace std;

/**
* 2020-05-04
* Veronica
*/
class Solution {
public:
	int findComplement(int num) {
		unsigned int index = 31, complement = 0;
		while (((num >> index) & 1) == 0) {
			complement |= ((unsigned)1 << index);
			index--;
		}
		return num ^ (~complement);
	}
};

int main() {
	Solution solution;

	int num = 1;
	cout << solution.findComplement(num) << endl;

	return 0;
}