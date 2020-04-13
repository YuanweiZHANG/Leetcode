#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
* 2020-04-13
* Veronica
*/
class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1 == s2)
			return true;
		if (s1.size() != s2.size())
			return false;
		int len = s1.size();
		vector<int> count(128, 0);
		for (int i = 0; i < len; ++i) {
			count[s1[i]]++;
			count[s2[i]]--;
		}
		for (int i = 0; i < 128; ++i) {
			if (count[i] != 0)
				return false;
		}

		for (int i = 1; i < len; ++i) {
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, len - i), s2.substr(i, len - i)))
				return true;
			if (isScramble(s1.substr(0, i), s2.substr(len - i, i)) && isScramble(s1.substr(i, len - i), s2.substr(0, len - i)))
				return true;
		}
		return false;
	}
};

int main() {
	Solution solution;

	string s1 = "abc", s2 = "cab";
	cout << solution.isScramble(s1, s2) << endl;

	return 0;
}