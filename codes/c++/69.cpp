#include <iostream>
using namespace std;

/**
* 2020-04-10
* Veronica
*/
class Solution {
public:
	int mySqrt(int x) {
		long long i = 1;
		while (i*i <= x) {
			i++;
		}

		return i - 1;
	}
};

int main() {
	Solution solution;

	int x = 2147395600;
	cout << solution.mySqrt(x) << endl;

	return 0;
}
