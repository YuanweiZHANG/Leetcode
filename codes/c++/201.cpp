#include <iostream>
using namespace std;

/**
* 2020-04-23
* Veronica
*/
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		if (m < n)
			return rangeBitwiseAnd(m >> 1, n >> 1) << 1;
		else
			return m;
	}
};

int main() {
	Solution solution;

	int m = 5, n = 7;
	while (cin >> m >> n) {
		cout << solution.rangeBitwiseAnd(m, n) << endl;
	}
	return 0;
}