#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
* 2020-04-14
* Veronica
*/
class Solution {
public:
	string stringShift(string s, vector<vector<int>>& shift) {
		int shifts = 0;
		for (auto a : shift) {
			if (a[0] == 0)
				shifts -= a[1];
			else
				shifts += a[1];
		}
		if (shifts == 0)
			return s;
		else if (shifts < 0) {
			shifts = -shifts;
			shifts %= s.size();
			return s.substr(shifts, s.size() - shifts) + s.substr(0, shifts);
		}
		else {
			shifts %= s.size();
			return s.substr(s.size() - shifts, shifts) + s.substr(0, s.size() - shifts);
		}
	}
};

int main() {
	Solution solution;

	string s = "wpdhhcj";
	vector<vector<int>> shift = { {0,7},{1,7},{1,0},{1,3},{0,3},{0,6},{1,2} };
	cout << solution.stringShift(s, shift) << endl;

	return 0;
}