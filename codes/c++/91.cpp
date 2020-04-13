#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
* 2020-04-13
* Veronica
*/
class Solution {
public:
	int numDecodings(string s) {
		if (s == "")
			return 0;
		vector<int> ways(s.size(), 0);
		if (s[0] >= '1' && s[0]<='9')
			ways[0] = 1;
		for (int i = 1; i < s.size(); ++i) {
			if (ways[i - 1] == 0) {
				ways[i] = 0;
				continue;
			}
			bool oneDigit = validOneDigit(s[i]);
			bool twoDigit = validTwoDigit(s[i - 1], s[i]);
			if (oneDigit) {
				ways[i] = ways[i - 1];
				if (twoDigit) {
					if (i == 1)
						ways[i] += 1;
					else
						ways[i] += ways[i - 2];
				}
			}
			else {
				if (twoDigit) {
					if (i == 1)
						ways[i] += 1;
					else
						ways[i] += ways[i - 2];
				}
			}
		}
		return ways[s.size() - 1];
	}

	bool validOneDigit(char a) {
		if (a >= '1'&& a <= '9')
			return true;
		else
			return false;
	}

	bool validTwoDigit(char a, char b) {
		if (a == '0' || a > '2')
			return false;
		if (a == '2'&& b > '6')
			return false;
		return true;
	}
};

int main() {
	Solution solution;

	string s = "101";
	cout << solution.numDecodings(s) << endl;

	return 0;
}